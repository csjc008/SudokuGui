#ifndef TOGGLEBUTTON_H
#define TOGGLEBUTTON_H

#include <QPushButton>

class ToggleButton : public QPushButton
{
public:
    ToggleButton(QWidget *parent = 0);
    void setX(int _x);
    void setY(int _y);
    int getX();
    int getY();

    void setVal(int _v);
    int getVal();
private:
    int x,y;
    int val;
};

#endif // TOGGLEBUTTON_H
