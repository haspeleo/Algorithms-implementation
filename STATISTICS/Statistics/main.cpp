/* 
 * File:   main.cpp
 * Author: lri
 *
 * Created on 28 mai 2011, 20:09
 * http://easycalculation.com/statistics/standard-deviation.php
 * video tutorials on many things: http://www.khanacademy.org/ and go to statistics
 */

#include <cstdlib>
#include <iostream>

#include"Statistics.h"13

using namespace std;



int main(int argc, char** argv) {
    
    double x1, x2;
    int n1, n2;
    double alpha;
    
    cout<<"*** STATISTICS ***"<<endl;
    cout<<"Z-Test for propotions, 2 samples"<<endl;
    cout<<"Give 2 fractions:"<<endl;
    cin >> x1 >> n1 >> x2 >> n2;
    
    cout<<"Give confidence in % (95 for example):"<<endl;
    cin >> alpha;
    
    z_TestForTwoSamples(x1, n1, x2, n2, alpha);
    
    return 0;
}

