#pragma once
#include <typeindex>
#include <typeinfo>
#include "Board.h"
#include "Rook.h"
#include"King.h"
#include<stdio.h>
#include "Code.h"
using namespace std;
class Game {
	Board _board;
	Player turn;
public:
	Game(string s, Player p=PLAYER1);
	Game(const Board&, Player p = PLAYER1);
	Code CanMove(int i,int j,int i1,int j1)const;
	Code move(int i, int j, int i1, int j1);
	bool isChess(Player player)const;
	bool SomeoneCanMoveTo(int iDes, int jDes, Player)const;
	bool ifCauseChess(int i, int j, int i1, int j1)const;
};
