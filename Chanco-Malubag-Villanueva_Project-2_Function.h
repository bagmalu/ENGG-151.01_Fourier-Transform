// Chanco, Malubag, Villanueva
// 3 BS Computer Engineering

// ENGG 151.01
// Project 2: Fourier Transform

#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//copy-pasted from specs
void computeDFT(
    double * xData, int xDuration,
    double samplingFreq, double startFreq, double endFreq, int nSteps,
    double ** realPart, double ** imagPart,
    double ** magnitude, double ** phase);

double * importData (string filename, int &duration);

#endif // FUNCTION_H
