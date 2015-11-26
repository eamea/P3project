#include "Evaluator.h"

Evaluator::Evaluator(){
}

void Evaluator::setEuclideanDistance(float eud){
	euclideanDistance = eud;
}


void Evaluator::startTimer(char letter){
	currentLetter = letter;
	startTime = clock();
}


void Evaluator::stopTimer(string str){
	filename = str;
	endTime = clock();

	clockTicsTaken = endTime - startTime;
	timeInSeconds = clockTicsTaken / (double)CLOCKS_PER_SEC;


	writeToFile(filename);
}

void Evaluator::writeToFile(string filename){
	outputFile.open(filename);
	dataToSend << "\nSign '" << currentLetter << "': clockTicsTaken = " << clockTicsTaken << ". timeInSeconds = " << timeInSeconds << ". euclideanDistance = " << euclideanDistance << ".";
	outputFile << dataToSend.str();
	outputFile.close();
}


/*clock_t startTime = clock();
doSomeOperation();
clock_t endTime = clock();
clock_t clockTicksTaken = endTime - startTime;
double timeInSeconds = clockTicksTaken / (double)CLOCKS_PER_SEC;*/