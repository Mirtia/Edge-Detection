#include "edge.h"
#include <stdio.h>

int main(int argc, const char **argv)
{
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

    cv::namedWindow("Image", cv::WINDOW_NORMAL);
    cv::resizeWindow("Image", DEFAULT_WIDTH, DEFAULT_HEIGHT);
    cv::imshow("Image", image);

    cv::waitKey(0);
    return 0;
}
