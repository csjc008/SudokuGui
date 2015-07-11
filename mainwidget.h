#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "togglebutton.h"
#include "QtAwesome.h"
#include <QLabel>
#include "brickset.h"

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
    void setAwesome(QtAwesome* _as);
    QPushButton *getQuitButton();
public slots:
    void moveWindow(int x,int y);
    void quitApp();
    void pressNumber(int x, int y);
    void solveSudoku();
    void reset();
private:
    ToggleButton** btnGrid;
    QtAwesome* awesome;
    QPushButton* btnTimes;
    QPushButton* btnSolve;
    QPushButton* btnReset;
    int curx,cury;
    QLabel* txtStatus;
    bool done;
};

#endif // MAINWIDGET_H
