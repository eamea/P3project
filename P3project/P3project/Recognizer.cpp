#include "Recognizer.h"

//TODO Uses getters from main function to set the threshold images.
Recognizer::Recognizer(){
	//blueThreshImg = getBlueThreshImg();
	//greenThreshImg = getGreenThreshImg();
	////pinkThreshImg = getPinkThreshImg();
	//redThreshImg = getRedThreshImg();
	//yellowThreshImg = getYellowThreshImg();
}

//BLOB analyzes the relevant threshimages based on the char input.
void Recognizer::BLOBAnalyze(char x)
{
	switch (x)
	{
	case 'a':
		BLOBBlueImg = detector.BLOBDetection(blueThreshImg);
		BLOBYellowImg = detector.BLOBDetection(yellowThreshImg);
		break;
	case 'b':
		BLOBRedImg = detector.BLOBDetection(redThreshImg);
		BLOBYellowImg = detector.BLOBDetection(yellowThreshImg);
		break;
	case 'f':
		BLOBBlueImg = detector.BLOBDetection(blueThreshImg);
		BLOBGreenImg = detector.BLOBDetection(greenThreshImg);
		BLOBRedImg = detector.BLOBDetection(redThreshImg);
		BLOBYellowImg = detector.BLOBDetection(yellowThreshImg);
		break;
	case 'l':
		BLOBBlueImg = detector.BLOBDetection(blueThreshImg);
		BLOBRedImg = detector.BLOBDetection(redThreshImg);
		BLOBYellowImg = detector.BLOBDetection(yellowThreshImg);
		break;
	case 's':
		BLOBBlueImg = detector.BLOBDetection(blueThreshImg);
		BLOBYellowImg = detector.BLOBDetection(yellowThreshImg);
		break;
	case 't':
		BLOBBlueImg = detector.BLOBDetection(blueThreshImg);
		BLOBYellowImg = detector.BLOBDetection(yellowThreshImg);
		break;
	}
}

void Recognizer::extractFeatures(char x)
{

}

bool Recognizer::compareFeatures(char x)
{

}

//Runs the functions in order and returns a bool based on whether it found the sign for the input char.
bool Recognizer::recognize(char x)
{
	BLOBAnalyze(x);
	extractFeatures(x);
	
	return compareFeatures(x);
	
}