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
	void createTrackbars();
private:
	int thresholdValue;
	int kernelSize;

	int iLowH = 0;
	int iHighH = 179;

	int iLowS = 0;
	int iHighS = 255;

	int iLowV = 0;
	int iHighV = 255;
};

