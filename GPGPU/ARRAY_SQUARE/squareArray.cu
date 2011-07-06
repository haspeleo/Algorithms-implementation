// * http://llpanorama.wordpress.com/2008/05/21/my-first-cuda-program/
/*square array on GPU Written by me */

#include<stdio.h>
#include<cuda.h>

#include<time.h>

/******************************************************************/
//kernel that execute on the CUDA device "Tesla" for example 
/******************************************************************/

__global__ void square_array(float *a, int N) {
	int idx = blockIdx.x * blockDim.x + threadIdx.x;
        if (idx<N) a[idx]= a[idx] * a[idx];
        }

/******************************************************************/
//main  function that executes the host : the CPU 
/******************************************************************/

int main(void) {

	//for time mesurement 
	clock_t start, end;
	double elapsed;
	start = clock();

  float *a_h; //I point  the host array 
  float *a_d; //I point  the device array

  const int N=10000; //Number of the elements in the array 
  size_t size = N * sizeof (float);

  a_h = (float *)malloc(size); //I allocate the array on the host(allocation on CPU) 
  cudaMalloc((void **)&a_d, size);//I allocate the array on the device (allocation on GPU)

  for (int i=0;i<N;i++)
  a_h[i] = (float)i;//loop for initializing the array on the CPU

  cudaMemcpy(a_d, a_h, size, cudaMemcpyHostToDevice);//copy array elements from CPU to GPU

 //do Calulation on GPU
 int block_size = 4;
 int n_blocks = N/block_size + (N%block_size == 0 ? 0:1);

//Call to kernel function
 square_array <<< n_blocks, block_size >>> (a_d, N);

 //Bring back results to host array 
 cudaMemcpy(a_h, a_d, size, cudaMemcpyDeviceToHost);

 //Print the result array 
 for (int i=0;i< N;i++)
 printf("%d %f\n ", i, a_h[i] );

//Free host and device arrays
 free(a_h);
 cudaFree(a_d);

//get time
end = clock();
elapsed = ((double) end - start) / CLOCKS_PER_SEC;
printf("%.2f secondes entre start et end. \n", elapsed);

}	

