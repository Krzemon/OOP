#include "Histogram.h"

Histogram::Histogram(int n, int nEntries, int nBins, double xMin, double xMax, int height, const char* sign) : n(n), nEntries(nEntries), nBins(nBins), xMin(xMin), xMax(xMax), height(height), sign(sign) {}

Histogram::Histogram(int argc, char* argv[], int n, int nEntries, int nBins, double xMin, double xMax, int height, const char* sign) {

    if(argc == 1) Histogram(n, nEntries, nBins, xMin, xMax, height, sign);
    if(argc > 1) sign = argv[1];
    if(argc > 2 && atoi(argv[2]) > 0){
        nBins = atoi(argv[2]);
        if(argc > 3 && atoi(argv[3]) > 0){
            height = atoi(argv[3]);
            if(argc > 4 && atof(argv[4]) > 0){
                xMin = atof(argv[4]);
                if(argc > 5 && atof(argv[5]) > atof(argv[4])){
                    xMax = atof(argv[5]);
                    if(argc > 6 && atoi(argv[6]) > 0)
                        n = atoi(argv[6]);
    } } } }
}

// void Histogram::generate(){
//     srand(time(0));
    
//     int nBinsTotal = nBins+2;
//     const double binWidth = (xMax-xMin)/nBins;

//     std::vector<int> binContent(nBinsTotal, 0);
//     std::vector<double> vals(nEntries, 0);

//     double sum = 0;
    
//     for(int i=0; i<nEntries; ++i){
//         double xi = 0;
//         for(int j=0; j<n; ++j) xi += rand()/double(RAND_MAX);
//         xi /= n;
//         vals.at(i) = xi;
//         sum += xi;
    
//         int bin;
//         if(xi<xMin) bin = 0;
//         else if(xi>=xMax) bin=nBinsTotal-1;
//         else bin = (xi-xMin)/binWidth+1;
    
//         ++binContent.at(bin);
//     }
    
//     double maxValue = 0;
//     for(int val: binContent)
//         if(val>maxValue) maxValue = val;
    
//     const double rowHeight = maxValue/height;
//     for(int i=height-1; i>=0; --i){
//         for(int j=0; j<nBinsTotal; ++j){
//         if(j==0 || j==nBinsTotal-1)
//             std::cout << "+";
//         else if(binContent.at(j-1)/rowHeight > i)
//             std::cout << sign;
//         else
//             std::cout << " ";
//         }
//         std::cout << std::endl;
//     }

    // for(int i=0; i<nBinsTotal; ++i){
    //     if(i==0)
    //         std::cout << xMin;
    //     else if(i==nBinsTotal-1)
    //         std::cout << xMax;
    //     else
    //         std::cout << xMin + i*binWidth;
    //     std::cout << " ";
    // }

    // std::cout << std::endl;

    // for(int i=0; i<nBinsTotal; ++i){
    //     std::cout << binContent[i] << " ";
    // }

    // std::cout << std::endl;

    // double average = sum/nEntries;
    // std::cout << "Average: " << average << std::endl;

    // double variance = 0;
    // for(int i=0; i<nEntries; ++i){
    //     variance += (vals[i]-average)*(vals[i]-average);
    // }
    // variance /= nEntries;
    // std::cout << "Variance: " << variance << std::endl;
// }