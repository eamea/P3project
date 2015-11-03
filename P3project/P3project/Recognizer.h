#pragma once
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/features2d.hpp"
#include "BLOBDetector.h"

using namespace std;
using namespace cv;

class Recognizer
{
public:
	Recognizer();
	void BLOBAnalyze(char x);		//BLOB analyzes the relevant threshimages based on the char input.
	void extractFeatures(char x);
	bool compareFeatures(char x);
	bool recognize(char x);			//Runs the functions in order and returns a bool based on whether it found the sign for the input char.
private:
	//Matrices to hold the thresholded images.
	Mat blueThreshImg;
	Mat greenThreshImg;
	//Mat pinkThreshImg;
	Mat redThreshImg;
	Mat yellowThreshImg;

	//Matrices to hold the BLOB analysed images.
	Mat BLOBBlueImg;
	Mat BLOBGreenImg;
	//Mat BLOBPinkImg;
	Mat BLOBRedImg;
	Mat BLOBYellowImg;

	BLOBDetector detector;
	
	//Need variables for basic features.

	//Need variables for extracted features.
};

