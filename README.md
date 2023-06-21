# Edge Detection OpenCV

## Notes

To prevent OpenCV **INFO** messages from showing at the execution, set the variable:

```bash
export OPENCV_LOG_LEVEL=OFF
```

## Background

This section is entirely informative, and mainly it consists of important info I collected to grasp how edge detection works.

### Blurring

As stated in [OpenCV documentation](https://docs.opencv.org/4.x/d4/d86/group__imgproc__filter.html#gaabe8c836e97159a9193fb0b11ac52cf1):

```c++
void cv::GaussianBlur(InputArray src,
    OutputArray dst,
    Size ksize,
    double sigmaX,
    double sigmaY = 0,
    int borderType = BORDER_DEFAULT 
);
```

#### Parameters

- **sigmaX**: standard deviation for Gaussian kernel (X direction)
- **sigmaY**: standard deviation for Gaussian kernel (Y direction)
- **borderType**: pixel extrapolation method

Higher sigma values mean more pronounced blurring effect. Common values for **σ** are **{1, 3, 5}**.

Before resuming to apply any edge detection filter, we always use Gaussian blur to the original image to reduce the level of noise.

```c++
void cv::blur(InputArray src,
    OutputArray dst,
    Size ksize,
    Point anchor = Point(-1,-1),
    int borderType = BORDER_DEFAULT 
)
```

### Canny Edge Detection

Steps of Canny algorithm (always check the [documentation](https://docs.opencv.org/3.4/da/d5c/tutorial_canny_detector.html)):

- Apply blurring (in our case Gaussian blur)
- Find the intensity gradients (analogous to Sobel)
- Non-maximum suppresion
- Hysterisis (threshold parameters)

```c++
void cv::Canny(InputArray image,
    OutputArray edges,
    double threshold1,
    double threshold2,
    int apertureSize = 3,
    bool L2gradient = false 
)
```

### Sobel & Scharr Filters

Sobel operator uses 3x3 kernels which are convolved with the original image to calculate approximations of the derivatives, one of the horizontal changes and one for vertical.

While reducing artifacts associated with a pure central differences operator, Sobel does not exhibit a good rotational symmetry (about 1° of error). Scharr looked into optimizing this property by producing kernels optimized for specific given numeric precision (integer, float…).

### Difference of Gaussian Kernels

The difference of Gaussians (DoG) involves the subtraction of one Gaussian blurred version of an original image from another, less blurred version. Read more [here](https://en.wikipedia.org/wiki/Difference_of_Gaussians).

We need to pass a **factor** < 1 to create a narrower variance for the second filter.

### Laplacian Edge Detection

The Laplacian operator functions as a derivative operator, emphasizing gray level discontinuities within an image while reducing the emphasis on regions with gradually changing gray levels. As a result, this operation generates images with gray-toned edge lines and other disruptions set against a dark background. Consequently, the image exhibits both inward and outward edges. We can apply Negative or Positive Laplacian operator.
