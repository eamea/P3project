#include "BLOBDetector.h"


BLOBDetector::BLOBDetector(Mat thresImg){
	Mat img = thresImg;
}

void BLOBDetector::BLOBDetection(){
	for (size_t row = 0; row < img.row; row++){
		for (size_t col = 0; col < img.col; col++){
			if (img.at<unsigned char>(row, col) == 255){
				grassFire(row, col);
				BLOB = BLOB + 1;
			}
			
		}
	}
}

void BLOBDetector::grassFire(size_t row, size_t col){
	img.at<unsigned char>(row, col) = 0;
	BLOB.at<unsigned char>(row, col) = object;
	if (img.at<unsigned char>(row + 1, col) == 255){
		grassFire(row + 1, col);
	}
	if (img.at<unsigned char>(row + 1, col + 1) == 255){
		grassFire(row + 1, col + 1);
	}
	if (img.at<unsigned char>(row, col + 1) == 255){
		grassFire(row, col + 1);
	}
	if (img.at<unsigned char>(row - 1, col + 1) == 255){
		grassFire(row - 1, col + 1);
	}
	if (img.at<unsigned char>(row - 1, col) == 255){
		grassFire(row - 1, col);
	}
	if (img.at<unsigned char>(row -1, col - 1) == 255){
		grassFire(row - 1, col - 1);
	}
	if (img.at<unsigned char>(row, col - 1) == 255){
		grassFire(row, col - 1);
	}
	if (img.at<unsigned char>(row + 1, col - 1) == 255){
		grassFire(row + 1, col - 1);
	}
}

