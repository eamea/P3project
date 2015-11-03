#pragma once
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/features2d.hpp"

using namespace std;
using namespace cv;

class Recognizer
{
public:
	Recognizer();
	void BLOBAnalyze(char x);
	void extractFeatures(char x);
	void compareFeatures(char x);
	bool recognize(char x);
private:
	Mat blueThreshImg;
	Mat greenThreshImg;
	//Mat pinkThreshImg;
	Mat redThreshImg;
	Mat yellowThreshImg;
	
	//Need variables for basic features.

	//Need variables for extracted features.
};

