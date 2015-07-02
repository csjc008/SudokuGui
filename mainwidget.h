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
public slots:
    void moveWindow(int x,int y);

private:
    ToggleButton** btnGrid;
    QtAwesome* awesome;
};

#endif // MAINWIDGET_H
