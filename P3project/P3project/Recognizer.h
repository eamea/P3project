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
	void BLOBAnalyzeGlove2();
	void extractFeatures(char letter);
	void extractFeaturesGlove2();
	bool compareFeatures(char letter, bool leftHand);
	bool compareFeaturesGlove2(char letter, bool leftHand);
	bool recognize(char letter, bool leftHand);			//Runs the functions in order and returns a bool based on whether it found the sign for the input char.
	bool recognizeGlove2(char letter, bool leftHand);

	Mat getBlueBLOBImg();
	Mat getGreenBLOBImg();
	Mat getPinkBLOBImg();
	Mat getRedBLOBImg();
	Mat getYellowBLOBImg();

	Detector getDetector();
	void setDetector(Detector d);
private:
	Detector dt;
	BLOBDetector BLOBdt;
	bool leftHanded = true;

	vector<vector<Point>> blueBLOBList;
	vector<vector<Point>> greenBLOBList;
	vector<vector<Point>> pinkBLOBList;
	vector<vector<Point>> redBLOBList;
	vector<vector<Point>> yellowBLOBList;

	//Matrices to hold the thresholded images.
	Mat blueThreshImg;
	Mat greenThreshImg;
	Mat pinkThreshImg;
	Mat redThreshImg;
	Mat yellowThreshImg;

	//Matrices to hold the BLOB analysed images.
	Mat blueBLOBImg;
	Mat greenBLOBImg;
	Mat pinkBLOBImg;
	Mat redBLOBImg;
	Mat yellowBLOBImg;

	Mat hasBeenFound;

	int blueSmallestX;
	int blueLargestX;
	int blueSmallestY;
	int blueLargestY;
	int blueDistanceX;
	Point blueCenter;

	int greenSmallestX;
	int greenLargestX;
	int greenSmallestY;
	int greenLargestY;
	Point greenCenter;

	int pinkSmallestX;
	int pinkLargestX;
	int pinkSmallestY;
	int pinkLargestY;
	Point pinkCenter;

	int redSmallestX;
	int redLargestX;
	int redSmallestY;
	int redLargestY;
	int redDistanceX;
	Point redCenter;

	int yellowSmallestX;
	int yellowLargestX;
	int yellowSmallestY;
	int yellowLargestY;
	Point yellowCenter;

	int errorAllowance = 10;
	int multiplier2 = 2;
	int multiplier = 3;


	//Need variables for basic features.
	//Need variables for extracted features.
};

