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

    // //for checking lang
    // cout << "\nsampling rate: " << sampling_rate << endl;
    // cout << "start_freq: " << start_freq << endl;
    // cout << "end_freq: " << end_freq << endl;
    // cout << "nSteps: " << nSteps << endl;
    // cout << "changeinfreq: " << changeinfreq << "\n\n";
    
    computeDFT(data, l_points,
               sampling_rate, start_freq, end_freq, nSteps,
               real_part, imag_part,
               magnitude, phase);
    
    //exporting to output file
    ofstream outputfile;
    outputfile.open(output);

    // cout << "\nNormalized Crosscorrelation Output\n";

    // if (xcorrDuration < 20)
    // {
    //   cout << xcorrIndex;
    //   for (int i = 0; i<xcorrDuration; i++)
    //   {
    //     cout << "\t" << xcorrData[i] << endl;
    //   }
    // }


    // outputfile << xcorrIndex;
    // for (int i = 0; i < xcorrDuration; i++)
    //   outputfile << "\t" << xcorrData[i] << endl;

    cout << "\nOutput successfully written to: " << output << endl;

    //close the file
    outputfile.close();
  }
  return 0;
}
