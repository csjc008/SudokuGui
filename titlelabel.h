#ifndef TITLELABEL_H
#define TITLELABEL_H
#include <QLabel>
#include <QWidget>
#include <QMouseEvent>
#include <QMoveEvent>
#include <QPoint>

class TitleLabel : public QLabel
{
    Q_OBJECT
public:
    TitleLabel(QWidget* parent=0);

protected:
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent *event);

signals:
    void dragged(int x,int y);

private:
    QPoint oldPos;
};

#endif // TITLELABEL_H
