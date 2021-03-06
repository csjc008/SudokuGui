#-------------------------------------------------
#
# Project created by QtCreator 2015-07-01T13:33:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QSudoku
TEMPLATE = app

include(QtAwesome/QtAwesome.pri)

SOURCES += main.cpp\
        mainwidget.cpp \
    togglebutton.cpp \
    util.cpp \
    titlelabel.cpp \
    quadindex.cpp \
    minibrickset.cpp \
    brickset.cpp

HEADERS  += mainwidget.h \
    togglebutton.h \
    util.h \
    titlelabel.h \
    quadindex.h \
    minibrickset.h \
    brickset.h

RESOURCES += \
    resource.qrc

DISTFILES += \
    ToggleButton.txt \
    Header.txt \
    Times.txt \
    ToggleButton1.txt \
    ToggleButton2.txt \
    MainWidget.txt \
    BlueButton.txt \
    MessageLabel.txt
