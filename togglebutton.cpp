#include "togglebutton.h"
#include <QFile>
#include <QtGlobal>
#include <QtDebug>
#include "util.h"

ToggleButton::ToggleButton(QWidget *parent):QPushButton(parent),x(0),y(0),val(0){
    this->setStyleSheet(Util::getStringFromResource(":/style/ToggleButton.txt"));
}

void ToggleButton::setX(int _x){
    this->x=_x;
}

void ToggleButton::setY(int _y){
    this->y=_y;
}

int ToggleButton::getX(){
    return this->x;
}

int ToggleButton::getY(){
    return this->y;
}

void ToggleButton::setVal(int _v){
    this->val=_v;
}

int ToggleButton::getVal(){
    return this->val;
}



