#include "mainwidget.h"
#include <QGridLayout>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent){
    QGridLayout* btnLayout=new QGridLayout();
    btnGrid=new ToggleButton* [9];
    for(int i=0;i<9;i++){
        btnGrid[i]=new ToggleButton[9];
        for(int j=0;j<9;j++){
            btnGrid[i][j].setText("0");
            btnGrid[i][j].setCheckable(true);
            btnGrid[i][j].setFixedSize(50,50);
            btnGrid[i][j].setX(i);
            btnGrid[i][j].setY(j);
            btnLayout->addWidget(&btnGrid[i][j],i,j);
        }
    }
    setLayout(btnLayout);
}

MainWidget::~MainWidget(){

}
