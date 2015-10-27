#pragma once
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

class Detector
{
public:
	Detector(int tVal, int kSize);
	Mat segmentFrame(Mat src);
private:
	int thresholdValue;
	int kernelSize;
};

