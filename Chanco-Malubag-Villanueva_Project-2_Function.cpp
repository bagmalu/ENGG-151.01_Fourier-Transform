
// Chanco, Malubag, Villanueva
// 3 BS Computer Engineering

// ENGG 151.01
// Project 2: Fourier Transform

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>
#include <iomanip>

#include "Chanco-Malubag-Villanueva_Project-2_Function.h"

using namespace std;

//DFT Function
void computeDFT
(
    double *xData, int xDuration,
    double samplingFreq, double startFreq,
    double endFreq, int nSteps,
    double *realPart, double *imagPart,
    double *magnitude, double *phase
)
{
    // Initialize real and imaginary parts to zero
    for (int i = 0; i <= nSteps; i++)
    {
        realPart[i] = 0.0;
        imagPart[i] = 0.0;
    }

    double changeinfreq = (endFreq - startFreq) / (nSteps);

    for (int k = 0; k <= nSteps; k++)
    {
        double digital_freq = 2 * M_PI *
        (startFreq + k * changeinfreq) / samplingFreq;

        for (int n = 0; n < xDuration; n++)
        {
            realPart[k] += xData[n] * cos(digital_freq*n);
            imagPart[k] -= xData[n] * sin(digital_freq*n);
        }

        magnitude[k] = sqrt(realPart[k] * realPart[k] +
                            imagPart[k] * imagPart[k]);

        if (realPart[k] != 0 || imagPart[k] != 0)
        {
            phase[k] = atan2(imagPart[k], realPart[k]) * (180.0 / M_PI);
        }
        else
        {
            phase[k] = 0.0;
        }
    }
}

//Output function
void outputResult(string filename,
                  double* realPart,
                  double* imagPart,
                  double* magnitude,
                  double* phase,
                  int nSteps,
                  double startFreq,
                  double changeinfreq)
{

    ofstream outfile(filename);
    if (outfile.is_open())
    {
        outfile << setw(16) << "frequency (Hz)"
                << setw(16) << "real part"
                << setw(16) << "imaginary part" << endl;

        for (int i = 0; i <= nSteps; i++)
        {
            double frequency = startFreq + i * changeinfreq;
            outfile << setw(16) << frequency
                    << setw(16) << realPart[i]
                    << setw(16) << imagPart[i] << endl;
        }

        // Output header for magnitude and phase
        outfile << "\n" << setw(16) << "frequency (Hz)"
                << setw(16) << "magnitude"
                << setw(16) << "phase (degrees)" << endl;

        for (int i = 0; i <= nSteps; i++)
        {
            double frequency = startFreq + i * changeinfreq;
            outfile << setw(16) << frequency
                    << setw(16) << magnitude[i]
                    << setw(16) << phase[i] << endl;
        }

        outfile.close();
    }
    else
    {
        cerr << "Error opening file: " << filename << endl;
    }
}

//Import Function
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
    int index = 0;

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
      cout << "\nSignal duration " << duration <<
      " extracted from " << filename << endl;

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