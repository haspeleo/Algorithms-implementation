/* compile :  nvcc -o vectorSum gpuVectorSum.cu  */

#include <stdio.h>

#define N 10000

/******************************************************************/
//kernel that execute on the CUDA device "Tesla" for example 
/******************************************************************/
__global__ void add (int *a, int *b, int *c) {

        int tid = blockIdx.x;    // handle the data at this index
        if (tid < N)
            c[tid] = a[tid] + b[tid];

} 
/******************************************************************/
//main  function that executes the host : the CPU 
/******************************************************************/

int main () {
	
	clock_t start, end;
	double elapsed;
	start = clock();

        int a[N], b[N], c[N];
        int *a_d, *b_d, *c_d;

        //Allocate the arrays on the device
        cudaMalloc((void**)&a_d, N * sizeof(int));
        cudaMalloc((void**)&b_d, N * sizeof(int));
        cudaMalloc((void**)&c_d, N * sizeof(int));


        //init A, B arrays
        for (int i = 0; i < N; i++) {
                a[i] = -i;
                b[i] = i * i;
        }

        //copy Array A and B to device 
          cudaMemcpy(a_d, a, N * sizeof(int), cudaMemcpyHostToDevice);//copy array elements from CPU to GPU
          cudaMemcpy(b_d, b, N * sizeof(int), cudaMemcpyHostToDevice);//copy array elements from CPU to GPU

        //Call kernel function to be executed on GPU
        //add<<<n_blocks, block_size>>>(a_d, b_d, c_d);
        add<<<N, 64>>>(a_d, b_d, c_d);

         //Bring back results to host array 
 	cudaMemcpy(c, c_d, N * sizeof(int), cudaMemcpyDeviceToHost);
	
 	//Print the result array 
	for (int i=0; i<N; i++) {
	    printf( "%d + %d = %d\n", a[i], b[i], c[i] );
	}	
	
	end = clock();
	elapsed = ((double)end - start) / CLOCKS_PER_SEC;
	
	printf("ELAPSED TIME = %.4f\n", elapsed);

	//free the device array	
	cudaFree(a_d);
	cudaFree(b_d);
	cudaFree(c_d);

return 0;
}

