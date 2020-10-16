#ifndef MINMAX_H
#define MINMAX_H
#include <QPair>

class minmax

{
public:
    bool full(int [3][3]);
    int Win(int [3][3]);
    int Move(int [3][3], int);
    QPair<int,int> GetMove(int [3][3]);
};

#endif // MINMAX_H
