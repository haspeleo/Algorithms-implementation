/*Recursive version of factorial*/

#include <stdio.h>
#include <stdlib.h> 

int factorial (int n) {
       if (n < 0) exit(EXIT_FAILURE);

       if (n == 1) 

              return 1;
	else 
              return n * factorial(n - 1);
       }

int main(int argc, char *argv[]) {

	if (argc != 2) {
	printf("No arguments, exit!");
	exit(0);
	}

      int n = atoi(argv[1]);

      printf("Factorial[%d] = %d\n", n, factorial(n));

  return 0;
}

