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

//Thresholds based on the car inserted. b = blue, g = green, p = pink, r = red, y = yellow.
void Detector::setThreshold(char color){
	switch (color){
	case 'b':
		iLowH = 105;
		iHighH = 121;

		iLowS = 75;
		iHighS = 255;

		iLowV = 0;
		iHighV = 255;

		break;
	case 'g':
		iLowH = 23;
		iHighH = 82;

		iLowS = 77;
		iHighS = 162;

		iLowV = 42;
		iHighV = 255;

		break;
	case 'p':
		iLowH = 130;
		iHighH = 179;

		iLowS = 58;
		iHighS = 157;

		iLowV = 54;
		iHighV = 243;

		break;
	case 'r':
		iLowH = 0;
		iHighH = 9;

		iLowS = 138;
		iHighS = 255;

		iLowV = 86;
		iHighV = 255;

		break;
	case 'y':
		iLowH = 17;
		iHighH = 36;

		iLowS = 98;
		iHighS = 213;

		iLowV = 126;
		iHighV = 255;

		break;
	default:
		cout << "Cannot threshold the inserted char. Not valid." << endl;
		break;
	}
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
