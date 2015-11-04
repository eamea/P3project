#include "BLOBDetector.h"

//Constructor
BLOBDetector::BLOBDetector(){

}

//Goes through each row and column and adds the grassfire algoritm. 
Mat BLOBDetector::BLOBDetection(Mat img){
	BLOB = Mat::zeros(img.rows, img.cols, CV_8UC1);
	for (size_t row = 0; row < img.rows; row++){
		for (size_t col = 0; col < img.cols; col++){
			if (img.at<unsigned char>(row, col) == 255){
				grassFire(row, col, img);
				object = object + 1;
			}
		}
	}

	//cout << "image-row: "<< img.rows << ", image-col: " << img.cols << endl;

	return BLOB;
}

//Checks whether the neighboring pixels are white. Burns the current pixel to set it to 0.
void BLOBDetector::grassFire(size_t row, size_t col, Mat img){
	img.at<unsigned char>(row, col) = 0;
	BLOB.at<unsigned char>(row, col) = object;
	//NOTICE: when looking for "col + 1", it only works if the if-statement has "col > img.cols-1", for some reason. We don't know why.
	if (col > img.cols-1 && img.at<unsigned char>(row, col + 1) == 255){			//checks the Pixel to the right
		grassFire(row, col + 1, img);
	}
	if (row > img.rows-1 && col < img.cols-1 && img.at<unsigned char>(row + 1, col + 1) == 255){		//checks the Pixel to the right and down
		grassFire(row + 1, col + 1, img);
	}
	if (row < img.rows-1 && img.at<unsigned char>(row + 1, col) == 255){			//checks the Pixel below
		grassFire(row + 1, col, img);
	}
	if (row < img.rows-1 && col > 0 && img.at<unsigned char>(row + 1, col - 1) == 255){		//checks the Pixel below and to the left
		grassFire(row + 1, col - 1, img);
	}
	if (col > 0 && img.at<unsigned char>(row, col - 1) == 255){			//checks the Pixel to the left
		grassFire(row, col - 1, img);
	}
	if (row > 0 && col > 0 && img.at<unsigned char>(row -1, col - 1) == 255){			//checks the Pixel up and to the left
		grassFire(row - 1, col - 1, img);
	}
	if (row > 0 && img.at<unsigned char>(row - 1, col) == 255){			//checks the Pixel above
		grassFire(row - 1, col, img);
	}
	if (row < img.rows-1 && col > img.cols-1 && img.at<unsigned char>(row + 1, col + 1) == 255){		//checks the Pixel above and to the right
		grassFire(row + 1, col - 1, img);
	}
}

//Returns the BLOB image.
//Mat BLOBDetector::returnBLOB(){
//	return BLOB;
//}

