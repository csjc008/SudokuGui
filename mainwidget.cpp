#include "mainwidget.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent){
    QVBoxLayout* vLayout=new QVBoxLayout();
    QLabel* tlHeader=new QLabel("Sudoku Solver");
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
    vLayout->addLayout(btnGridLayout);
    setLayout(vLayout);
    setWindowFlags( Qt::FramelessWindowHint );
}

MainWidget::~MainWidget(){

}
