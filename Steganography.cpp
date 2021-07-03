#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <sstream>
#include "FrameProcessing.h"
#include "VideoProcessing.h"
#include "Message.h"
#include "EncryptionAndDecryption.h"

using namespace std;
using namespace cv;

vector<int> decToBinary(int numberOfBits, int numberOfBitsToBeRepresentedOn);

int binaryToDecimal(vector<int> n);

//returns 1 if yes, 0 otherwise
long getMaximumNumberOfBits(vector<Mat> inputFrames) {
    long numberOfFrames = (long)inputFrames.size();
    long nrPixels = inputFrames[0].rows * inputFrames[0].cols;
    long maxNrOfMessageBitsInFrame = nrPixels * 3 + nrPixels * 2 * 2; //Y => 3 pixels, U => 2 pixels, V => 2 pixels
    long maxTotalNrOfMessageBits = numberOfFrames * maxNrOfMessageBitsInFrame;
    return maxTotalNrOfMessageBits;
}

void getStegoFrames(vector<Mat> inputFrames, vector<int> message, vector<Mat>& outputFrames, char * key) {
    long maxNrOfBits = getMaximumNumberOfBits(inputFrames);
    std::vector<int> inputBitsMessage(decToBinary(message.size(), 50));
    inputBitsMessage.insert(inputBitsMessage.end(), message.begin(), message.end());
    if (inputBitsMessage.size() <= maxNrOfBits) {
        int messageFinished = 0;
        //Split frame into 3 channels (R, G, B)
        //permute pixels in each channel
        for (int i = 0; i < inputFrames.size(); i++) {
            vector<Mat> frameChannels = splitFrameChannels(inputFrames[i]);
            Mat permutedY = permuteFramePixels(frameChannels[0], key);
            Mat permutedU = permuteFramePixels(frameChannels[1], key);
            Mat permutedV = permuteFramePixels(frameChannels[2], key);

            for (int row = 0; row < permutedY.rows && messageFinished == 0; row++) {
                for (int col = 0; col < permutedY.cols && messageFinished == 0; col++) {
                    vector<int> currentYPixelValue = unsignedchar2bits(permutedY.at<uchar>(row, col));
                    vector<int> currentUPixelValue = unsignedchar2bits(permutedU.at<uchar>(row, col));
                    vector<int> currentVPixelValue = unsignedchar2bits(permutedV.at<uchar>(row, col));

                    for (int bit = 5; bit < 8 && messageFinished == 0; bit++) {
                        if (inputBitsMessage.size() > 0) {
                            currentYPixelValue.at(bit) = inputBitsMessage.front();
                            inputBitsMessage.erase(inputBitsMessage.begin());
                        }
                        else {
                            messageFinished = 1;
                        }
                    }
                    for (int bit = 6; bit < 8 && messageFinished == 0; bit++) {
                        if (inputBitsMessage.size() > 0) {
                            currentUPixelValue.at(bit) = inputBitsMessage.front();
                            inputBitsMessage.erase(inputBitsMessage.begin());
                        }
                        else {
                            messageFinished = 1;
                        }
                    }
                    for (int bit = 6; bit < 8 && messageFinished == 0; bit++) {
                        if (inputBitsMessage.size() > 0) {
                            currentVPixelValue.at(bit) = inputBitsMessage.front();
                            inputBitsMessage.erase(inputBitsMessage.begin());
                        }
                        else {
                            messageFinished = 1;
                        }
                    }
                    unsigned char newYPixelValue = bits2unsignedchar(currentYPixelValue);
                    permutedY.at<uchar>(row, col) = newYPixelValue;

                    unsigned char newUPixelValue = bits2unsignedchar(currentUPixelValue);
                    permutedU.at<uchar>(row, col) = newUPixelValue;

                    unsigned char newVPixelValue = bits2unsignedchar(currentVPixelValue);
                    permutedV.at<uchar>(row, col) = newVPixelValue;
                }
            }

            Mat permutedYInverse = permuteFramePixelsInverse(permutedY, key);
            Mat permutedUInverse = permuteFramePixelsInverse(permutedU, key);
            Mat permutedVInverse = permuteFramePixelsInverse(permutedV, key);
            vector<Mat> channels = { permutedYInverse, permutedUInverse, permutedVInverse };
            Mat mergedChannels = mergeFrameChannels(channels);
            outputFrames.push_back(mergedChannels);
        }
    }
    else {
        cout << "\nThe file is to large! Select either a larger video or a smaller file!\n";
    }
}

