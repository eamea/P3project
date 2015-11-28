#pragma once
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "BLOBDetector.h"
#include "Detector.h"
#include <vector>
#include <cmath>

using namespace std;
using namespace cv;

class Recognizer
{
public:
	Recognizer(Detector d);									//when declaring a recognizer, tell it which detector to use (a.k.a. which thresholdImages to use)

	void recognize(char letter, bool leftHand);				//runs the functions in order and returns a bool based on whether it found the sign for the input char
	void recognizeGlove2(char letter, bool leftHand);

	void vectorRecognizer(char letter, bool leftHand);
	void vectorRecognizerGlove2(char letter, bool leftHand);

	vector<float> normalizeValues(vector<float> vc);

	bool getLetterFound();									//getters and setters for various variables
	float getEuclideanDistance();
	Mat getBlueBLOBImg();
	Mat getGreenBLOBImg();
	Mat getPinkBLOBImg();
	Mat getRedBLOBImg();
	Mat getYellowBLOBImg();
	Detector getDetector();
	void setDetector(Detector d);
private:
	void BLOBAnalyze(char letter);							//BLOB analyzes the relevant threshimages based on the char input
	void BLOBAnalyzeGlove2();
	void extractFeatures(char letter);
	void extractFeaturesGlove2();
	void extractFeaturesVector();
	void compareFeatures(char letter, bool leftHand);
	void compareFeaturesGlove2(char letter, bool leftHand);

	Detector dt;
	BLOBDetector BLOBdt;
	bool leftHanded = true;
	bool letterFound = false;

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

	Point blueSmallestX;
	Point blueLargestX;
	Point blueSmallestY;
	Point blueLargestY;
	int blueDistanceX;
	Point blueCenter;

	Point greenSmallestX;
	Point greenLargestX;
	Point greenSmallestY;
	Point greenLargestY;
	Point greenCenter;

	Point pinkSmallestX;
	Point pinkLargestX;
	Point pinkSmallestY;
	Point pinkLargestY;
	Point pinkCenter;

	Point redSmallestX;
	Point redLargestX;
	Point redSmallestY;
	Point redLargestY;
	int redDistanceX;
	Point redCenter;

	Point yellowSmallestX;
	Point yellowLargestX;
	Point yellowSmallestY;
	Point yellowLargestY;
	Point yellowCenter;

	int errorAllowance = 10;
	int multiplier2 = 2;
	int multiplier = 3;

	vector<float> currentSign;
	vector<float> idealSign;

	float handRatio;

	float euclideanDistance;

	float lengthBlue;
	float lengthYelBlue;
	float lengthBlueYel;
	float lengthYelRed;
	float lengthBlueRed;
	float ratio;

	float lengthRedGreen;
	float lengthGreenPink;
	float lengthPinkBlue;
	float lengthPinkYel;
	float lengthGreenYel;
	float lengthRedPink;
	float lengthRedBlue;
	float lengthRedYel;
};

