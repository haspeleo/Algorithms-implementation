#include <iostream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;



double gaussian() {
    double res = 0;
    for (int k=0 ; k<12 ; k++) {
        res += drand48();
        //res += xor128()/4294967295.;
    }
    res -= 6;
    return res;

}

int main (int argc, char* argv []) {

	int Nmax = atoi(argv[1]);

	for ( int i = 0; i < Nmax; i++) {

		cout <<i<<"	"<<gaussian()<<endl;
	}

return 0;
}
