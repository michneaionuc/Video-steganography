#pragma once

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void getStegoFrames(vector<Mat> inputFrames, vector<int> inputBitsMessage, vector<Mat>& outputFrames, char* key);

void getMessageFromStegoFrames(vector<Mat> stegoFrames, vector<vector<int>>& bitsMessage, char* key);
