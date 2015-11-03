#include <iostream>
#include "opencv2/opencv.hpp"
#include "Detector.h"
#include "Recognizer.h"
#include "UIHandler.h"
#include "BLOBDetector.h"

using namespace std;
using namespace cv;

//Creating a Matrix to hold the thresholded images
Mat blueThreshImg;
Mat greenThreshImg;
//Mat pinkThreshImg; //this one is outcommented because its not used
Mat redThreshImg;
Mat yellowThreshImg;

//Getter functions for each thresholded image
Mat getBlueThreshImg(){
	return blueThreshImg;
}

Mat getGreenThreshImg(){
	return greenThreshImg;
}

/* Pink is not used 
Mat getPinkThreshImg(){
	return pinkThreshImg;
}
*/

Mat getRedThreshImg(){
	return redThreshImg;
}

Mat getYellowThreshImg(){
	return yellowThreshImg;
}


int main()
{
	Detector detector(5); //instantiating a new Detector object called detector
	Recognizer recognizer(); //instantiating a new Recognizer object called recognizer

	VideoCapture stream(0); //capturing a stream from webcam 0.

	Mat capturedFrame;		//a mat for holding the current frame
	Mat output;				//a mat for holding the processed frame

	//detector.setThreshold('y'); //setting threshold values to threshold blue

	//detector.createTrackbars();	//creating a window called trackbar

	while (true){ //infinite loop for constant frame update.
		stream.read(capturedFrame);	//reading a frame from the stream

		//thresholding for the color and saving it in the respective matrix
		detector.setThreshold('b');
		blueThreshImg = detector.segmentFrame(capturedFrame);

		detector.setThreshold('g');
		greenThreshImg = detector.segmentFrame(capturedFrame);

		/*detector.setThreshold('p');
		pinkThreshImg = detector.segmentFrame(capturedFrame);*/

		detector.setThreshold('r');
		redThreshImg = detector.segmentFrame(capturedFrame);

		detector.setThreshold('y');
		yellowThreshImg = detector.segmentFrame(capturedFrame);

		//output = detector.segmentFrame(capturedFrame); //processing the captured frame and putting it in output.

		/*imshow("Blue", blueThreshImg);
		imshow("Green", greenThreshImg);
		imshow("Red", redThreshImg);
		imshow("Yellow", yellowThreshImg);*/
		//imshow("Output", output);	//showing the processed image

		//Checks every 30 ms if 'esc'-key has been pressed by user. If true, break the loop.
		if (waitKey(30) == 27)
			break;
	}

	return 0;
}