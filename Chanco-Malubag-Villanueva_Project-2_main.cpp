// Chanco, Malubag, Villanueva
// 3 BS Computer Engineering

// ENGG 151.01
// Project 2: Fourier Transform

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

#include "Function.h"

using namespace std;

int main(int argc, char *argv[])
{
  if((argc < 6) || (argc > 7))
  {
    cout << "\nInput format should be: " << argv[0]
         << " <signal-file> <sampling-rate> <start-freq> <end-freq> <num of steps> <output-file>" << endl;

    cout << "\nProgram has been terminated" << endl;
  }
  else
  {
    //input file
    string signal_file = argv[1];

    //initialize values based on command prompt
    stringstream s;

    double sampling_rate = 0.0;
    double start_freq = 0.0;
    double end_freq = 0.0;
    int nSteps = 0;

    s << argv[2];
    s >> sampling_rate;
    s.clear();
    s << argv[3];
    s >> start_freq;
    s.clear();
    s << argv[4];
    s >> end_freq;
    s.clear();
    s << argv[5];
    s >> nSteps;
    s.clear();

    //output file
    string output = (argc == 7) ? argv[6] : "dftlog.txt";
    cout << "\nOutput will be uploaded to: " << output << endl;

    int l_points = 0; //duration

    double * data = importData(signal_file, l_points);

    // double * signal = new double[nSteps]; --> ion remember where we used this

    double * real_part = new double[nSteps];
    double * imag_part = new double[nSteps];
    double * magnitude = new double[nSteps];
    double * phase = new double[nSteps];


    computeDFT(data, l_points,
               sampling_rate, start_freq, end_freq, nSteps,
               real_part, imag_part,
               magnitude, phase);


    // Calculate frequency step size
    double changeinfreq = (end_freq - start_freq) / (nSteps);

    //exporting to output file
    outputResult(output.c_str(), real_part, imag_part, magnitude, phase, nSteps, start_freq, changeinfreq);
    cout << "\nOutput successfully written to: " << output << endl;

  }
  return 0;
}
