/* 
 * File:   Statistics.h
 * Author: lri
 *
 * Created on 28 mai 2011, 20:13
 */


#include <vector>

#ifndef STATISTICS_H
#define	STATISTICS_H




double standardDeviation(std::vector<double> samples);
void z_TestForTwoSamples(double x1, int n1, double x2, int n2, double alpha);



#endif	/* STATISTICS_H */

