
/*
 * http://www.site.uottawa.ca/~lucia/courses/2131-05/labs/Lab3/CommandLineArguments.html -- command line arguments
 * http://www.cplusplus.com/forum/articles/13355/ -- parsing command line parameters
 * http://www.gnu.org/s/libc/manual/html_node/Getopt.html  --gnu 
 */


#include <iostream>
#include <cstdlib>

using namespace std;

//int main(int argc, char** argv) {   /* equivalent form of main */

int main(int argc, char* argv[]) {


    cout << "argc = " << argc << endl; 

   for(int i = 0; i < argc; i++) {
   cout << "argv[" << i << "] = " << argv[i] << endl;
}

int x = atoi(argv[1]);
int y = atoi(argv[2]);

cout <<x<<y<<endl;


return 0;
}
