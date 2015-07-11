#include "brickset.h"
#include <QtDebug>
#include <iostream>
using namespace std;

BrickSet::BrickSet(){
}

void BrickSet::confirmOne(int mi, int mj, int _i, int _j, char _val){
    if (mi < 0 || mi >= 3 || mj < 0 || mj >= 3) {
        return;
    }
    this->bricks[mi][mj].confirmOne(_i, _j, _val);
}

void BrickSet::confirmOne(int _i, int _j, char _val){
    if(_i<0||_i>=9||_j<0||_j>=9||_val<0||_val>9){
        return;
    }
    int mi = _i / 3;
    int mj = _j / 3;
    int i = _i - 3 * mi;
    int j = _j - 3 * mj;
    this->confirmOne(mi,mj,i,j,_val);
}



int BrickSet::reducePoss(){
    for (int mi = 0; mi < 3; mi++) {
        for (int mj = 0; mj < 3; mj++) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    char val = this->bricks[mi][mj].val[i][j];
                    if (val > 0) {
                        this->bricks[mi][mj].reduceBrick(i, j, val);
                        for (int _i = 0; _i < 3; _i++) {
                            if (_i != mi) {
                                this->bricks[_i][mj].reduceColumn(j, val);
                            }
                        }
                        for (int _j = 0; _j < 3; _j++) {
                            if (_j != mj) {
                                this->bricks[mi][_j].reduceRow(i, val);
                            }
                        }
                    }
                }
            }
        }
    }
    int changed = 0;
    for (int mi = 0; mi < 3; mi++) {
        for (int mj = 0; mj < 3; mj++) {
            int tmp = this->bricks[mi][mj].validateBrick();
            if (tmp == 1) {
                changed = 1;
            }
            if (tmp == -1) {
                return -1;
            }
        }
    }
    return changed;
}

int BrickSet::reduceTillNoChange(){
    while (true) {
        int tmp = this->reducePoss();
        if (tmp == 0) {
            return 1;
        }
        if (tmp == -1) {
            return -1;
        }
    }
}

BrickSet* BrickSet::solve(){
    this->reduceTillNoChange();
    int status = this->status();
    if (status == 1) {
        return this;
    } else if (status == -1) {
        return NULL;
    }

    // this->printAllVals2Screen();
    // pick one undetermined brick
    QuadIndex* qi = this->pickOneUndetermined();
    // for all the possibilities in the brick(_mi,_mj,_i,_j), solve
    if (qi != NULL) {
        for (int val = 0; val < 9; val++) {
            if (this->bricks[qi->mi][qi->mj].bricks[qi->i][qi->j][val] == 1) {
                BrickSet* subBs = this->copy();
                subBs->bricks[qi->mi][qi->mj].val[qi->i][qi->j]=val + 1;
                BrickSet* ret = subBs->solve();
                if (ret != NULL) {
                    delete qi;
                    delete subBs;
                    return ret;
                }
            }
        }
    } else {
        qDebug()<<"wrong!";
    }
    if(qi!=NULL){
        delete qi;
    }
    return NULL;
}

QuadIndex *BrickSet::pickOneUndetermined(){
    for (int _mi = 0; _mi < 3; _mi++) {
        for (int _mj = 0; _mj < 3; _mj++) {
            for (int _i = 0; _i < 3; _i++) {
                for (int _j = 0; _j < 3; _j++) {
                    if (this->bricks[_mi][_mj].val[_i][_j] == 0) {
                        return new QuadIndex(_mi, _mj, _i, _j);
                    }
                }
            }
        }
    }
    return NULL;
}

BrickSet *BrickSet::copy(){
    BrickSet* cp = new BrickSet();
    memcpy(cp,this,sizeof(BrickSet));
    return cp;
}

int BrickSet::status(){
    bool undetermined = false;
    for (int mi = 0; mi < 3; mi++) {
        for (int mj = 0; mj < 3; mj++) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    char val = this->bricks[mi][mj].val[i][j];
                    if (val == 0) {
                        undetermined = true;
                    } else if (val < 0) {
                        return -1;
                    }
                }
            }
        }
    }
    if (undetermined) {
        return 0;
    } else {
        return 1;
    }
}

void BrickSet::printAllVals2Screen(){
    cout<<endl;
    for (int _i = 0; _i < 9; _i++) {
        for (int _j = 0; _j < 9; _j++) {
            int mi = _i / 3;
            int mj = _j / 3;
            int i = _i - mi * 3;
            int j = _j - mj * 3;
            cout<<(int) this->bricks[mi][mj].val[i][j]<<" ";
        }
        cout<<endl;
    }
}

char BrickSet::getOne(int _i, int _j){
    int mi = _i / 3;
    int mj = _j / 3;
    int i = _i - mi * 3;
    int j = _j - mj * 3;
    return this->bricks[mi][mj].val[i][j];
}

