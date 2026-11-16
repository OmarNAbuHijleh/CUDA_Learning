# include <stdio.h>

/*
 * Memory management methods:
 * cudaMalloc
 *  - allocates memory on the GPU
 * cudaMemcpy
 *  - It can copy from device to host, from host to device, or device to device
 * cudaFree
 *  - Frees the memory on the device
 * cudaDeviceSynchronize
 *  - By default, the CPU and the GPU work together, but sometimes we need to make the CPU wait until all of the GPU operations are completed. That's what this function does
 *  - Useful when you need results before continuing. We can use it while performing benchmarks
 *
 * Memory in CUDA:
 *  - Global Memory
 *      - The main memory of the GPU, accessible by all threads
 *      - slowest, but largest in size
 *      - Use for data shared across all threads
 *  - Shared Memory:
 *      - Memory shared by all threads in a block
 *      - Very fast but small in size
 *      - use for data that threads in a block need to share frequently, like temporary variables or lookup tables
 *  - Registers:
 *      - Fastest memory, private to each thread
 *      - Used for local variables
 *      - Limited in number
 *      - Use cases are things like loop counters or intermediate calculations
 *  - Constant Memory:
 *      - Read-only memory for all threads
 *      - Cached for fast access
 *      - Used for data that doesn't change during kernel execution
 *      - Example: Constants or configuration parameters
 *  - Local Memory:
 *      - Used when registers are not enough
 *      - slow (stored in global memory)
 *      - avoid if possible
 *      - Large arrays or variables that don't fit in registers
 */
__global__ void whoami(void) {
    // Figure out which block we're looking at! Remember that these are 0-indexed
    int block_id =
        blockIdx.x +
        blockIdx.y * gridDim.x +
        blockIdx.z * gridDim.x * gridDim.y;


    int block_offset =
        block_id *
        blockDim.x * blockDim.y * blockDim.z;

    // Same as for blocks, but on the thread level. Remember that a grid contains blocks, which contain threads!
    int thread_offset =
        threadIdx.x +
        threadIdx.y * blockDim.x +
        threadIdx.z * blockDim.x * blockDim.y;

    int id = block_offset + thread_offset; // The thread in the grid

    printf("%04d | Block{%d %d %d} = %3d | Thread{%d %d %d} = %3d\n",
        id,
        blockIdx.x, blockIdx.y, blockIdx.z, block_id,
        threadIdx.x, threadIdx.y, threadIdx.z, thread_offset
    );
}


int main(int argc, char **argv) {
    const int b_x = 2, b_y = 3, b_z = 4; // Define our block's length, width, and depth
    const int t_x = 4, t_y = 4, t_z = 4; // Define our thread dimensionality for each block (length, width, and depth). max warp size is 32, so we'll get 2 warp of 32 threads per block (4*4*4 gives us 64, which breaks down to 2 warps of 32 threads)

    int blocks_per_grid = b_x * b_y * b_z;
    int threads_per_block = t_x * t_y * t_z;
    printf("%d blocks/grid\n", blocks_per_grid);
    printf("%d threads/block\n", threads_per_block);
    printf("%d total threads\n", blocks_per_grid * threads_per_block);

    // dim3 is a type specific to CUDA. It's a simple way to specify 3 dimensions and is used for grid and block sizes
    dim3 blocksPerGrid(b_x, b_y, b_z); // 3d cube of shape 2*3*4 = 24
    dim3 threadsPerBlock(t_x, t_y, t_z); // 3d cube of shape 4*4*4 = 64

    // pass these results into our kernel "whoami" where grid dimensions are the first parameter and threadsPerBlock as the second. We can pass in other things as well.
    // The <<<>>> is used to configure and launch kernels on the GPU. Defines the grid and block dimensions, shared memory size, and stream for kernel execution.
    // Note that we're passing in the gridsize and the block size. The actual arguments passed to the kernel would be in the "()"
    whoami<<<blocksPerGrid, threadsPerBlock>>>();
    cudaDeviceSynchronize();
}
