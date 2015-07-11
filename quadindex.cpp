#include "quadindex.h"

QuadIndex::QuadIndex(int _mi, int _mj, int _i, int _j){
    this->mi=_mi;
    this->mj=_mj;
    this->i=_i;
    this->j=_j;
}

QuadIndex::QuadIndex(){
    mi = mj = i = j = 0;
}

