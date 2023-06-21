#include <stdio.h>
#include "edge.h"
#include "util.h"

int main(int argc, const char **argv)
{
    // Printing OpenCV version
    printf("OpenCV version: %s\n", CV_VERSION);
    
    const char *keys = {
        "{help h usage ?    |       | See usage}"
        "{input i           |       | Path to input image}"};

    cv::CommandLineParser parser(argc, argv, keys);

    if (parser.has("help"))
    {
        parser.printMessage();
        printf("Example usage: edge-detection.exe -i=image.jpg\n");
        return 0;
    }

    std::string filename = parser.get<std::string>("input");

    if (filename.empty())
    {
        printf("Error: Input file required.\n");
        return -1;
    }

    cv::Mat image = cv::imread(filename, cv::IMREAD_GRAYSCALE);

    if (image.empty())
    {
        printf("Error: Cannot read image file.\n");
        return -1;
    }

    EdgeFilter edgeFilter(image, 3);
    std::vector<cv::Mat> images;

    // TODO: Understand what the correct parameters are for both blurring and filters
    cv::Mat cannyImage = edgeFilter.edgeCanny(0, 100, 3);
    cv::Mat laplaceImage = edgeFilter.edgeLaplacian(0, 3, 1, 0);
    // This is fine! factor = 0.5 and sigma_X = 1
    cv::Mat OGDImage = edgeFilter.edgeGaussianDiff(0, 0.5, 1);
    cv::Mat sobelImage = edgeFilter.edgeScharrSobel(3, 1, 1, 1, 1, 0);
    // Create a vector of images that contains the results of the edge filters
    // and the original image to plot in a single window
    images.push_back(image);
    images.push_back(cannyImage);
    images.push_back(laplaceImage);
    images.push_back(OGDImage);
    images.push_back(sobelImage);
    plotImages(images, "Edge Detection Comparison");
    cv::waitKey(0);
    return 0;
}
