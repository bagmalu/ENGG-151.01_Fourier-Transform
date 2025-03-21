
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
    double * realPart, double * imagPart, //og was double ** for both
    double * magnitude, double * phase) //og was double ** for both
{
  for(int i=0; i<=nSteps-1; i++)
    {
      double changeinfreq = ((endFreq-startFreq)/(nSteps-1));
      double digital_freq = 2*M_PI*((startFreq + i * changeinfreq)/samplingFreq);

      for(int n = 0; n < nSteps; n++)
      {
        realPart[i] += xData[n] * cos(digital_freq * n);
        imagPart[i] += xData[n] * sin(digital_freq * n);
      }

      magnitude[i] = sqrt(realPart[i] * realPart[i] + imagPart[i] * imagPart[i]);
      // frequencies[i] = digital_freq; --> change w formula to go back to phase
    }
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
     int index = 0; //should always ignore and assume to be 0 tho may smtg sa specs about input val nito

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
