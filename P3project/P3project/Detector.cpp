#include "Detector.h"

//Constructor
Detector::Detector(int kSize)
{
	kernelSize = kSize;
}

//creates a windows called "control" with trackbars for setting HSV values.
void Detector::createTrackbars()
{
	namedWindow("Control", CV_WINDOW_AUTOSIZE);

	cvCreateTrackbar("LowH", "Control panel", &iLowH, 179);
	cvCreateTrackbar("HighH", "Control panel", &iHighH, 179);

	cvCreateTrackbar("LowS", "Control panel", &iLowS, 255);
	cvCreateTrackbar("HighS", "Control panel", &iHighS, 255);

	cvCreateTrackbar("LowV", "Control panel", &iLowV, 255);
	cvCreateTrackbar("HighV", "Control panel", &iHighV, 255);
}

//Returns a Mat that has been segmented with HSV values.
Mat Detector::segmentFrame(Mat src){
	Mat result;

	cvtColor(src, result, CV_BGR2HSV); //converting to HSV

	inRange(result, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), result); //thresholding based on HSV values

	//opening
	erode(result, result, getStructuringElement(MORPH_ELLIPSE, Size(kernelSize, kernelSize)));
	dilate(result, result, getStructuringElement(MORPH_ELLIPSE, Size(kernelSize, kernelSize)));

	//closening
	dilate(result, result, getStructuringElement(MORPH_ELLIPSE, Size(kernelSize, kernelSize)));
	erode(result, result, getStructuringElement(MORPH_ELLIPSE, Size(kernelSize, kernelSize)));

	return result;	//returning the thresholded image.
}
