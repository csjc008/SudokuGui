#ifndef BRICKSET_H
#define BRICKSET_H
#include "minibrickset.h"
#include "quadindex.h"

class BrickSet
{
public:
    BrickSet();
    void confirmOne(int mi, int mj, int _i, int _j, char _val);
    void confirmOne(int _i, int _j, char _val);
    MiniBrickSet bricks[3][3];
    int reducePoss();
    int reduceTillNoChange();
    BrickSet* solve();
    QuadIndex* pickOneUndetermined();
    BrickSet* copy();
    int status();
    void printAllVals2Screen();
    char getOne(int _i,int _j);
};

#endif // BRICKSET_H
