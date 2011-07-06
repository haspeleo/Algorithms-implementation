/* 
 * File:   main.cpp
 * Author: doghmen
 *
 * Created on 12 février 2011, 17:57
 */

#include <cstdlib>
#include<string>
#include<iostream>

using namespace std;


int main(int argc, char** argv) {
    const int N = 3;

    string Questions[N] = {" Capitale de France ", "Os mobile de google ", "Meilleur moteur de recherche"};

    string Suggestions[3][N] = {{"Berlin", "Londres", "Paris"},
                                {"Android", "iOS", "Symbian"},
                                {"Bing", "google", "megavideo"}};

    char response [N] = {'C', 'A', 'B'};

    string Justifications[N] = {"Revise ton cours de geographie",
                                "C'est l'OS sur les Htc",
                                "tout le monde le sait!"};
    for(int i = 0; i < N; i++) {
        cout <<"Q"<<i<<" = "<<Questions[i]<<" ?"<<endl;
        cout <<"-----"<<endl;
        for (int j = 0; j < 3; j++) {
            cout <<Suggestions[i][j]<<endl;
            
        }
    }


    return 0;
}

