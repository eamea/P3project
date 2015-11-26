#pragma once
#include <string>
#include <iostream>
#include <ctime>
#include <sstream>
#include <fstream>

using namespace std;

class Evaluator
{
public:
	Evaluator();
	void startTimer(char letter);
	void stopTimer(string filename);
	void setEuclideanDistance(float eud);
private:
	void writeToFile(string filename);

	char currentLetter;
	stringstream dataToSend;
	ofstream outputFile;
	string filename;
	clock_t startTime;
	clock_t endTime;
	clock_t clockTicsTaken;
	double timeInSeconds;
	float euclideanDistance;

};


/*clock_t startTime = clock();
doSomeOperation();
clock_t endTime = clock();
clock_t clockTicksTaken = endTime - startTime;
double timeInSeconds = clockTicksTaken / (double)CLOCKS_PER_SEC;*/

