#ifndef UTIL_H
#define UTIL_H
#define DEFAULT_WIDTH 1920
#define DEFAULT_HEIGHT 1060

#include <opencv2/opencv.hpp>

void plotImages(std::vector<cv::Mat> images, const char* title);

#endif  /*UTIL_H*/