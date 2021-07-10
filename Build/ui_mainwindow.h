/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSend;
    QAction *actionRecieve;
    QWidget *centralwidget;
    QFrame *sendFrame;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_5;
    QPushButton *save_video_button;
    QLabel *label_2;
    QLineEdit *lineEditKey;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *upload_file_button;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QPushButton *generate_video_button;
    QLineEdit *lineEditFile;
    QLabel *label_status;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEditVideo;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *upload_video_button;
    QFrame *recieveFrame;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_6;
    QPushButton *save_message_button;
    QLabel *label_3;
    QLineEdit *lineEditKey2;
    QWidget *verticalLayoutWidget_8;
    QVBoxLayout *verticalLayout_8;
    QPushButton *extract_message_button;
    QMenuBar *menubar;
    QMenu *menuSend_or_recieve;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1033, 768);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
        actionSend = new QAction(MainWindow);
        actionSend->setObjectName(QString::fromUtf8("actionSend"));
        actionRecieve = new QAction(MainWindow);
        actionRecieve->setObjectName(QString::fromUtf8("actionRecieve"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sendFrame = new QFrame(centralwidget);
        sendFrame->setObjectName(QString::fromUtf8("sendFrame"));
        sendFrame->setGeometry(QRect(10, 200, 1041, 441));
        sendFrame->setFrameShape(QFrame::StyledPanel);
        sendFrame->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget_5 = new QWidget(sendFrame);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(10, 330, 1001, 90));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        save_video_button = new QPushButton(verticalLayoutWidget_5);
        save_video_button->setObjectName(QString::fromUtf8("save_video_button"));
        save_video_button->setStyleSheet(QString::fromUtf8("font: 15pt \"Papyrus\";\n"
"color: \"black\";"));

        verticalLayout_5->addWidget(save_video_button);

        label_2 = new QLabel(sendFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 130, 471, 71));
        label_2->setStyleSheet(QString::fromUtf8("font: 15pt \"Papyrus\";\n"
"color: \"black\";"));
        label_2->setAlignment(Qt::AlignCenter);
        lineEditKey = new QLineEdit(sendFrame);
        lineEditKey->setObjectName(QString::fromUtf8("lineEditKey"));
        lineEditKey->setGeometry(QRect(510, 150, 501, 41));
        lineEditKey->setStyleSheet(QString::fromUtf8(""));
        verticalLayoutWidget_3 = new QWidget(sendFrame);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(10, 20, 481, 80));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        upload_file_button = new QPushButton(verticalLayoutWidget_3);
        upload_file_button->setObjectName(QString::fromUtf8("upload_file_button"));
        upload_file_button->setStyleSheet(QString::fromUtf8("font: 15pt \"Papyrus\";\n"
"color: \"black\";"));

        verticalLayout_3->addWidget(upload_file_button);

        verticalLayoutWidget_4 = new QWidget(sendFrame);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 230, 1001, 80));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        generate_video_button = new QPushButton(verticalLayoutWidget_4);
        generate_video_button->setObjectName(QString::fromUtf8("generate_video_button"));
        generate_video_button->setStyleSheet(QString::fromUtf8("font: 15pt \"Papyrus\";\n"
"color: \"black\";"));

        verticalLayout_4->addWidget(generate_video_button);

        lineEditFile = new QLineEdit(sendFrame);
        lineEditFile->setObjectName(QString::fromUtf8("lineEditFile"));
        lineEditFile->setGeometry(QRect(510, 40, 501, 41));
        lineEditFile->setStyleSheet(QString::fromUtf8(""));
        label_status = new QLabel(centralwidget);
        label_status->setObjectName(QString::fromUtf8("label_status"));
        label_status->setGeometry(QRect(20, 630, 1001, 51));
        label_status->setStyleSheet(QString::fromUtf8("font: 15pt \"Papyrus\";\n"
"color: \"black\";"));
        label_status->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 20, 1031, 71));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"Papyrus\";\n"
