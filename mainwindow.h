#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <opencv2/opencv.hpp>
#include <iostream>


using namespace std;
using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_upload_video_button_released();

    void on_upload_file_button_released();

    void on_save_video_button_released();

    void on_generate_video_button_released();

    void on_generate_video_button_pressed();

    void showSend();

    void showRecieve();

    void on_extract_message_button_released();

    void on_save_message_button_released();

    void on_extract_message_button_pressed();

private:
    Ui::MainWindow *ui;
    QString currentFile;
    QPushButton *upload_video_button;
    QString videoLocation;
    QString fileLocation;
    QString encryptionKey;
    QString stegoVideoLocation;
    vector<Mat> frames;
    vector<Mat> stegoFrames;
    unsigned char * extractedSecretMessage;
    double FPS;
};

#endif // MAINWINDOW_H
