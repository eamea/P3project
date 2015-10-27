#include <iostream>
#include "opencv2/opencv.hpp"
#include "Detector.h"

using namespace std;
using namespace cv;

int main()
{
	Mat q;
	Detector dt();
	
	//q = dt.segmentFrame(q);
	//imshow("QQQ", q);

	//Detector dt(140, 5); //instantiating a new Detector object

	//VideoCapture stream(0);

	//Mat frame;
	//Mat output;

	//while (true){
	//	stream.read(frame);

	//	output = dt.segmentFrame(frame);

	//	imshow("Output", output);

	//	if (waitKey(30) == 27)
	//		break;
	//}

	waitKey(0);

	return 0;
}