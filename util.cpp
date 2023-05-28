#include "util.h"

void plotImages(std::vector<cv::Mat> images, const char* title)
{
    // For this test, it is assumed that all images have the same size
    size_t numImages = images.size();
    int side = static_cast<int>(std::ceil((std::sqrt(numImages))));
    int imageWidth = images.back().cols;
    int imageHeight = images.back().rows;
    // Grayscale images so CV_8UC1 (Unsigned 8 Channel 1)
    cv::Mat canvas(side * imageHeight, side * imageWidth, CV_8UC1, cv::Scalar(255, 255, 255));
    for (size_t i = 0; i < numImages; i++)
    {
        // ROI stands for Region of Interest
        cv::Rect roi(i % side * imageWidth, static_cast<int>(i / side) * imageHeight, imageWidth, imageHeight);
        images[i].copyTo(canvas(roi));
    }
    cv::namedWindow(title, cv::WINDOW_NORMAL);
    cv::resizeWindow(title, DEFAULT_WIDTH, DEFAULT_HEIGHT);
    cv::imshow(title, canvas);
}