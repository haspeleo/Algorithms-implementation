#include <thrust/host_vector.h>
#include <thrust/device_vector.h>

#include <thrust/transform.h>
#include <algorithm>

#include <iostream>

#include "utils.h"
#include "timer.h"

struct saxpy_functor {
	const float a;
	saxpy_functor(float _a) : a(_a){}
	__host__ __device__
	float operator()(const float &x, const float &y) const {
		return a * x + y;
	}
};

void saxpy_fast(float A, thrust::device_vector<float>& X, thrust::device_vector<float>& Y) {
	// Y <- A * X + Y
	thrust::transform(X.begin(), X.end(), Y.begin(), Y.begin(), saxpy_functor(A));
}

void saxpy_slow(float A, thrust::device_vector<float>& X, thrust::device_vector<float>& Y) {
	thrust::device_vector<float> temp(X.size());
	// temp <- A
	thrust::fill(temp.begin(), temp.end(), A);
	// temp <- A * X
	thrust::transform(X.begin(), X.end(), temp.begin(), temp.end(), thrust::multiplies<float>());
	// temp <- A * X + Y
	thrust::transform(temp.begin(), temp.end(), Y.begin(), Y.end(), thrust::plus<float>());
}


int main () {

	float a = 71;
	thrust::device_vector<float> X(1000, 2);
	thrust::device_vector<float> Y(1000, 2);
	
	std::cout <<"using fast saxpy : 2N reads and N writes "<<std::endl;
	Timer timer;
	timer.begin();
	saxpy_fast(a, X, Y);
	double time  = timer.end();
	std::cout <<"Time used for fast saxpy: "<<time<<std::endl;
	//printDeviceVector(Y, "Y");
	//printDeviceVector(X, "X");
	
	std::cout <<"using slow saxpy : 4N reads and 3N writes "<<std::endl;
	timer.begin();
	saxpy_slow(a, X, Y);
	time = timer.end();
	std::cout <<"Time used for fast saxpy: "<<time<<std::endl;
	//printDeviceVector(Y, "Y");
	//printDeviceVector(X, "X");
	
return 0;
}
