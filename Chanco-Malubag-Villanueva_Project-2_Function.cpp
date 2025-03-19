
// Chanco, Malubag, Villanueva
// 3 BS Computer Engineering

// ENGG 151.01
// Project 2: Fourier Transform

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

#include "Chanco-Malubag-Villanueva_Project-2_Function.h"

using namespace std;

//copy-pasted from specs
void computeDFT(
    double * xData, int xDuration,
    double samplingFreq, double startFreq, double endFreq, int nSteps,
    double ** realPart, double ** imagPart,
    double ** magnitude, double ** phase)
{
  
}
// The magnitude and phase could be computed separately from the
// real and imaginary parts produced by the function

double * importData (string filename, int &duration)
 {
   ifstream f(filename);

   if(f.good())
   {
     string line;
     stringstream s;

     vector<double> v;

     double number;
     double * signal;

     bool firstLine = true;

     duration = 0;
     int index = 0; //should always ignore and assume to be 0

     cout << "\n" << filename << " accessed!\n";

     while(getline(f,line))
     {
       s << line;

       if(firstLine)
       {
         duration++;
         s >> index;
       }
       else //if not first line
       {
         duration++;

         while(s >> number)
         {
           v.push_back(number);
         }

         s.clear();
       }

       //reset all
       s.clear();
       number = 0;
       line.clear();
       firstLine = false;
     }

     //putting into array
     if(v.size() !=0)
     {
       int j = 0;

       signal = new double [duration];

       for(int i=0; i<duration; i++)
       {
         signal[i] = v[j];
         j++;
       }

       //console feedback
       cout << "\nSignal duration " << duration << " extracted from " << filename << endl;

       return signal;
     }
     else
     {
       cout << "\n" << filename << " is empty" << endl;
       return NULL;
     }
     cout << "\n" << filename << " is empty!\n";
   }
   cout << "\n" << filename << " not accessible" << endl;
   return NULL;
 }
