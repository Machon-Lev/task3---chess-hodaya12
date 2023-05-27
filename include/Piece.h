#pragma once

#include<stdio.h>
#include <string>
#include "Code.h"
#include "Player.h"
using namespace std;
class Board;
class Piece {
	Player _player;
public:
	Piece(Player);
	const Player getPlayer() const;
	virtual Code move(const Board &board,int i,int j) const;
	virtual bool isValidmove(int i, int j, const Board& board) const= 0;
	
};