vector<int> getNumberOfMessageBits(vector<Mat> stegoFrames, char* key) {
    int currNrBits = 50;
    vector<int> nrBits;
    for (int i = 0; i < stegoFrames.size() && currNrBits > 0; i++) {
        vector<Mat> frameChannels = splitFrameChannels(stegoFrames[i]);
        Mat permutedY = permuteFramePixels(frameChannels[0], key);
        Mat permutedU = permuteFramePixels(frameChannels[1], key);
        Mat permutedV = permuteFramePixels(frameChannels[2], key);

        for (int row = 0; row < permutedY.rows && currNrBits > 0; row++) {
            for (int col = 0; col < permutedY.cols && currNrBits > 0; col++) {
                vector<int> currentYPixelValue = unsignedchar2bits(permutedY.at<uchar>(row, col));
                vector<int> currentUPixelValue = unsignedchar2bits(permutedU.at<uchar>(row, col));
                vector<int> currentVPixelValue = unsignedchar2bits(permutedV.at<uchar>(row, col));

                for (int bit = 5; bit < 8 && currNrBits > 0; bit++) {
                    nrBits.push_back(currentYPixelValue.at(bit));
                    currNrBits--;
                }

                for (int bit = 6; bit < 8 && currNrBits > 0; bit++) {
                    nrBits.push_back(currentUPixelValue.at(bit));
                    currNrBits--;
                }
                for (int bit = 6; bit < 8 && currNrBits > 0; bit++) {
                    nrBits.push_back(currentVPixelValue.at(bit));
                    currNrBits--;
                }
            }
        }
    }

    return nrBits;
}

void getMessageFromStegoFrames(vector<Mat> stegoFrames, vector<vector<int>>& bitsMessage, char* key) {
    vector<int> byte;
    int currNrBits = binaryToDecimal(getNumberOfMessageBits(stegoFrames, key)) + 50;
    int count = 0;
    //Split frame into 3 channels (R, G, B)
    //permute pixels in each channel
    for (int i = 0; i < stegoFrames.size() && currNrBits > 0; i++) {
        vector<Mat> frameChannels = splitFrameChannels(stegoFrames[i]);
        Mat permutedY = permuteFramePixels(frameChannels[0], key);
        Mat permutedU = permuteFramePixels(frameChannels[1], key);
        Mat permutedV = permuteFramePixels(frameChannels[2], key);

        for (int row = 0; row < permutedY.rows && currNrBits > 0; row++) {
            for (int col = 0; col < permutedY.cols && currNrBits > 0; col++) {
                vector<int> currentYPixelValue = unsignedchar2bits(permutedY.at<uchar>(row, col));
                vector<int> currentUPixelValue = unsignedchar2bits(permutedU.at<uchar>(row, col));
                vector<int> currentVPixelValue = unsignedchar2bits(permutedV.at<uchar>(row, col));

                for (int bit = 5; bit < 8 && currNrBits > 0; bit++) {
                    if (byte.size() == 8) {
                        bitsMessage.push_back(byte);
                        byte.clear();
                    }
                    if(count++ >= 50) {
                        byte.push_back(currentYPixelValue.at(bit));
                    }
                    currNrBits--;
                }

                for (int bit = 6; bit < 8 && currNrBits > 0; bit++) {
                    if (byte.size() == 8) {
                        bitsMessage.push_back(byte);
                        byte.clear();
                    }
                    if(count++ >= 50) {
                        byte.push_back(currentUPixelValue.at(bit));
                    }
                    currNrBits--;
                }
                for (int bit = 6; bit < 8 && currNrBits > 0; bit++) {
                    if (byte.size() == 8) {
                        bitsMessage.push_back(byte);
                        byte.clear();
                    }
                    if(count++ >= 50) {
                        byte.push_back(currentVPixelValue.at(bit));
                    }
                    currNrBits--;
                }
            }
        }
    }
}

vector<int> decToBinary(int decimalNumber, int numberOfBitsToBeRepresentedOn)
{
    std::vector<int> binaryNum(numberOfBitsToBeRepresentedOn, 0);

    int i = numberOfBitsToBeRepresentedOn - 1;
    int n = decimalNumber;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i--;
    }

    return binaryNum;
}

int binaryToDecimal(vector<int> n)
{
    int decimal = 0 ;
    for(int i = 0; i < n.size(); i++) {
        decimal = decimal << 1 | n[i];
    }
    return decimal;
}
