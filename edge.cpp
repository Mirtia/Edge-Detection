#include "edge.h"

cv::Mat EdgeFilter::edgeCanny(int threshold_1, int threshold_2, int sigma_X)
{
    cv::Mat blurredImage;
    cv::Mat edges;
    cv::GaussianBlur(this->inputArray, blurredImage, cv::Size(this->kernelSize, this->kernelSize), sigma_X);
    cv::Canny(blurredImage, edges, threshold_1, threshold_2);
    
    return edges;
}

cv::Mat EdgeFilter::edgeLaplacian(int sigma_X, int ddepth, int scale = 1, int delta = 0)
{
    cv::Mat blurredImage;
    cv::Mat edges, absEdges;
    cv::GaussianBlur(this->inputArray, blurredImage, cv::Size(this->kernelSize, this->kernelSize), sigma_X);
    cv::Laplacian( this->inputArray, edges, ddepth, kernelSize, scale, delta, cv::BORDER_DEFAULT);
    convertScaleAbs(edges, absEdges);

    return absEdges; 
}

cv::Mat EdgeFilter::edgeGaussianDiff(int sigma_X, double factor, int gamma)
{
    cv::Mat blurredImage;
    cv::Mat edges;
    cv::Mat gaussian_1, gaussian_2;

    cv::GaussianBlur(this->inputArray, gaussian_1, cv::Size(this->kernelSize, this->kernelSize), sigma_X);
    cv::GaussianBlur(this->inputArray, gaussian_2, cv::Size(this->kernelSize, this->kernelSize), sigma_X * factor);
    cv::subtract(gaussian_1, gamma * gaussian_2, edges);

    return edges;
}

cv::Mat EdgeFilter::edgeScharrSobel(int ddepth, int ksize, int scale, int delta, double beta, double gamma)
{
    cv::Mat grad_X, grad_Y;
    cv::Mat absGrad_X, absGrad_Y;
    cv::Mat edges;

    cv::Sobel(this->inputArray, grad_X, ddepth, 1, 0, ksize, scale, delta, cv::BORDER_DEFAULT);
    cv::Sobel(this->inputArray, grad_Y, ddepth, 0, 1, ksize, scale, delta, cv::BORDER_DEFAULT);

    convertScaleAbs(grad_X, absGrad_X);
    convertScaleAbs(grad_Y, absGrad_Y);

    addWeighted(absGrad_X, beta, absGrad_Y, gamma, 0, edges);

    return edges;
}
