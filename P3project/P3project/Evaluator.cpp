#include "Evaluator.h"

Evaluator::Evaluator(){
}

//start the timer for the parsed char
void Evaluator::startTimer(char letter, Mat img){
	currentLetter = letter;											//saving parsed char
	timerHasStarted = true;											//"starting" timer
	startTime = clock();											//check the current clock_tic and set startTime as this
	videoWriter.open("C:/Users/Patrick/Desktop/5seconds.avi", CV_FOURCC('M', 'J', 'P', 'G'), 5, Size(img.cols, img.rows), true); //the videoWriter opens the specified file, descripes the type each frame is, decides the frame reate, declares the size of the video, and wether or not it's a colour picture
}

//stop the timer and write to the file with the parsed name
void Evaluator::stopTimer(string str){
	filename = str;													//saving the parsed string
	endTime = clock();												//check the current clock_tic and set stopTime as this

	clockTicsTaken = endTime - startTime;							//calculating clockTicsTaken
	timeInSeconds = clockTicsTaken / (double)CLOCKS_PER_SEC;		//calculating time taken in seconds

	writeToFile(filename);											//writing to the specified text file

	timerHasStarted = false;										//"stopping" the timer

	videoWriter.release();
}

//writing to the specified file
void Evaluator::writeToFile(string filename){
	outputFile.open(filename);										//"opening" the text file
	dataToSend << "\nSign '" << currentLetter << "': clockTicsTaken = " << clockTicsTaken << ". timeInSeconds = " << timeInSeconds << ". euclideanDistance = " << euclideanDistance << ".";	//creating a string to send to the file
	outputFile << dataToSend.str();									//sending the created string to the file
	outputFile.close();												//"closing" the text file
}

//save videoStream to file
void Evaluator::saveVideo(Mat img){									
		videoWriter.write(img);										//save the frame to the videoWriter
}

//set euclidean distance 
void Evaluator::setEuclideanDistance(float eud){
	euclideanDistance = eud;
}

//get the bool timerHasStarted
bool Evaluator::getTimerHasStarted(){
	return timerHasStarted;
}