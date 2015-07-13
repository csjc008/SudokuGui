#include "mainwidget.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include "util.h"
#include "titlelabel.h"
#include <QPoint>
#include <QtDebug>
#include <QSpacerItem>
#include <QApplication>

#include <iostream>

using namespace  std;

MainWidget::MainWidget(QWidget *parent) : QWidget(parent),curx(-1),cury(-1),done(false){
    this->setObjectName("MainWindow");
    this->setStyleSheet(Util::getStringFromResource(":/style/MainWidget.txt"));
    QtAwesome* as = new QtAwesome();
    as->initFontAwesome();
    this->awesome=as;

    QVBoxLayout* vLayout=new QVBoxLayout();
    vLayout->setContentsMargins(0,0,0,10);
    QHBoxLayout* headerLayout=new QHBoxLayout();
    QVBoxLayout* hvLayout=new QVBoxLayout();
    TitleLabel* tlHeader=new TitleLabel();
    tlHeader->setText("Sudoku Solver");
    tlHeader->setFixedWidth(440);
    headerLayout->addWidget(tlHeader);
    QGridLayout* btnGridLayout=new QGridLayout();
    btnGridLayout->setContentsMargins(10,0,10,0);
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
            connect(&btnGrid[i][j],&ToggleButton::pressedxy,this,&MainWidget::pressNumber);
            btnSubLayout[i/3][j/3]->addWidget(&btnGrid[i][j],i%3,j%3);
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            btnGridLayout->addLayout(btnSubLayout[i][j],i,j);
        }
    }
    // vLayout->addWidget(tlHeader);
    btnTimes = new QPushButton( awesome->icon( fa::times ),"" );
    btnTimes->setFixedSize(30,30);

    // QPushButton* btnTimes = new QPushButton( QString( QChar(static_cast<int>(0xf00d)) ) );
    // btnTimes->setFlat(true);
    btnTimes->setStyleSheet(Util::getStringFromResource(":/style/Times.txt"));
    btnSolve=new QPushButton(awesome->icon(fa::flag),"Solve");
    btnSolve->setStyleSheet(Util::getStringFromResource(":/style/BlueButton.txt"));
    btnReset=new QPushButton(awesome->icon(fa::beer),"Reset");
    btnReset->setStyleSheet(Util::getStringFromResource(":/style/BlueButton.txt"));
    hvLayout->addWidget(btnTimes);
    hvLayout->addStretch();
    headerLayout->addStretch();
    headerLayout->addLayout(hvLayout);
    vLayout->addLayout(headerLayout);
    vLayout->addLayout(btnGridLayout);
    this->txtStatus=new QLabel();
    this->txtStatus->setStyleSheet(Util::getStringFromResource(":/style/MessageLabel.txt"));
    QHBoxLayout* tailLayout=new QHBoxLayout();
    tailLayout->setContentsMargins(0,0,10,0);
    tailLayout->addWidget(txtStatus);
    tailLayout->addStretch();
    tailLayout->addWidget(btnReset);
    tailLayout->addWidget(btnSolve);
    vLayout->addLayout(tailLayout);
    setLayout(vLayout);
    setWindowFlags( Qt::FramelessWindowHint );
    connect(tlHeader,&TitleLabel::dragged,this,&MainWidget::moveWindow);
    connect(this->btnTimes,&QPushButton::clicked,this,&MainWidget::quitApp);
    connect(this->btnSolve,&QPushButton::clicked,this,&MainWidget::solveSudoku);
    connect(this->btnReset,&QPushButton::clicked,this,&MainWidget::reset);
}

MainWidget::~MainWidget(){
}

void MainWidget::setAwesome(QtAwesome *_as){
    this->awesome=_as;
}

QPushButton *MainWidget::getQuitButton(){
    return this->btnTimes;
}

void MainWidget::moveWindow(int x, int y){
    // qDebug()<<"moved: "<<x<<","<<y;
    this->move(QPoint(x,y)+this->pos());
}

void MainWidget::quitApp(){
    QApplication::quit();
}

void MainWidget::pressNumber(int x, int y){
    if(curx!=-1 && cury!=-1){
        this->btnGrid[curx][cury].toggle();
    }
    curx=x;cury=y;
}

void MainWidget::solveSudoku(){
    if(done){
        this->txtStatus->setText("Already solved, please RESET!");
        return;
    }
    BrickSet bs;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            int val=this->btnGrid[i][j].getVal();
            if(val>0){
                bs.confirmOne(i,j,val);
            }
        }
    }
    // bs.printAllVals2Screen();
    BrickSet *ret=bs.solve();
    if(ret!=NULL){
        // ret->printAllVals2Screen();
        this->txtStatus->setText("Solved!");
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                this->btnGrid[i][j].setVal(ret->getOne(i,j));
                this->btnGrid[i][j].setText(QString('0'+ret->getOne(i,j)));
            }
        }
        delete ret;
    } else {
        // no solution!
        this->txtStatus->setText("No solution!");
    }
    done=true;
}

void MainWidget::reset(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            this->btnGrid[i][j].setVal(0);
            this->btnGrid[i][j].setText(QString('0'));
        }
    }
    done=false;
    this->txtStatus->setText("All bricks reset.");
}
