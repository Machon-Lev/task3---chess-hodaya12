#include "..\include\Game.h"

Game::Game(string s, Player p):_board(s),turn(p)
{
	
}

Game::Game(const Board& b, Player p):_board(b), turn(p)
{
	
}




Code Game::CanMove(int i, int j, int i1, int j1)const
{
	
	const Piece* moving_piece=_board.getSquare(i, j);
	if (!moving_piece)
		return CODE_11;
	if(moving_piece->getPlayer()!=turn)
		return CODE_12;
	const Piece* des_piece = _board.getSquare(i1, j1);
	if(des_piece&&des_piece->getPlayer()== turn)
		return CODE_13;
	return moving_piece->move(_board, i1, j1);
	
	
}

Code Game::move(int i, int j, int i1, int j1)
{
	Code code=CanMove(i, j,  i1, j1);
	if (code == CODE_42) {
		if (ifCauseChess(i, j, i1, j1))
			return CODE_31;

		_board.setSquare(i, j, i1,j1);
		if (isChess(Player((turn + 1) % 2))) {
			turn = Player((turn + 1) % 2);
			return CODE_41;
		}
		turn = Player((turn + 1) % 2);
		return code;
	}
}

bool Game::SomeoneCanMoveTo(int iDes, int jDes,Player p) const
{
	for(int i=1;i<ROWS+1;i++)
		for (int j = 1; j < COLS+1; j++) {
			if (_board.getSquare(i, j)) {
				if (_board.getSquare(i, j)->getPlayer() == p && CanMove(i, j, iDes, jDes) == CODE_42)
					return true;
			}
		}
	return false;

}

bool Game::ifCauseChess(int i, int j, int i1, int j1) const
{
	Board newBoard(_board);
	newBoard.setSquare(i, j, i1,j1);
	Game newGame(newBoard, Player((turn + 1) % 2));
	return newGame.isChess(_board.getSquare(i, j)->getPlayer());
}

bool Game::isChess(Player player)const
{
	int row = -1;
	int col = -1;
	for(int i=1;i<ROWS+1;i++) //to find the king
		for (int j = 1; j < COLS+1; j++)
			if (_board.getSquare(i, j)&&typeid(*(_board.getSquare(i, j))) == typeid(King) &&
				_board.getSquare(i, j)->getPlayer() == player)
			{
				row = i;
				col = j;
				break;
			}
	if (row == -1 || col == -1)return false;
	return(SomeoneCanMoveTo(row, col, Player((player + 1) % 2)));

	
}
