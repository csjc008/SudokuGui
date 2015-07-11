#ifndef MINIBRICKSET_H
#define MINIBRICKSET_H


class MiniBrickSet
{
public:
    MiniBrickSet();
    char bricks[3][3][9];
    char val[3][3];
    void confirmOne(int i, int j, char _val);
    void reduceBrick(int _i, int _j, char _val);
    void reduceRow(int _i, char _val);
    void reduceColumn(int _j, char _val);
    int validateBrick();
};

#endif // MINIBRICKSET_H
