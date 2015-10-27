#pragma once
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

class Detector
{
public:
	Detector(int tVal, int kSize);
	Mat segmentFrame(Mat src);
private:
	int thresholdValue;
	int kernelSize;
};

