#include "Recognizer.h"

//TODO Uses getters from main function to set the threshold images.
Recognizer::Recognizer(Detector d){
	dt = d;
}

Mat Recognizer::getBlueBLOBImg(){
	return BLOBBlueImg;
}

Detector Recognizer::getDetector(){
	return dt;
}

void Recognizer::setDetector(Detector d){
	dt = d;
}

//BLOB analyzes the relevant threshimages based on the char input.
void Recognizer::BLOBAnalyze(char letter)
{
	switch (letter)
	{
	case 'a':
		//imshow("blue thresh from recognizer", dt.getBlueThreshImg());
		BLOBBlueImg = detector.BLOBDetection(dt.getBlueThreshImg());
		BLOBYellowImg = detector.BLOBDetection(dt.getYellowThreshImg());
		break;
	case 'b':
		BLOBRedImg = detector.BLOBDetection(dt.getRedThreshImg());
		BLOBYellowImg = detector.BLOBDetection(dt.getYellowThreshImg());
		break;
	case 'f':
		BLOBBlueImg = detector.BLOBDetection(dt.getBlueThreshImg());
		BLOBGreenImg = detector.BLOBDetection(dt.getGreenThreshImg());
		BLOBRedImg = detector.BLOBDetection(dt.getRedThreshImg());
		BLOBYellowImg = detector.BLOBDetection(dt.getYellowThreshImg());
		break;
	case 'l':
		BLOBBlueImg = detector.BLOBDetection(dt.getBlueThreshImg());
		BLOBRedImg = detector.BLOBDetection(dt.getRedThreshImg());
		BLOBYellowImg = detector.BLOBDetection(dt.getYellowThreshImg());
		break;
	case 's':
		BLOBBlueImg = detector.BLOBDetection(dt.getBlueThreshImg());
		BLOBYellowImg = detector.BLOBDetection(dt.getYellowThreshImg());
		break;
	case 't':
		BLOBBlueImg = detector.BLOBDetection(dt.getBlueThreshImg());
		BLOBYellowImg = detector.BLOBDetection(dt.getYellowThreshImg());
		break;
	}
}

void Recognizer::extractFeatures(char letter)
{

}

bool Recognizer::compareFeatures(char letter)
{
	return false;
}

//Runs the functions in order and returns a bool based on whether it found the sign for the input char.
bool Recognizer::recognize(char letter)
{
	BLOBAnalyze(letter);
	extractFeatures(letter);
	
	return compareFeatures(letter);
}