#include "minibrickset.h"
#include <string.h>
#include <QtDebug>
#include <iostream>

using namespace std;

MiniBrickSet::MiniBrickSet(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<9;k++){
                this->bricks[i][j][k]=1;
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            this->val[i][j]=0;
        }
    }
}

void MiniBrickSet::confirmOne(int i, int j, char _val){
    if (_val < 1 || _val > 9 || i < 0 || i >= 3 || j < 0 || j >= 3) {
        return;
    }
    this->val[i][j] = _val;
}

void MiniBrickSet::reduceBrick(int _i, int _j, char _val){
    if (_val < 1 || _val > 9 || _i < 0 || _i >= 3 || _j < 0 || _j >= 3) {
        return;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == _i && j == _j) {
                continue;
            }
            bricks[i][j][_val - 1] = 0;
        }
    }
}

void MiniBrickSet::reduceRow(int _i, char _val){
    if (_val < 1 || _val > 9 || _i < 0 || _i >= 3) {
        return;
    }
    for (int j = 0; j < 3; j++) {
        bricks[_i][j][_val - 1] = 0;
    }
}

void MiniBrickSet::reduceColumn(int _j, char _val){
    if (_val < 1 || _val > 9 || _j < 0 || _j >= 3) {
        return;
    }
    for (int i = 0; i < 3; i++) {
        bricks[i][_j][_val - 1] = 0;
    }
}

int MiniBrickSet::validateBrick(){
    int changed = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int numPoss = 0;
            char curPoss = 0;
            for (int val = 0; val < 9; val++) {
                if (bricks[i][j][val] == 1) {
                    numPoss++;
                    curPoss = val + 1;
                }
            }
            if (numPoss == 1) {
                // previously undetermined
                if (this->val[i][j] == 0) {
                    changed = 1;
                }
                this->val[i][j] = curPoss;
            }
            if (numPoss == 0) {
                // bad case!
                this->val[i][j] = -1;
                changed = -1;
            }
        }
    }
    return changed;
}

