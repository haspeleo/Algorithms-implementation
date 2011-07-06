/*Sequential version of factorial*/
#include <stdio.h>
#include <stdlib.h>

#include <time.h>

unsigned long factorial(int n) {

        if (n < 0) exit(EXIT_FAILURE);
 
        unsigned long result = 1;
        int i;
        for (i = 1; i <= n; i++) {
                result *= i;
        }

return result;
}

int main(int argc, char *argv[]) {

        clock_t start, end;
        double elapsed;
        start = clock();
	if (argc != 2) {
	printf("Not enough arguments!, exit\n");
	exit(0);
	}

        int n = atoi(argv[1]);

        printf(">>Sequential factorial version, N = %d\n", n);
        printf("Factorial[%d] = %d \n", n, factorial(n));

        end = clock();
        elapsed =((double)end - start);
        printf("ELAPSED TIME = %.7f\n");

return EXIT_SUCCESS;
}

