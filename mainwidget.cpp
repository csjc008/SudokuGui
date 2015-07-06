#include "mainwidget.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QLabel>
#include "util.h"
#include "titlelabel.h"
#include <QPoint>
#include <QtDebug>
#include <QSpacerItem>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent){
    QtAwesome* as = new QtAwesome();
    as->initFontAwesome();
    this->awesome=as;

    QVBoxLayout* vLayout=new QVBoxLayout();
    QHBoxLayout* headerLayout=new QHBoxLayout();
    QVBoxLayout* hvLayout=new QVBoxLayout();
    TitleLabel* tlHeader=new TitleLabel();
    tlHeader->setText("Sudoku Solver");
    headerLayout->addWidget(tlHeader);
    QGridLayout* btnGridLayout=new QGridLayout();
    btnGridLayout->setVerticalSpacing(3);
    btnGridLayout->setHorizontalSpacing(3);
    QGridLayout*** btnSubLayout=new QGridLayout** [3];
    for(int i=0;i<3;i++){
        btnSubLayout[i]=new QGridLayout* [3];
        for(int j=0;j<3;j++){
            btnSubLayout[i][j]=new QGridLayout();
            btnSubLayout[i][j]->setVerticalSpacing(1);
            btnSubLayout[i][j]->setHorizontalSpacing(1);
        }
    }
    btnGrid=new ToggleButton* [9];
    for(int i=0;i<9;i++){
        btnGrid[i]=new ToggleButton[9];
        for(int j=0;j<9;j++){
            btnGrid[i][j].setText("0");
            btnGrid[i][j].setCheckable(true);
            btnGrid[i][j].setFixedSize(50,50);
            btnGrid[i][j].setX(i);
            btnGrid[i][j].setY(j);
            btnSubLayout[i/3][j/3]->addWidget(&btnGrid[i][j],i%3,j%3);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            btnGridLayout->addLayout(btnSubLayout[i][j],i,j);
        }
    }
    // vLayout->addWidget(tlHeader);
    QPushButton* btnTimes = new QPushButton( awesome->icon( fa::times ),"" );
    // QPushButton* btnTimes = new QPushButton( QString( QChar(static_cast<int>(0xf00d)) ) );
    // btnTimes->setFlat(true);
    btnTimes->setStyleSheet(Util::getStringFromResource(":/style/Times.txt"));
    hvLayout->addWidget(btnTimes);
    hvLayout->addStretch();
    headerLayout->addStretch();
    headerLayout->addLayout(hvLayout);
    vLayout->addLayout(headerLayout);
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
