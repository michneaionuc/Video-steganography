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
    MainWindow w;
    w.setWindowTitle("Video Steganography Software");
    w.show();
    return a.exec();
}
