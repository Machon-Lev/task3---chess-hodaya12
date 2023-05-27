#pragma once
#include "Piece.h"
#include<cmath>
#include "Board.h"

class King :public Piece {
public:
	using Piece::Piece;
	bool isValidmove(int i, int j, const Board& board) const;
};
