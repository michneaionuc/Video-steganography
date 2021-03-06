#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

#include <opencv2/opencv.hpp>
#include <iostream>
#include "FrameProcessing.h"
#include "VideoProcessing.h"
#include "EncryptionAndDecryption.h"
#include "Steganography.h"
#include "Message.h"
#include <string.h>
#include <QThread>

using namespace std;
using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{    
    ui->setupUi(this);
    ui->recieveFrame->hide();
    connect(ui->actionSend, &QAction::triggered, this, &MainWindow::showSend);
    connect(ui->actionRecieve, &QAction::triggered, this, &MainWindow::showRecieve);
    this->setCentralWidget(ui->centralwidget);
    ui->label_status->setText(" ");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_upload_video_button_released()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->lineEditVideo->setText(fileName);
    this->videoLocation = fileName;
    file.close();
}


void MainWindow::on_upload_file_button_released()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->lineEditFile->setText(fileName);
    this->fileLocation = fileName;
    file.close();
}

//returns 1 if yes, 0 otherwise
long getMaximumNumberOfBits(vector<Mat> inputFrames) {
    long numberOfFrames = (long)inputFrames.size();
    long nrPixels = inputFrames[0].rows * inputFrames[0].cols;
    long maxNrOfMessageBitsInFrame = nrPixels * 3 + nrPixels * 2 * 2; //Y => 3 pixels, U => 2 pixels, V => 2 pixels
    long maxTotalNrOfMessageBits = numberOfFrames * maxNrOfMessageBitsInFrame;
    return maxTotalNrOfMessageBits;
}

void MainWindow::on_generate_video_button_released()
{
    ui->label_status->setText("Processing...");
    this->encryptionKey = ui->lineEditKey->text();

    string keyStr(this->encryptionKey.toStdString());
    char * key = &keyStr[0];

    string fileLocationStr(this->fileLocation.toStdString());
    char * fileLocation = &fileLocationStr[0];

    string videoLocationStr(this->videoLocation.toStdString());
    char * videoLocation = &videoLocationStr[0];

    extract_frames(videoLocation, this->frames);

    unsigned char * secretMEssage = getSecretMessageInBytes(fileLocation);
    if((strlen((char*)secretMEssage) * 8) <= getMaximumNumberOfBits(this->frames)) {
        vector<vector<int>> bits = secretMessageToArraysOfBits(secretMEssage);
        vector<int> permutedBits = permuteMessageBits(bits, key);

        getStegoFrames(this->frames, permutedBits,this->stegoFrames, key);
        VideoCapture cap(videoLocation);
        this->FPS = static_cast<int>(cap.get(CAP_PROP_FPS));
        ui->label_status->setText("Finished!");
    } else {
        ui->label_status->setText("File is too large!");
    }
}

void MainWindow::on_save_video_button_released()
{
    ui->label_status->setText("Saving video...");
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");

    // Get the width/height of the video frames
    int width = this->frames[0].cols;
    int height = this->frames[0].rows;

    string videoLocationStr(fileName.toStdString());

    char * stegoVideoLocation = &videoLocationStr[0];

    saveVideo(stegoVideoLocation, this->stegoFrames, this->FPS, width, height);
    ui->label_status->setText("Finished!");
}


void MainWindow::on_generate_video_button_pressed()
{
    ui->label_status->setText("Processing...");
}

void MainWindow::showSend() {
    ui->sendFrame->show();
    ui->recieveFrame->hide();
}

void MainWindow::showRecieve() {
    ui->sendFrame->hide();
    ui->recieveFrame->show();
}


void MainWindow::on_extract_message_button_released()
{
    ui->label_status->setText("Extracting the message...");
    QString encryptionKey2 = ui->lineEditKey2->text();

    vector<vector<int>> messageBits;

    string keyStr(encryptionKey2.toStdString());

    char * key = &keyStr[0];

    string videoLocationStr(this->videoLocation.toStdString());
    char * videoLocation = &videoLocationStr[0];
    extract_frames(videoLocation, this->stegoFrames);

    getMessageFromStegoFrames(this->stegoFrames, messageBits, key);

    this->extractedSecretMessage = arraysOfBitsToSecretMessage(permuteMessageBitsInverse(messageBits, key));
    QString size = QString::number(permuteMessageBitsInverse(messageBits, key).size());

    if(this->extractedSecretMessage[0] == '\0') {
        ui->label_status->setText("Wrong key!");
    } else {
        ui->label_status->setText("Finished!");
    }
}


void MainWindow::on_save_message_button_released()
{
    ui->label_status->setText("Saving the message...");
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");

    string messageLocationStr(fileName.toStdString());

    char * messageLocation = &messageLocationStr[0];

    saveSecretMessage(messageLocation, this->extractedSecretMessage);

    ui->label_status->setText("Finished!");
}

void MainWindow::on_extract_message_button_pressed()
{
    ui->label_status->setText("Extracting the message...");
}

