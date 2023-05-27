#pragma once
#include"Rook.h"
#include"Queen.h"
#include"King.h"
#include"Bishop.h"
#include"Board.h"
#include"Player.h"
#include<string>
#include <typeindex>
#include <typeinfo>
using namespace std;
#define ROWS 8
#define COLS 8
class Piece;
class Rook;
class Queen;
class Bishop;
class Board {
    const Piece* _board[ROWS][COLS];
public:
    Board();
    Board(string s);
    Board(const Board& b);
    void myLocation(const Piece*,int loc[]) const;
    const Piece* getSquare(int i, int j) const;
    void setSquare(int Isor, int Jsor,int Ides,int Jdes);
    ~Board();
};