/*
* http://code.google.com/p/stanford-cs193g-sp2010/wiki/GettingStartedWithCUDA
*
*/
#include <thrust/host_vector.h>
#include <thrust/device_vector.h>

#include <cstdlib>
#include <iostream>

#include "utils.h"
#include "timer.h"

float cpuReduction(thrust::host_vector<float> v) {
	float sum = 0;
	for(int i = 0; i < v.size(); i++) {
		sum += v[i];
	}
	return sum;
}


//float recursiveCpuReduction(thrust::host_vector<float> v, int begin, int end) {
//	if(begin == end) return (v[begin]); 
//	if(end - begin < 2)
//		return (v[begin] + v[end]);
//	else if (end > begin) {
//		int middle = ( begin + end ) / 2;
//		recursiveCpuReduction(v, begin, middle);
//		recursiveCpuReduction(v, middle + 1, end);
//	}
//
//}

//#define PRINTING

int main(void) {
	
	int SIZE = 1000;
	Timer timer;

	thrust::host_vector<float> H(SIZE);
	for(int i = 0; i < H.size(); i++) {
		H[i] = i;
	}	

	timer.begin();
	float cpu_sum = cpuReduction(H);
	float time = timer.end();
	//std::cout <<">>> Reduction sum on CPU : "<<cpu_sum<<" using: "<<time<<" seconds..."<<std::endl;
	printf("ELAPSED TIME for reduction on cpu = %.6f\n seconds...", time);

	//float rcpu_sum = recursiveCpuReduction(H, 0, H.size());
	//std::cout <<">>> Recursive Reduction sum on CPU : "<<rcpu_sum<<std::endl;

	#ifdef PRINTING
	printHostVector(H, "H");
	#endif

   	thrust::device_vector<float> D = H; 

	#ifdef PRINTING
	printDeviceVector(D, "D");
	#endif
	timer.begin();
	float sum = thrust::reduce(D.begin(), D.end(), (float) 0, thrust::plus<float>());
	time = timer.end();
	//std::cout <<">>> Reduction sum on GPU: "<<sum<<" using : "<<time<<" seconds..."<<std::endl;
	printf("ELAPSED TIME for reduction on gpu = %.6f\n seconds...", time);

return EXIT_SUCCESS;
}
