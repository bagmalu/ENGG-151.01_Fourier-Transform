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

    double * digital_freq = new double[nSteps];
    double changeinfreq = ((end_freq-start_freq)/(nSteps-1));

    cout << "\nsampling rate: " << sampling_rate << endl;
    cout << "start_freq: " << start_freq << endl;
    cout << "end_freq: " << end_freq << endl;
    cout << "nSteps: " << nSteps << endl;
    cout << "changeinfreq: " << changeinfreq << "\n\n";
    
    for(int i=0; i<=nSteps-1; i++)
    {
      digital_freq[i] = 2*M_PI*((start_freq+(i*changeinfreq))/sampling_rate);
      cout << digital_freq[i] << endl;
    }
    
//    //for testing
//    for(int i=0; i<=duration-1; i++)
//      cout << data[i] << endl;

    // //solving for output index
    // int xcorrIndex = xIndex - (yIndex + yDuration - 1);

    // //output data variables
    // int xcorrDuration = 0;

    // double * xcorrData = new double [xcorrDuration];

    // //computing for output
    // computeNormalizedCrosscorrelation(
    //   xData, xDuration, xIndex,
    //   yData, yDuration, yIndex,
    //   xcorrData, xcorrDuration, xcorrIndex);

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
