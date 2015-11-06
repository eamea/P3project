#include "Recognizer.h"

//TODO Uses getters from main function to set the threshold images.
Recognizer::Recognizer(Detector d){
	dt = d;
}

Mat Recognizer::getBlueBLOBImg(){
	return BLOBBlueImg;
}

Mat Recognizer::getGreenBLOBImg(){
	return BLOBGreenImg;
}

Mat Recognizer::getRedBLOBImg(){
	return BLOBRedImg;
}

Mat Recognizer::getYellowBLOBImg(){
	return BLOBYellowImg;
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
		BLOBBlueImg = detector.BLOBDetection(dt.getBlueThreshImg(), 'b');
		BLOBYellowImg = detector.BLOBDetection(dt.getYellowThreshImg(), 'y');
		break;
	case 'b':
		BLOBRedImg = detector.BLOBDetection(dt.getRedThreshImg(), 'r');
		BLOBYellowImg = detector.BLOBDetection(dt.getYellowThreshImg(), 'y');
		break;
	case 'f':
		BLOBBlueImg = detector.BLOBDetection(dt.getBlueThreshImg(), 'b');
		BLOBGreenImg = detector.BLOBDetection(dt.getGreenThreshImg(), 'g');
		BLOBRedImg = detector.BLOBDetection(dt.getRedThreshImg(), 'r');
		BLOBYellowImg = detector.BLOBDetection(dt.getYellowThreshImg(), 'y');
		break;
	case 'l':
		BLOBBlueImg = detector.BLOBDetection(dt.getBlueThreshImg(), 'b');
		BLOBRedImg = detector.BLOBDetection(dt.getRedThreshImg(), 'r');
		BLOBYellowImg = detector.BLOBDetection(dt.getYellowThreshImg(), 'y');
		break;
	case 's':
		BLOBBlueImg = detector.BLOBDetection(dt.getBlueThreshImg(), 'b');
		BLOBYellowImg = detector.BLOBDetection(dt.getYellowThreshImg(), 'y');
		break;
	case 't':
		BLOBBlueImg = detector.BLOBDetection(dt.getBlueThreshImg(), 'b');
		BLOBYellowImg = detector.BLOBDetection(dt.getYellowThreshImg(), 'y');
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