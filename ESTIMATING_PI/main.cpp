
#include<iostream>
#include <cstdlib>
#include<math.h>


using namespace std;

int main(int argc, char** argv) {

    double nbTotalPoints = 0;
    double nbPointsInSquare = 0;
    double PI;
    int timeLeft = 10000;
    double x, y;

    srand(time(NULL));
    cout <<"*** Estimating PI by Monte-Carlo Simulations ***"<<endl;
    
    while (timeLeft > 0) {
        x = (double)(rand() % 10) / 10;
        y = (double)(rand() % 10) /10;
      
        nbTotalPoints ++;

        if ((sqrt (x * x + y * y)) < 1) {
            nbPointsInSquare ++;
        }
        timeLeft --; 
    }
    cout <<"Nb Total points = "<<nbTotalPoints<<endl;
    cout <<"Nb points in square = "<<nbPointsInSquare<<endl;

    PI = 4 * (nbPointsInSquare / nbTotalPoints);

    cout <<"Using time budget = "<<timeLeft<<endl;
    cout <<"Estimated PI = "<<PI<<endl;

    return 0;
}

