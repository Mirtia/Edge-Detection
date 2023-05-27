#include "util.h"

void plotImages(cv::Mat original_image, std::vector<cv::Mat> images)
{
    for (auto &&image : images)
    {
        if (original_image.size() != image.size())
        {
            std::cerr << "Image size different from the original image." << std::endl;
            // TODO: Handle
            return;
        }
    }

    int side = static_cast<int>(std::sqrt(images.size()));
    int width = side * images.back().size().width;
    int height = side * images.back().size().height;
    cv::Mat canvas(height, width, CV_8UC3, cv::Scalar(255, 255, 255));
    // TODO: Organize grid
}
