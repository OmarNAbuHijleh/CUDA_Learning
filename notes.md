# NOTES

## Intro to GPUs
### Typical CUDA Program Structure:
1.) CPU allocates CPU memory
2.) CPU copies data to GPU
3.) CPU launches kernel on GPU (processing the data is done here)
4.) CPU copies data from GPU back to CPU to perform next operation with it

The kernel looks like a serial program - it doesn't state anything regarding parallelism. 

### Terms to Remember:
- kernels (GPU kernels - these are different from convolutional and linux kernels)
- threads, blocks, and grid (to be discussed)
- GEMM: GEneral Matrix Multiplication
- SGEMM: Single Precision (fp32) General Matrix Multiplication
- cpu/host/functions vs. gpu/device/kernels
  - CPU is referred to as host, and it executes functions
  - GPU is referred to as device, and it executes kernels

### First Kernels
- Wikipedia contains tables telling us about which generations have which components (ex. L2 Cache) for the various Nvidia Microarchitecture implementations and their specs
- If we clone the cuda samples repository, we can take a look at the deviceQuery after building it and we can see the specifics of the GPU we're using. This will inform us of what features are available on our GPU that are not available on others.
  - NOTE: In our case we're using CUDA capability 8.6

- Naming scheme is very important when writing our kernels. Our host (the CPU) is going to precede it's definitions as "h_" while our device (the GPU) is going to be "d_".
  - So variable A in the host would be "h_A" while on the device it would be "d_A"
  - `__global__` is visible globally, so the host or device can call these functions. They don't typically return anything but do really fast operations to a variable you pass in
  - `__device__` this is a small job only the GPU can call. 
  - `__host__`  is only going to run on the CPU. Same as running a regular c/c++ script on CPU without CUDA

- Memory allocation:
  - cudaMalloc on VRAM (also called global memory)
    - ex. `cudaMalloc(&d_a, N*N*sizeof(float));`
  - cudaMemcpy can copy from device to host, host to device, or device to device (edge cases)
    - cudaMemcpyHostToDevice, cudaMemcpyDeviceToHost, cudaMemcpyDeviceToDevice
  - cudaFree will free memory on the device

- nvcc compiler
  - host code is modified to run kernels and compiled to an x86 binary
- device code
  - compiled to PTX (parallel thread execution) stable across multiple GPU generations
- JIT (just in time)
  - PTX into native GPU instructions, allowing for forward compatibility

- CUDA hierarchy
  - Kernels execute in a thread (smallest component)
  - Threads are grouped into thread blocks (aka blocks)
  - blocks are grouped into a grid
  - Kernel executed as a grid of blocks of threads (largest component)

  - terms:
    - gridDim --> number of blocks in a grid
    - blockIdx --> index of the block in the grid
    - blockDim --> number of threads in a block
    - threadIdx --> index of the thread in a block

- Each thread has local memory (registers that are private to the thread)
  - A *WEFT* is the horizontal component of a block and a *WARP* is the vertical components of the blocks
  - Each WARP inside a block parallelizes 32 threads
  - Instructions are sent to warps to tell the threads what to do (i.e. the warps are orchestrating the threads)
  - Total number of warps in a block: ceil(T/W_size, 1)
    - T is the number of threads per block
    - W_size is the warp size, which equals 32
- Each block has shared memory amongst its threads!
