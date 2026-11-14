# include <stdio.h>

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

    // dim3 is a type specific to CUDA.
    dim3 blocksPerGrid(b_x, b_y, b_z); // 3d cube of shape 2*3*4 = 24
    dim3 threadsPerBlock(t_x, t_y, t_z); // 3d cube of shape 4*4*4 = 64

    // pass these results into our kernel "whoami" where grid dimensions are the first parameter and threadsPerBlock as the second. We can pass in other things as well.
    whoami<<<blocksPerGrid, threadsPerBlock>>>();
    cudaDeviceSynchronize();
}
