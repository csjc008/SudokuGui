#include "mainwidget.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include "util.h"
#include "titlelabel.h"
#include <QPoint>
#include <QtDebug>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent){
    QtAwesome* as = new QtAwesome();
    as->initFontAwesome();
    this->awesome=as;

    QVBoxLayout* vLayout=new QVBoxLayout();
    TitleLabel* tlHeader=new TitleLabel();
    tlHeader->setText("Sudoku Solver");
    QGridLayout* btnGridLayout=new QGridLayout();
    btnGridLayout->setVerticalSpacing(4);
    btnGridLayout->setHorizontalSpacing(4);
    btnGrid=new ToggleButton* [9];
    for(int i=0;i<9;i++){
        btnGrid[i]=new ToggleButton[9];
        for(int j=0;j<9;j++){
            btnGrid[i][j].setText("0");
            btnGrid[i][j].setCheckable(true);
            btnGrid[i][j].setFixedSize(50,50);
            btnGrid[i][j].setX(i);
            btnGrid[i][j].setY(j);
            btnGridLayout->addWidget(&btnGrid[i][j],i,j);
        }
    }
    vLayout->addWidget(tlHeader);

    QPushButton* btnTimes = new QPushButton( awesome->icon( fa::times ),"" );
    // QPushButton* btnTimes = new QPushButton( QString( QChar(static_cast<int>(0xf00d)) ) );
    // btnTimes->setFlat(true);
    btnTimes->setStyleSheet(Util::getStringFromResource(":/style/Times.txt"));
    vLayout->addWidget(btnTimes);

    vLayout->addLayout(btnGridLayout);
    setLayout(vLayout);
    setWindowFlags( Qt::FramelessWindowHint );
    connect(tlHeader,&TitleLabel::dragged,this,&MainWidget::moveWindow);
}

MainWidget::~MainWidget(){

}

void MainWidget::setAwesome(QtAwesome *_as){
    this->awesome=_as;
}

void MainWidget::moveWindow(int x, int y){
    // qDebug()<<"moved: "<<x<<","<<y;
    this->move(QPoint(x,y)+this->pos());
}
