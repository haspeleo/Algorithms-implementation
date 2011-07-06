#include <iostream>
#include <string>

#include <ext/hash_map>
#include <map>

using namespace std;
using namespace __gnu_cxx;


int main () {


map<string, int> stringCounts;
string str;

while (cin >> str) ++stringCounts[str];

map<string, int>::iterator iter;

for (iter = stringCounts.begin(); iter != stringCounts.end(); ++iter) {
	cout << "Word: " <<iter->first <<" , count = "<<iter->second<<endl;
}


return 0;
}
