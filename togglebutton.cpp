#include "togglebutton.h"
#include <QFile>
#include <QtGlobal>
#include <QtDebug>
#include "util.h"

ToggleButton::ToggleButton(QWidget *parent):QPushButton(parent),x(0),y(0),val(0){
}

void ToggleButton::setX(int _x){
    this->x=_x;
    if((x+y)%2==1){
        this->setStyleSheet(Util::getStringFromResource(":/style/ToggleButton1.txt"));
    } else {
       this->setStyleSheet(Util::getStringFromResource(":/style/ToggleButton2.txt"));
    }
}

void ToggleButton::setY(int _y){
    this->y=_y;
    if((x+y)%2==1){
        this->setStyleSheet(Util::getStringFromResource(":/style/ToggleButton1.txt"));
    } else {
       this->setStyleSheet(Util::getStringFromResource(":/style/ToggleButton2.txt"));
    }
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



