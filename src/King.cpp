#include "..\include\King.h"



bool King::isValidmove(int i, int j, const Board& board)const
{
	int loc[2];
	board.myLocation(this,loc);
	int row = loc[0];
	int col = loc[1];
	if (row == i && col == j)return false;
	return (abs(row - i) <= 1 && abs(col - j) <= 1);
}