"color: \"black\";"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        lineEditVideo = new QLineEdit(centralwidget);
        lineEditVideo->setObjectName(QString::fromUtf8("lineEditVideo"));
        lineEditVideo->setGeometry(QRect(520, 130, 501, 41));
        lineEditVideo->setStyleSheet(QString::fromUtf8(""));
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(20, 110, 481, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        upload_video_button = new QPushButton(verticalLayoutWidget_2);
        upload_video_button->setObjectName(QString::fromUtf8("upload_video_button"));
        upload_video_button->setStyleSheet(QString::fromUtf8("font: 15pt \"Papyrus\";\n"
"color: \"black\";"));

        verticalLayout_2->addWidget(upload_video_button);

        recieveFrame = new QFrame(centralwidget);
        recieveFrame->setObjectName(QString::fromUtf8("recieveFrame"));
        recieveFrame->setGeometry(QRect(10, 200, 1041, 441));
        recieveFrame->setStyleSheet(QString::fromUtf8(""));
        recieveFrame->setFrameShape(QFrame::StyledPanel);
        recieveFrame->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget_6 = new QWidget(recieveFrame);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(10, 290, 1001, 90));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        save_message_button = new QPushButton(verticalLayoutWidget_6);
        save_message_button->setObjectName(QString::fromUtf8("save_message_button"));
        save_message_button->setStyleSheet(QString::fromUtf8("font: 15pt \"Papyrus\";\n"
"color: \"black\";"));

        verticalLayout_6->addWidget(save_message_button);

        label_3 = new QLabel(recieveFrame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 40, 471, 71));
        label_3->setStyleSheet(QString::fromUtf8("font: 12pt \"Papyrus\";\n"
"color: \"black\";"));
        label_3->setAlignment(Qt::AlignCenter);
        lineEditKey2 = new QLineEdit(recieveFrame);
        lineEditKey2->setObjectName(QString::fromUtf8("lineEditKey2"));
        lineEditKey2->setGeometry(QRect(510, 60, 501, 41));
        lineEditKey2->setStyleSheet(QString::fromUtf8(""));
        verticalLayoutWidget_8 = new QWidget(recieveFrame);
        verticalLayoutWidget_8->setObjectName(QString::fromUtf8("verticalLayoutWidget_8"));
        verticalLayoutWidget_8->setGeometry(QRect(10, 160, 1001, 80));
        verticalLayout_8 = new QVBoxLayout(verticalLayoutWidget_8);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        extract_message_button = new QPushButton(verticalLayoutWidget_8);
        extract_message_button->setObjectName(QString::fromUtf8("extract_message_button"));
        extract_message_button->setStyleSheet(QString::fromUtf8("font: 15pt \"Papyrus\";\n"
"color: \"black\";"));

        verticalLayout_8->addWidget(extract_message_button);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1033, 24));
        menuSend_or_recieve = new QMenu(menubar);
        menuSend_or_recieve->setObjectName(QString::fromUtf8("menuSend_or_recieve"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSend_or_recieve->menuAction());
        menuSend_or_recieve->addSeparator();
        menuSend_or_recieve->addAction(actionSend);
        menuSend_or_recieve->addAction(actionRecieve);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSend->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        actionRecieve->setText(QCoreApplication::translate("MainWindow", "Recieve", nullptr));
        save_video_button->setText(QCoreApplication::translate("MainWindow", "Save the video", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Enter an encryption key:", nullptr));
        upload_file_button->setText(QCoreApplication::translate("MainWindow", "Upload a txt file", nullptr));
        generate_video_button->setText(QCoreApplication::translate("MainWindow", "Generate video", nullptr));
        label_status->setText(QCoreApplication::translate("MainWindow", "Processing...", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Video Steganography", nullptr));
        upload_video_button->setText(QCoreApplication::translate("MainWindow", "Upload video", nullptr));
        save_message_button->setText(QCoreApplication::translate("MainWindow", "Save the message", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Enter the decryption key:", nullptr));
        extract_message_button->setText(QCoreApplication::translate("MainWindow", "Extract message", nullptr));
        menuSend_or_recieve->setTitle(QCoreApplication::translate("MainWindow", "Send or recieve?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
