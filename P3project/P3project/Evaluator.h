#pragma once
#include <string>
#include <iostream>
#include <ctime>
#include <sstream>
#include <fstream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

class Evaluator
{
public:
	Evaluator();
	void startTimer(char letter, Mat img);		//start the timer for the parsed char
	void stopTimer(string filename);			//stop the timer and write to the file with the parsed name
	void saveVideo(Mat img);					//Saves the current frame to a videoWriter
	void setEuclideanDistance(float eud);		//set euclidean distance 
	bool getTimerHasStarted();					//get the bool timerHasStarted
private:
	void writeToFile(string filename);			//writing to the specified file

	char currentLetter;							//the letter we're currently writing data for
	stringstream dataToSend;					//a string-stream to send the data as a string to the text file
	ofstream outputFile;						//the file to send to
	string filename;							//name of the file to write to
	clock_t startTime;							//the time that startTimer(char) was called
	clock_t endTime;							//the time that stopTimer(string) was called
	clock_t clockTicsTaken;						//the time taken in clock tics (a constant but system specific unit of time)
	double timeInSeconds;						//the time taken in seconds
	float euclideanDistance;					//the euclidean distance between the registered hand sign and the ideal hand sign
	bool timerHasStarted = false;				//bool to check whether the timer is running or not
	VideoWriter videoWriter;					//creates a videoWriter which allowes us to save an image to a file

};


/*clock_t startTime = clock();
doSomeOperation();
clock_t endTime = clock();
clock_t clockTicksTaken = endTime - startTime;
double timeInSeconds = clockTicksTaken / (double)CLOCKS_PER_SEC;*/

