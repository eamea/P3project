#include <iostream>
#include "opencv2/opencv.hpp"
#include "Detector.h"
#include "Recognizer.h"
#include "UIHandler.h"

using namespace std;
using namespace cv;

int main()
{
	Detector detector( 5); //instantiating a new Detector object called detector

	VideoCapture stream(0); //capturing a stream from webcam 0.

	Mat capturedFrame;		//a mat for holding the current frame
	Mat output;				//a mat for holding the processed frame

	detector.createTrackbars();	//creating a window called trackbar

	while (true){ //infinite loop for constant frame update.
		stream.read(capturedFrame);	//reading a frame from the stream

		output = detector.segmentFrame(capturedFrame); //processing the captured frame and putting it in output.

		imshow("Output", output);	//showing the processed image

		//Checks every 30 ms if 'esc'-key has been pressed by user. If true, break the loop.
		if (waitKey(30) == 27)
			break;
	}

	return 0;
}