// testaSEE.cpp : SSE instructions Test
//
#include <iostream>

//#include "detectSSE.h"
#include "timer.h"
#include <xmmintrin.h>

void saxpy(int n, float alpha, float *x, float *y) {
	int i;
	//#pragma omp parallel for
	for (i=0; i<n; i++)
		y[i] += alpha * x[i];
}

void saxpySSE(int n, float alpha, float *x, float *y) {
	/* A FAIRE */
	int i;
	#pragma omp parallel for
	for (i=0; i<n; i++) {
		y[i] += alpha * x[i];
	}

	//__m128 x_i, y_i, alpha4;
	//int i;
	//alpha4 = _mm_set1_ps(5.01f);

	//for (i = 0; i < n; i+=4) {
	//	y_i = _mm_load_ps(y+i);
	//	x_i = _mm_load_ps(x+i);

	//	y_i += alpha4 * x_i;

	//	y_i = _m_store_ps(y+i, y_i);
	//}
}

void saxspySSE_OMP(int n, float alpha, float *x, float *y) {
	__m128 x_i, y_i, alpha4;	
	
	alpha4 = _mm_load_ps(alpha);
	#pragma omp parallel for 
	for (int i = 0; i < n; i++) {
		x_i = -mm_load_ps(x+i);
		y_i = -mm_load_ps(y+i);
		
		y_i += alpha4 * x_i;
		
		y_i = _mm_store_ps(y+i, y_i);
	}

}

int main(int argc, char * argv[]) {
//	std::cout << "cpuid is = " << IsCPUID() << std::endl;
//	std::cout << "SSE is = " << IsSSE() << std::endl;
	const unsigned int sizeX = 1000000;
	const unsigned int numberIteractions =1000;
	float *x = (float*) malloc(sizeof(float)* sizeX);
	float *y = (float*) malloc(sizeof(float)* sizeX);

	for(int i=0; i< sizeX ; i++)
	{
		x[i]=1.0f;
		y[i]=0.5f;
	}
	Timer timer;

	timer.begin();
	for(int j=0; j< numberIteractions;j++)
		saxpy(sizeX, 0.001f, x, y);

	double time=timer.end();

	std::cout << " classic saxpy with n= " << sizeX << " computation time= " << time << std::endl;

	//if(IsSSE())
	{
		for(int i = 0; i< sizeX ; i++)
		{
			x[i]=1.0f;
			y[i]=0.5f;
		}
		timer.begin();
		for(int j = 0; j< numberIteractions;j++)
			saxpySSE(sizeX, 0.001f, x, y);

		double timeSSE = timer.end();
		std::cout << " SSE saxpy with n= " << sizeX << " computation time= " << timeSSE << std::endl;
		std::cout << " SSE speed up= " << time/timeSSE << std::endl;

	}
	return EXIT_SUCCESS;
}

