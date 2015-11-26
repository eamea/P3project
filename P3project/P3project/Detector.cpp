#include "Detector.h"

//Default constructor
Detector::Detector(){
	kernelSize = 3;
}

//Constructor
Detector::Detector(int kSize){
	cout << "Detector: kernelSize set to " << kSize << "." << endl;
	kernelSize = kSize;
}

//Getter functions for each thresholded image
Mat Detector::getBlueThreshImg(){
	return blueThreshImg;
}
Mat Detector::getGreenThreshImg(){
	return greenThreshImg;
}
Mat Detector::getPinkThreshImg(){
	return pinkThreshImg;
}
Mat Detector::getRedThreshImg(){
	return redThreshImg;
}
Mat Detector::getYellowThreshImg(){
	return yellowThreshImg;
}

//creates a windows called "control" with trackbars for setting HSV values.
void Detector::createTrackbars()
{
	namedWindow("Control panel", CV_WINDOW_AUTOSIZE);

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
		iLowH = 107;
		iHighH = 112;

		iLowS = 0;
		iHighS = 164;

		iLowV = 117;
		iHighV = 255;

		break;
	case 'g':
		iLowH = 40;
		iHighH = 74;

		iLowS = 98;
		iHighS = 203;

		iLowV = 79;
		iHighV = 255;

		break;
	case 'p':
		iLowH = 153;
		iHighH = 172;

		iLowS = 84;
		iHighS = 157;

		iLowV = 0;
		iHighV = 255;

		break;
	case 'r':
		iLowH = 156;
		iHighH = 179;

		iLowS = 124;
		iHighS = 255;

		iLowV = 0;
		iHighV = 255;

		break;
	case 'y':
		iLowH = 29;
		iHighH = 47;

		iLowS = 0;
		iHighS = 255;

		iLowV = 190;
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

//Thresholds only the colors that are needed for the specific letter.
void Detector::thresholdImageFor(Mat src, char letter){
	switch (letter){
	case 'a':
		setThreshold('b');
		blueThreshImg = segmentFrame(src);

		setThreshold('y');
		yellowThreshImg = segmentFrame(src);

		break;

	case 'b':
		setThreshold('r');
		redThreshImg = segmentFrame(src);

		setThreshold('y');
		yellowThreshImg = segmentFrame(src);

		break;

	case 'f':
		setThreshold('b');
		blueThreshImg = segmentFrame(src);

		setThreshold('g');
		greenThreshImg = segmentFrame(src);

		setThreshold('r');
		redThreshImg = segmentFrame(src);

		setThreshold('y');
		yellowThreshImg = segmentFrame(src);

		break;

	case 'l':
		setThreshold('b');
		blueThreshImg = segmentFrame(src);

		setThreshold('r');
		redThreshImg = segmentFrame(src);

		setThreshold('y');
		yellowThreshImg = segmentFrame(src);

		break;

	case 's':
		setThreshold('b');
		blueThreshImg = segmentFrame(src);

		setThreshold('y');
		yellowThreshImg = segmentFrame(src);

		break;

	case 't':
		setThreshold('b');
		blueThreshImg = segmentFrame(src);

		setThreshold('y');
		yellowThreshImg = segmentFrame(src);

		break;

	default:
		cout << "ERROR: thresholdImageFor has not been parsed a valid char." << endl;
		break;
	}
}

void Detector::thresholdForGlove2(Mat src){

	setThreshold('b');
	blueThreshImg = segmentFrame(src);

	setThreshold('g');
	greenThreshImg = segmentFrame(src);

	setThreshold('p');
	pinkThreshImg = segmentFrame(src);

	setThreshold('r');
	redThreshImg = segmentFrame(src);

	setThreshold('y');
	yellowThreshImg = segmentFrame(src);
}
