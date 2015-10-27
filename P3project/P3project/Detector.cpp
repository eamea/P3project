#include "Detector.h"

Detector::Detector(int tVal, int kSize)
{
	thresholdValue = tVal;
	kernelSize = kSize;
}

void Detector::createTrackbars()
{
	namedWindow("Control panel", CV_WINDOW_AUTOSIZE);

	cvCreateTrackbar("low Hue", "Control panel", &iLowH, 179);
	cvCreateTrackbar("High Hue", "Control panel", &iHighH, 179);

	cvCreateTrackbar("Low sat", "Control panel", &iLowS, 255);
	cvCreateTrackbar("High sat", "Control panel", &iHighS, 255);

	cvCreateTrackbar("Low value", "Control panel", &iLowV, 255);
	cvCreateTrackbar("High value", "Control panel", &iHighV, 255);
}

Mat Detector::segmentFrame(Mat src){
	Mat result;

	cvtColor(src, result, CV_BGR2HSV);

	inRange(result, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), result);

	//opening
	erode(result, result, getStructuringElement(MORPH_ELLIPSE, Size(kernelSize, kernelSize)));
	dilate(result, result, getStructuringElement(MORPH_ELLIPSE, Size(kernelSize, kernelSize)));

	//closening
	dilate(result, result, getStructuringElement(MORPH_ELLIPSE, Size(kernelSize, kernelSize)));
	erode(result, result, getStructuringElement(MORPH_ELLIPSE, Size(kernelSize, kernelSize)));

	return result;
}
