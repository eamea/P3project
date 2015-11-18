#include "Recognizer.h"

//When declaring a recognizer, tell it which detector to use (a.k.a. which thresholdImages to use)
Recognizer::Recognizer(Detector d){
	dt = d;
}

Mat Recognizer::getBlueBLOBImg(){
	return blueBLOBImg;
}
Mat Recognizer::getGreenBLOBImg(){
	return greenBLOBImg;
}
Mat Recognizer::getRedBLOBImg(){
	return redBLOBImg;
}
Mat Recognizer::getYellowBLOBImg(){
	return yellowBLOBImg;
}

Detector Recognizer::getDetector(){
	return dt;
}
void Recognizer::setDetector(Detector d){
	dt = d;
}

//BLOB analyzes the relevant threshimages based on the char input.
void Recognizer::BLOBAnalyze(char letter) {
	switch (letter) {
	case 'a':
		blueBLOBImg = BLOBdt.BLOBDetection(dt.getBlueThreshImg(), 'b');
		yellowBLOBImg = BLOBdt.BLOBDetection(dt.getYellowThreshImg(), 'y');
		break;
	case 'b':
		redBLOBImg = BLOBdt.BLOBDetection(dt.getRedThreshImg(), 'r');
		yellowBLOBImg = BLOBdt.BLOBDetection(dt.getYellowThreshImg(), 'y');
		break;
	case 'f':
		blueBLOBImg = BLOBdt.BLOBDetection(dt.getBlueThreshImg(), 'b');
		greenBLOBImg = BLOBdt.BLOBDetection(dt.getGreenThreshImg(), 'g');
		redBLOBImg = BLOBdt.BLOBDetection(dt.getRedThreshImg(), 'r');
		yellowBLOBImg = BLOBdt.BLOBDetection(dt.getYellowThreshImg(), 'y');
		break;
	case 'l':
		blueBLOBImg = BLOBdt.BLOBDetection(dt.getBlueThreshImg(), 'b');
		redBLOBImg = BLOBdt.BLOBDetection(dt.getRedThreshImg(), 'r');
		yellowBLOBImg = BLOBdt.BLOBDetection(dt.getYellowThreshImg(), 'y');
		break;
	case 's':
		blueBLOBImg = BLOBdt.BLOBDetection(dt.getBlueThreshImg(), 'b');
		yellowBLOBImg = BLOBdt.BLOBDetection(dt.getYellowThreshImg(), 'y');
		break;
	case 't':
		blueBLOBImg = BLOBdt.BLOBDetection(dt.getBlueThreshImg(), 'b');
		yellowBLOBImg = BLOBdt.BLOBDetection(dt.getYellowThreshImg(), 'y');
		break;
	default:
		cout << "ERROR: Recognizer has not been parsed a valid char in BLOBAnalyze." << endl;
		break;
	}
}

//TODO
void Recognizer::extractFeatures(char letter){
	switch (letter){
	case 'a':
		blueBLOBList = BLOBdt.getBLOBList('b');
		yellowBLOBList = BLOBdt.getBLOBList('y');


		break;
	case 'b':
		redBLOBList = BLOBdt.getBLOBList('r');
		yellowBLOBList = BLOBdt.getBLOBList('y');
		break;
	case 'f':
		blueBLOBList = BLOBdt.getBLOBList('b');
		greenBLOBList = BLOBdt.getBLOBList('g');
		redBLOBList = BLOBdt.getBLOBList('r');
		yellowBLOBList = BLOBdt.getBLOBList('y');
		break;
	case 'l':
		blueBLOBList = BLOBdt.getBLOBList('b');
		redBLOBList = BLOBdt.getBLOBList('r');
		yellowBLOBList = BLOBdt.getBLOBList('y');
		break;
	case 's':
		blueBLOBList = BLOBdt.getBLOBList('b');
		yellowBLOBList = BLOBdt.getBLOBList('y');
		break;
	case 't':
		blueBLOBList = BLOBdt.getBLOBList('b');
		yellowBLOBList = BLOBdt.getBLOBList('y');
		break;
	}
}

//TODO
bool Recognizer::compareFeatures(char letter){
	return false;
}

//Runs the functions in order and returns a bool based on whether it found the sign for the input char.
bool Recognizer::recognize(char letter){
	BLOBAnalyze(letter);
	extractFeatures(letter);
	
	return compareFeatures(letter);
}