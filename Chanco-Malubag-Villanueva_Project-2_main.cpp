// Chanco, Malubag, Villanueva
// 3 BS Computer Engineering

// ENGG 151.01
// Project 2: Fourier Transform

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

#include "Chanco, Malubag, Villanueva_Project 2_Function.h"

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
    long sampling_rate = strtol(argv[2], NULL, 10);
    long start_freq = strtol(argv[3], NULL, 10);
    long end_freq = strtol(argv[4], NULL, 10);
    long nSteps = strtol(argv[5], NULL, 10);

    //output file
    string output = (argc == 7) ? argv[6] : "dftlog.txt";
    cout << "\nOutput will be uploaded to: " << output << endl;

    int l_points = 0; //duration

    double * data = importData(signal_file, l_points);

    double * digital_freq = new double[nSteps];
    double changeinfreq = (end_freq-start_freq)/(nSteps-1);
    
    for(int i=0; i<=nSteps-1; i++)
    {
      digital_freq[i] = 2*PI()*((start_freq+(i*changeinfreq))/sampling_rate);
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
