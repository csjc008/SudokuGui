#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "togglebutton.h"

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
public slots:
    void moveWindow(int x,int y);

private:
    ToggleButton** btnGrid;
};

#endif // MAINWIDGET_H
