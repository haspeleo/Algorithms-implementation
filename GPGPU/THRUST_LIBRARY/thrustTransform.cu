#include <thrust/host_vector.h>
#include <thrust/device_vector.h>

#include <thrust/transform.h>

#include <thrust/sequence.h>
#include <thrust/copy.h>
#include <thrust/fill.h>
#include <thrust/replace.h>

#include <thrust/functional.h> //for using functors

#include "utils.h"
#include <algorithm>

//int op_negate(int i) {return -1 * i;}
//int op_modulos(int a, int b ) {return a % b;}

int main () {

    // allocate three device_vectors with 10 elements
    	thrust::device_vector<int> X(10);
	thrust::device_vector<int> Y(10);
	thrust::device_vector<int> Z(10);

	printDeviceVector(X, "X");
	
    // initialize X to 0,1,2,3, ....
	thrust::sequence (X.begin(), X.end());
	printDeviceVector(X, "X");
    // compute Y = -X
	//for(int i = 0 ; i < X.size(); i++) {
	//	Y[i] = -1 * X[i];
	//}
	 printDeviceVector(X, "X");
	 printDeviceVector(Y, "Y");
	thrust::transform(X.begin(), X.end(), Y.begin(), thrust::negate<int>());
	std::cout <<">>>> after transform : transform(X.begin(), X.end(), Y.begin(), thrust::negate<int>()) "<<std::endl;	
	printDeviceVector(X, "X");
	printDeviceVector(Y, "Y");
    // fill Z with twos
	thrust::fill(Z.begin(), Z.end(), 2);
	
	printDeviceVector(Z, "Z");
    // compute Y = X mod 2
	thrust::transform(X.begin(), X.end(), Z.begin(), Y.begin(), thrust::modulus<int>());

    // replace all the ones in Y with tens
 	thrust::replace(Y.begin(), Y.end(), 1, 10);
    // print Y
	thrust::copy(Y.begin(), Y.end(), std::ostream_iterator<int>(std::cout, "\n"));
return 0;
}
