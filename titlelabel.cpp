#include "titlelabel.h"
#include "util.h"
#include <QPoint>
#include <QPointF>
#include <QtDebug>

TitleLabel::TitleLabel(QWidget *parent):QLabel(parent){
    this->setStyleSheet(Util::getStringFromResource(":/style/Header.txt"));
}

void TitleLabel::mousePressEvent(QMouseEvent *event){
    // qDebug()<<"press";
    QPointF ptf=event->screenPos();
    oldPos=QPoint(ptf.rx(),ptf.ry());
}

void TitleLabel::mouseReleaseEvent(QMouseEvent *event){
    // qDebug()<<"released";
}

void TitleLabel::mouseMoveEvent(QMouseEvent *event){
    QPointF ptf=event->screenPos();
    QPoint pt=QPoint(ptf.rx(),ptf.ry());
    QPoint delta=pt-oldPos;
    emit dragged(delta.rx(),delta.ry());
    // qDebug()<<"moved: "<<pt<<" "<<delta;
    oldPos=pt;
    event->accept();
}

