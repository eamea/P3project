#include "Detector.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


using namespace cv;

Detector::Detector(int tVal, int kSize)
{
	thresholdValue = tVal;
	kernelSize = kSize;
}

Mat Detector::segmentFrame(Mat src){
	Mat result;

	cvtColor(src,result, CV_BGR2GRAY);

	threshold(result, result, thresholdValue, 255, CV_THRESH_BINARY);

	//opening
	erode(result, result, getStructuringElement(MORPH_ELLIPSE, Size(kernelSize, kernelSize)));
	dilate(result, result, getStructuringElement(MORPH_ELLIPSE, Size(kernelSize, kernelSize)));

	//closening
	dilate(result, result, getStructuringElement(MORPH_ELLIPSE, Size(kernelSize, kernelSize)));
	erode(result, result, getStructuringElement(MORPH_ELLIPSE, Size(kernelSize, kernelSize)));

	return result;	
}
