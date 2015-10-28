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
	void compareFeatures();//compares the features gained to the saved features for the letter
	bool letterFound();//return a boolean to check wether or not the letter has been found
private: 
	SimpleBlobDetector detector;//the detector we use to find BLOB's
	vector<KeyPoint> keypoint;//a vector list that allows us to save the keypoints of the BLOB's
	float savedFeature;//not sure if this will be floats, and it wil probably end up as several variable
	float extractedFeature;// same as above
	bool foundLetter; //the boolean we use to check if the letter is found
};

