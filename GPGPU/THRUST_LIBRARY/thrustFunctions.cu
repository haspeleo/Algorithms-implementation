#include <thrust/host_vector.h>
#include <thrust/device_vector.h>

#include <thrust/copy.h>
#include <thrust/fill.h>
#include <thrust/sequence.h>

#include <iostream>

//printing device vector
void printDeviceVector(thrust::device_vector<int> v, std::string name) {
	for(int i = 0; i < v.size(); i++) {
        	 std::cout <<name<<"["<<i<<"] = "<<v[i]<< std::endl;
	}
	std::cout <<"  "<<std::endl;
}
//printing host vector	
void printHostVector(thrust::host_vector<int> v, std::string name) {
	for(int i = 0; i < v.size(); i++) {
        	 std::cout <<name<<"["<<i<<"] = "<<v[i]<< std::endl;
	}
	std::cout <<"  "<<std::endl;
}

int main(void) {

   	thrust::device_vector<int> D(10, 1);
	printDeviceVector(D, "D");

	thrust::fill(D.begin(), D.begin() + 7, 71);
	printDeviceVector(D, "D");

	//initialize host vector with first five elements of device vector
	thrust::host_vector<int> H(D.begin(), D.begin() + 5);
	printHostVector(H, "H");	

	// set the elements of H to 0, 1, 2, 3, ...
        thrust::sequence(H.begin(), H.end());
	printHostVector(H, "H");	

	thrust::copy(H.begin(), H.end(), D.begin());
	printDeviceVector(D, "D");

return 0;
}
