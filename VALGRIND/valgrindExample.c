/*
 * Simple example of using debugging and profiling tool valgrind
 *
 * 1] compile the example with:  
 * gcc -g -O0 valgrindExample.c -o valgrindExample
 * prefer using -O0, -O3 is not recommended as MemCheck ocasionally will report uninialized-value errors
 * which don't really exist
 *
 * 2] Memory error check: 
 * valgrind --leak-check=yes ./valgrindExample
 * see further informations at http://valgrind.org/gallery/linux_mag.html -- and the related book
 */


#include<stdlib.h>

void f(void) {

	int * T = malloc(10 * sizeof(int));
	T[10] = 0; // problem 1: heap block overrun

}// problem 2: exit without freeing T

int main() {

   f();

return 0;
}
