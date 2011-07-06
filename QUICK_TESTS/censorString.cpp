/*
 * http://technical-interview.com/C_Questions_1.aspx
 */

#include <iostream>
#include <string>

using namespace std;

string censorString0(string text, string remove) {

	string result = "";
	for(int i = 0; i < text.length(); i++) {
		bool found = false;
		for(int j = 0; j < remove.length(); j++) {
			if(text[i] == remove[j]) {
				found = true;
				break;
			}
		}
	if(!found) {
		result += text[i];
	}


} 	

return result;
}

void censorString1(string &text, string remove) {
	for(int i = 0; i < remove.length(); i++) {
		int pos = 0;

		while((pos = text.find(remove[i]), pos) != string::npos) { //string::npos indicates the end of the string.
			text.replace(pos, 1, "");
		}	
	}
}

int main() {

	string  text = "stanford";
	string remove = "nt";
	
	string output = censorString0(text, remove);
	censorString1(text, remove);
	
	
	cout <<"After censoring : "<<output<<endl;

	cout <<"After censoring : "<<text<<endl;

	string str="We think in generalities, but we live in details.";
	string str1 = str.substr(12, 12);

	cout <<"using string::substr : "<<str1<<endl;
	string str2 = "live";

	int pos = str.find(str2);
	cout <<"position of "<<str<<" in "<<str<<" = "<<pos<<endl;
	
return 0;

}
