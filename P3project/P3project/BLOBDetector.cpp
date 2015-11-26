#include "BLOBDetector.h"

BLOBDetector::BLOBDetector(){

}

//applies grassfire to img, and parses list of BLOBs to relevant color BLOBList
Mat BLOBDetector::BLOBDetection(Mat img, char color){
	BLOB = Mat::zeros(img.rows, img.cols, CV_8UC1);						//sets the default BLOB image to be a black, empty image

	switch (color){														//resets a BLOB image based on the color-char parsed
	case 'b':
		blueBLOBImg = Mat::zeros(img.rows, img.cols, CV_8UC1);
		break;
	case 'g':
		greenBLOBImg = Mat::zeros(img.rows, img.cols, CV_8UC1);
		break;
	case 'p':
		pinkBLOBImg = Mat::zeros(img.rows, img.cols, CV_8UC1);
		break;
	case 'r':
		redBLOBImg = Mat::zeros(img.rows, img.cols, CV_8UC1);
		break;
	case 'y':
		yellowBLOBImg = Mat::zeros(img.rows, img.cols, CV_8UC1);
		break;
	default:
		cout << "ERROR: BLOBDetection has not been parsed a valid color char." << endl;
		break;
	}

	BLOBList.empty();													//emptying and resizing the two vector lists
	BLOBList.resize(0);
	points.empty();
	points.resize(0);
	
	for (size_t row = 0; row < img.rows; row++){						//runs sequential grassfire algorithm on the image
		for (size_t col = 0; col < img.cols; col++){
			if (img.at<unsigned char>(row, col) == 255){
				seqGrassFire(row, col, img, color);					//call seqGrassFire on the first object pixel we hit
				while (!xCoor.empty() && !yCoor.empty()){				//as long as there are still pixels to check
					seqGrassFire(yCoor.front(), xCoor.front(), img, color); //call seqGrassFire on the first element in the lists
					
					Point point;										//converting the coordinates to a single point
					point.x = xCoor.front();							
					point.y = yCoor.front();

					points.push_back(point);							// pushing the point to the vector<Point>
					xCoor.pop_front();									//removing the elements from the lists
					yCoor.pop_front();
				}
				if (points.size() > BLOBsizeToFilterOut)				//filtering out blobs with less than 50 pixels in the lists of pixels
					BLOBList.push_back(points);							//pushing the vector points we've created to the contours
				
				object += 1;											//increasing label by 1
			}
		}
	}

	switch (color){														//returning the analyzed image and setting blob list
	case 'b':
		blueBLOBList.resize(0);
		blueBLOBList = BLOBList;
		return blueBLOBImg;
	case 'g':
		greenBLOBList = BLOBList;
		return greenBLOBImg;
	case 'p':
		pinkBLOBList = BLOBList;
		return pinkBLOBImg;
	case 'r':
		redBLOBList = BLOBList;
		return redBLOBImg;
	case 'y':
		yellowBLOBList.resize(0);
		yellowBLOBList = BLOBList;
		return yellowBLOBImg;
	default:
		cout << "ERROR: BLOBDetection has not been parsed a valid color char." << endl;
		return BLOB;
	}
}

//sequential grassfire algorithm
void BLOBDetector::seqGrassFire(size_t row, size_t col, Mat img, char color){
	img.at<uchar>(row, col) = 0;										//burns the current pixel
	objectPixelIn(row, col, color);										//setting the pixel in output image to an object pixel
	if (col < img.cols - 1){
		if (img.at<unsigned char>(row, col + 1) == 255){				//checks the pixel to the right
			img.at<uchar>(row, col + 1) = 0;							//burns the pixel in the input image
			objectPixelIn(row, col + 1, color);							//setting the pixel in output image to an object pixel
			yCoor.push_back(row);										//adding this pixel's x-coordinate to the end of the list
			xCoor.push_back(col+1);										//adding this pixel's y-coordinate to the end of the list
		}
	}
	if (row < img.rows - 1 && col < img.cols - 1){
		if (img.at<unsigned char>(row + 1, col + 1) == 255){			//checks the pixel to the right and down
			img.at<uchar>(row + 1, col + 1) = 0;
			objectPixelIn(row + 1, col + 1, color);
			yCoor.push_back(row + 1);
			xCoor.push_back(col + 1);
		}
	}
	if (row < img.rows - 1){
		if (img.at<unsigned char>(row + 1, col) == 255){				//checks the pixel below
			img.at<uchar>(row + 1, col) = 0;
			objectPixelIn(row + 1, col, color);
			yCoor.push_back(row + 1);
			xCoor.push_back(col);
		}
	}
	if (row < img.rows - 1 && col > 0){
		if (img.at<unsigned char>(row + 1, col - 1) == 255){			//checks the pixel below and to the left
			img.at<uchar>(row + 1, col - 1) = 0;
			objectPixelIn(row + 1, col - 1, color);
			yCoor.push_back(row + 1);
			xCoor.push_back(col - 1);
		}
	}
	if (col > 0){
		if (img.at<unsigned char>(row, col - 1) == 255){				//checks the pixel to the left
			img.at<uchar>(row, col - 1) = 0;
			objectPixelIn(row, col - 1, color);
			yCoor.push_back(row);
			xCoor.push_back(col - 1);
		}
	}
	if (row > 0 && col > 0){
		if (img.at<unsigned char>(row - 1, col - 1) == 255){			//checks the pixel up and to the left
			img.at<uchar>(row - 1, col - 1) = 0;
			objectPixelIn(row - 1, col - 1, color);
			yCoor.push_back(row - 1);
			xCoor.push_back(col - 1);
		}
	}
	if (row > 0){
		if (img.at<unsigned char>(row - 1, col) == 255){				//checks the pixel above
			img.at<uchar>(row - 1, col) = 0;
			objectPixelIn(row - 1, col, color);
			yCoor.push_back(row - 1);
			xCoor.push_back(col);
		}
	}
	if (row > 0 && col < img.cols - 1){
		if (img.at<unsigned char>(row - 1, col + 1) == 255){			//checks the pixel above and to the right
			img.at<uchar>(row - 1, col + 1) = 0;
			objectPixelIn(row - 1, col + 1, color);
			yCoor.push_back(row - 1);
			xCoor.push_back(col + 1);
		}
	}
}

//setting current pixel in relevant BLOBImg to the current object label value
void BLOBDetector::objectPixelIn(size_t row, size_t col, char color){
	switch (color){
	case 'b':
		blueBLOBImg.at<unsigned char>(row, col) = object;
		break;
	case 'g':
		greenBLOBImg.at<unsigned char>(row, col) = object;
		break;
	case 'p':
		pinkBLOBImg.at<unsigned char>(row, col) = object;
		break;
	case 'r':
		redBLOBImg.at<unsigned char>(row, col) = object;
		break;
	case 'y':
		yellowBLOBImg.at<unsigned char>(row, col) = object;
		break;
	default:
		break;
	}
}

//returns the BLOBList for the color parsed to the function
vector<vector<Point>> BLOBDetector::getBLOBList(char color){
	switch (color){
	case 'b':
		return blueBLOBList;
	case 'g':
		return greenBLOBList;
	case 'p':
		return pinkBLOBList;
	case 'r':
		return redBLOBList;
	case 'y':
		return yellowBLOBList;
	default:
		cout << "ERROR: getBLOBList has not been parsed a valid color char." << endl;
		return BLOBList;
	}
}