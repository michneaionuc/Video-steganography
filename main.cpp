#include "mainwindow.h"

#include <QApplication>
#include <opencv2/opencv.hpp>
#include <iostream>
#include "FrameProcessing.h"
#include "VideoProcessing.h"
#include "EncryptionAndDecryption.h"
#include "Steganography.h"
#include "Message.h"
#include <string.h>

using namespace std;
using namespace cv;

void doSteganography();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //doSteganography();
    MainWindow w;
    w.setWindowTitle("Video Steganography Software");
    w.show();
    return a.exec();
}

void doSteganography() {
    char fileLocation[] = "C:\\Steganography\\Resources\\file.txt";
    unsigned char * secretMEssage = getSecretMessageInBytes(fileLocation);

    char key[] = "password";

    vector<vector<int>> bits = secretMessageToArraysOfBits(secretMEssage);
    vector<int> permutedBits = permuteMessageBits(bits, key);

    vector<Mat> frames;
    vector<Mat> stegoFrames;
    vector<vector<int>> messageBits;

    extract_frames("C:\\Steganography\\Resources\\test.mp4", frames);

    getStegoFrames(frames, permutedBits, stegoFrames, key);

    getMessageFromStegoFrames(stegoFrames, messageBits, permutedBits.size(), key);

    unsigned char * extractedSecretMessage = arraysOfBitsToSecretMessage(permuteMessageBitsInverse(messageBits, key));

    char secretMessageFileName[] = "C:\\Steganography\\Resources\\secretmessage.txt";

    saveSecretMessage(secretMessageFileName, extractedSecretMessage);

    VideoCapture cap("C:\\Steganography\\Resources\\test.mp4");

    double FPS = static_cast<int>(cap.get(CAP_PROP_FPS));

    // Get the width/height of the video frames
    int width = stegoFrames[0].cols;
    int height = stegoFrames[0].rows;

    char videoLocation[] = "C:\\Steganography\\Resources\\output.mp4";

    saveVideo(videoLocation, frames, FPS, width, height);
}
