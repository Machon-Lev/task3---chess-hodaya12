#include "..\include\Queen.h"



bool Queen::isValidmove(int i, int j, const Board& board) const
{
    int loc[2];
    board.myLocation(this, loc);
    int row = loc[0];
    int col = loc[1];
    if (abs(row - i) == abs(col - j)) {
        if (row < i&& col < j) {
            for (int i1 = row + 1, j1 = col + 1; j1 < j && i1 < i; i1++, j1++)
                if (board.getSquare(i1, j1))
                    return false;
            return true;
        }
        if (row > i && col > j) {
            for (int i1 = row - 1, j1 = col - 1; j1 > j && i1 > i; i1--, j1--)
                if (board.getSquare(i1, j1))
                    return false;
            return true;
        }
        if (row < i && col > j) {
            for (int i1 = row + 1, j1 = col - 1; j1 > j && i1 < i; i1++, j1--)
                if (board.getSquare(i1, j1))
                    return false;
            return true;
        }
        if (row > i && col < j) {
            for (int i1 = row - 1, j1 = col + 1; j1 < j && i1 > i; i1--, j1++)
                if (board.getSquare(i1, j1))
                    return false;
            return true;
        }
        
    }
    

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
