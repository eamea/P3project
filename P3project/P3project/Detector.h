#pragma once
#include "opencv2/opencv.hpp"
class Detector
{
public:
	Detector(int tVal, int kSize);
	Mat segmentFrame(Mat src);
private:
	int thresholdValue;
	int kernelSize;
};

