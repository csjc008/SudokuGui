#ifndef OUTTERWIDGET_H
#define OUTTERWIDGET_H
#include "mainwidget.h"
#include <QWidget>

class OutterWidget:public QWidget
{
public:
    OutterWidget(QWidget * parent = 0);
private:
    MainWidget *w;
};

#endif // OUTTERWIDGET_H
