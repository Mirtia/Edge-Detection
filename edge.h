#ifndef EDGE_H
#define EDGE_H
#include <opencv2/opencv.hpp>

class EdgeFilter
{

public:
    EdgeFilter(const cv::Mat &inputArray, int kernelSize) : 
    inputArray(inputArray), kernelSize(kernelSize)
    {}
    
    cv::Mat edgeCanny(int threshold_1, int threshold_2, int sigma_X);
    cv::Mat edgeLaplacian(int sigma_X, int ddepth,  int scale, int delta);
    cv::Mat edgeGaussianDiff(int sigma_X, double factor, int gamma);
    cv::Mat edgeScharrSobel(int ddepth, int ksize, int scale, int delta, double beta, double gamma);

private:
    cv::Mat inputArray;
    int kernelSize;

};

#endif  /*EDGE_H*/