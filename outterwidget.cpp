#include "outterwidget.h"
#include <QVBoxLayout>

OutterWidget::OutterWidget(QWidget *parent):QWidget(parent){
    this->w=new MainWidget();
    QVBoxLayout *layout=new QVBoxLayout();
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(w);
    this->setLayout(layout);
    this->setWindowFlags( Qt::FramelessWindowHint);
}
