#ifndef TOGGLEBUTTON_H
#define TOGGLEBUTTON_H

#include <QPushButton>
#include <QKeyEvent>

class ToggleButton : public QPushButton
{
    Q_OBJECT
public:
    ToggleButton(QWidget *parent = 0);
    void setX(int _x);
    void setY(int _y);
    int getX();
    int getY();

    void setVal(int _v);
    int getVal();
protected:
    void keyPressEvent(QKeyEvent * e);
signals:
    void pressedxy(int x,int y);
public slots:
    void coordPressed();
private:
    int x,y;
    int val;
};

#endif // TOGGLEBUTTON_H
