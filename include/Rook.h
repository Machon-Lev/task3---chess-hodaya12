#pragma once
#include "Piece.h"
#include "Board.h"

class Board;
class Rook :public Piece{
public:
	using Piece::Piece;
	bool isValidmove(int i, int j, const Board& board)const;
	
};
