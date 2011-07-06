/* 
 * File:   main.cpp
 * Author: doghmen
 *
 * Created on 12 février 2011, 14:32
 */

#include <cstdlib>
#include <iostream>
using namespace std;


int main(int argc, char** argv) {

    string responseA = "Berlin";
    string responseB = "Londres";
    string responseC = "Paris";
    
    cout <<"**** QCM ****"<<endl;

    cout <<"Q1 : Quelle est la capiltale de la France ?"<<endl;
    cout<<"A) "<<responseA<<endl;
    cout<<"B) "<<responseB<<endl;
    cout<<"C) "<<responseC<<endl;

    char response;
    do {
        cout <<"Entrez votre response(A, B ou C): "<<endl;
        cin >> response;
        
    } while (response != 'A' && response != 'B' && response != 'C');

    string *choice;
    string *responseUser(0);

    
            switch(response) {
                    case 'A': responseUser = &responseA;
                    break;
                    case 'B': responseUser = &responseB;
                    break;
                    case 'C': responseUser = &responseC;
                    break;
            }

            cout <<"You have chosen : "<<*responseUser<<endl;

            if (response == 'C')
                cout <<"Correct response :)"<<endl;
            else
                cout <<"False response :("<<endl;
    return 0;
}

