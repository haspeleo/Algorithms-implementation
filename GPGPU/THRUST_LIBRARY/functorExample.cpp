#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int op_negate(int i) {return -1 * i;}

int main() {
vector<int> first;
vector<int> second;

vector<int>::iterator ii;

//set some values for first
for (int i = 0; i < 5; i++) {
	first.push_back(i * 2);
}

second.resize(first.size());

transform(first.begin(), first.end(), second.begin(), op_negate);

for (int i = 0; i < first.size(); i++) {
	cout <<"First["<<i<<"] = "<<first[i]<<endl;
}

for (int i = 0; i < second.size(); i++) {
	cout <<"Second["<<i<<"] = "<<second[i]<<endl;
}



return 0;
}
