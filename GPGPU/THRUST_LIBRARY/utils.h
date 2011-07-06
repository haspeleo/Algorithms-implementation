/* utils.h is a bunch of helper functions for printing informations 
 * when using thrust librarry
 */

#include <thrust/host_vector.h>
#include <thrust/device_vector.h>

#include <iostream>

//printing device vector
void printDeviceVector(thrust::device_vector<int> v, std::string name) {
	std::cout<<name<<"["<<" ";
	for(int i = 0; i < v.size(); i++) {
        	 std::cout <<v[i]<< " ";
	}
	std::cout<<"]"<<std::endl;
}
//printing host vector	
void printHostVector(thrust::host_vector<int> v, std::string name) {
	std::cout<<name<<"["<<" ";
	for(int i = 0; i < v.size(); i++) {
        	 std::cout <<v[i]<< " ";
	}
	std::cout<<"]"<<std::endl;
}
