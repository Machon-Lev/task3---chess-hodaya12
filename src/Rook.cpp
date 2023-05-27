#include "..\include\Rook.h"



bool Rook::isValidmove(int i, int j, const Board& board)const
{
    int loc[2];
    board.myLocation(this,loc);
    int row = loc[0];
    int col = loc[1];
    if (row == i && col != j) {
        for (int i1 = min(col, j) + 1; i1 < max(col, j); i1++)
            if (board.getSquare(row, i1))
                return false;
        return true;
    }
    if (col == j && row != i) {
        for (int i1 = min(row, i) + 1; i1 < max(row, i); i1++)
            if (board.getSquare(i1, col))
                return false;
        return true;
    }
    return false;
       
}


