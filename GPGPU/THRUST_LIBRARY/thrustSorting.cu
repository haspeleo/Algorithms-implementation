#include <thrust/sort.h>


#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {

	/* initialize random seed: */
	  srand ( time(NULL) );

	const int N = 100;
	int A[N];

	for (int i = 0 ; i < N; i++) {
	  /* generate secret number: */
		A[i] = rand() % 10 + 1;
	}

	thrust::sort(A, A+N);
	for (int i = 0; i < N; i++) {
		std::cout <<"A["<<i<<"] = "<<A[i]<<std::endl;
	}

return EXIT_SUCCESS;
}
