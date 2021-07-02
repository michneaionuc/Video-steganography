QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    EncryptionAndDecryption.cpp \
    FrameProcessing.cpp \
    Message.cpp \
    Steganography.cpp \
    VideoProcessing.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    EncryptionAndDecryption.h \
    FrameProcessing.h \
    Message.h \
    Steganography.h \
    VideoProcessing.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

CONFIG += lrelease

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#========================  Include openCV libraries ===========================================
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Software/opencv/build/x64/vc14/lib/ -lopencv_world452
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Software/opencv/build/x64/vc14/lib/ -lopencv_world452d
else:unix: LIBS += -L$$PWD/../Software/opencv/build/x64/vc14/lib/ -lopencv_world452

INCLUDEPATH += $$PWD/../Software/opencv/build/include
DEPENDPATH += $$PWD/../Software/opencv/build/include
