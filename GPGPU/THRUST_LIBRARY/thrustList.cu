#include <thrust/device_vector.h>
#include <thrust/copy.h>

#include <list>
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


int main() {

	//create STL list wuth 4 values
	std::list<int> stl_list;

	stl_list.push_back(10);
	stl_list.push_back(20);
	stl_list.push_back(30);
	stl_list.push_back(40);

	//initialize a device_vector with the list
	thrust::device_vector<int> D(stl_list.begin(), stl_list.end());
	
	//copy a device vector into an STL vector
	std::vector<int> stl_vector(D.size());
	thrust::copy(D.begin(), D.end(), stl_vector.begin());
	printDeviceVector(D, "D");	

return 0;
} 
