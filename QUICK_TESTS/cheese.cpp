#include <iostream> 

using namespace std;

int main(int argc, char* argv[]) { 

	string temp, out = "";

   cout << "argc = " << argc << endl; 
   for(int i = 1; i < argc; i++)  {
      cout << "argv[" << i << "] = " << argv[i] << endl; 
	temp = argv[i];
	out += temp[0];

	cout <<out<<endl;

	}

   return 0; 
}








//#include <iostream>
//#include <cstdlib>
//
//using namespace std;
//
//int main(int argc, char **argv) {
//
//string out = atoi(argv[1]);
//
//cout <<out<<endl;
//
//
//return 0;
//}
