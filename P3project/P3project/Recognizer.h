#pragma once
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/features2d.hpp"
#include "BLOBDetector.h"
#include "Detector.h"

using namespace std;
using namespace cv;

class Recognizer
{
public:
	Recognizer(Detector d);
	void BLOBAnalyze(char letter);		//BLOB analyzes the relevant threshimages based on the char input.
	void extractFeatures(char letter);
	bool compareFeatures(char letter);
	bool recognize(char letter);			//Runs the functions in order and returns a bool based on whether it found the sign for the input char.

	Mat getBlueBLOBImg();
	Mat getGreenBLOBImg();
	Mat getRedBLOBImg();
	Mat getYellowBLOBImg();

	Detector getDetector();
	void setDetector(Detector d);
private:
	Detector dt;
	BLOBDetector BLOBdt;

	vector<vector<Point>> blueBLOBList;
	vector<vector<Point>> greenBLOBList;
	vector<vector<Point>> redBLOBList;
	vector<vector<Point>> yellowBLOBList;

	//Matrices to hold the thresholded images.
	Mat blueThreshImg;
	Mat greenThreshImg;
	Mat redThreshImg;
	Mat yellowThreshImg;

	//Matrices to hold the BLOB analysed images.
	Mat blueBLOBImg;
	Mat greenBLOBImg;
	Mat redBLOBImg;
	Mat yellowBLOBImg;

	Mat hasBeenFound;

	Point blueSmallestX;
	Point blueLargestX;

	Point redSmallestX;
	Point redLargestX;
	Point redLargestY;
	int redDistanceX;

	Point yellowSmallestX;
	Point yellowLargestX;
	Point yellowSmallestY;
	Point yellowLargestY;
	Point yellowCenter;


	//Need variables for basic features.
	//Need variables for extracted features.
};

