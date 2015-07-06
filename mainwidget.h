#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "togglebutton.h"
#include "QtAwesome.h"

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
private:
    ToggleButton** btnGrid;
    QtAwesome* awesome;
    QPushButton* btnTimes;
    QPushButton* btnSolve;
};

#endif // MAINWIDGET_H
