
#include<vector>
#include<math.h>
#include<iostream>

#include"Statistics.h"

using namespace std;

double standardDeviation(std::vector<double> samples) {
    double std_dev = 0;
    
    return std_dev;
}


/**
 * Do a z-Test for proportions to see if 2 proportions are 
 * different from one another. (example x1=13/n1=50 is different from x2=1/n2=5)
 * And construct then confidence intervals to estimate how large that difference is.
 * 
 */

void z_TestForTwoSamples(double x1, int n1, double x2, int n2, double alpha) {
    
    double z;
    
    double p1, p2, p;
    
    p1 = x1 / n1;
    p2 = x2 / n2;
    
    p = (x1 + x2)/(n1 + n2);
    
    //formula for calculating z value 
    z = (p1 - p2) / ((sqrt(p * (1 - p))) * (sqrt(((double)1 / n1) + ((double)1 / n2)))); 
    
    double z_number = 1.96; //should be guessed from z-Table according to confidence
    
    
    if( z < -(z_number) || z > z_number) {
        
        cout <<"z-Test give us: "<<z<<endl;
        cout << "We reject null hypothesis H0" <<endl;
    }
    else {
        
        cout <<"z-Test give us: "<<z<<endl;
        cout << "We retain null hypothesis H0" <<endl;
    }
    
    //calcultate
    
}