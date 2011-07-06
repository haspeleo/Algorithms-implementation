/* 
 * File:   main.cpp
 * Author: doghmen
 *
 * Created on 1 février 2011, 15:39
 */
#include<iostream>
#include<string>
#include<vector>
#include <list>

using namespace std;

int main(int argc, char** argv) {

    vector<string> SS;
    SS.push_back("The number is 10");
    SS.push_back("The number is 20");
    SS.push_back("The number is 30");

    cout <<"*** Loop index by: *** "<<endl;

    for (int ii = 0; ii < SS.size(); ii++) {
        cout <<SS[ii]<<endl;
    }
    cout <<"*** Constant iterator: *** "<<endl;

    vector<string>::const_iterator cii;

    for (cii = SS.begin(); cii < SS.end(); cii++) {
        cout << *cii <<endl;
    }

    cout <<"*** Reverse iterator *** "<<endl;
    
    vector<string>::reverse_iterator rii;
    for (rii = SS.rbegin(); rii < SS.rend(); rii++) {
        cout <<*rii<<endl;
    }

    cout <<"Sample output :"<<endl;

    cout <<"Size = "<<SS.size()<<endl;
    cout <<"Third element :"<<  SS[2] <<endl;
    
    swap(SS[0], SS[2]);
    cout <<"See the results: "<<endl;


    for (cii = SS.begin(); cii < SS.end(); cii++) {
        cout <<*cii<<endl;
    }

    list<int> List;
    List.push_back(7);  //insert from the end
    List.push_front(1); //insert at the beginning
    List.insert(++List.begin(), 33);

    List.push_back(5);
    List.push_back(6);

    list<int>::iterator it;

    for (it = List.begin(); it != List.end(); it++) {
        cout <<*it<<" ";
        
    }
    cout <<"----------------------------------"<< endl;

    vector<int>vec1, vec2, vec3;
    cout<<"VEC 1 DATA: ";
    for(int i = 1; i <= 10; i++) {
        vec1.push_back(i);
    }
    for(int i = 0; i < vec1.size(); i++) {
        cout<<vec1[i]<<" ";
    }
    for(int i = 11; i <=20; i++) {
        vec2.push_back(i);
    }
    for (int i = 11; i < vec2.size(); i++) {
        cout <<vec2[i]<<endl;
    }
    cout <<"\n\n";
    if (vec1 != vec2) {
        cout <<"Vector 1 NOT equal to Vector 2!"<<endl;
    }
    else {
        cout <<"Vector 1 is equal to Vector 2!"<<endl;
    }


    return 0;
}

