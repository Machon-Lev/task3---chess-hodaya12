#include "..\include\Piece.h"



Piece::Piece(Player p)
{
    if (p == PLAYER1)
        _player = PLAYER1;
    else
        _player = PLAYER2;
}

const Player Piece::getPlayer() const
{
	return _player;
}



Code Piece::move(const Board &board,int i, int j)const
{
    if (!isValidmove(i, j, board))
        return CODE_21;
    return CODE_42;
}







