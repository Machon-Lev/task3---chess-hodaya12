#include "Board.h";




Board::Board()
{
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			_board[i][j] = nullptr;
}

Board::Board(string s)
{
	int i = 0;
	for (int i1 = 0; i1 < ROWS; i1++)
		for (int j = 0; j < COLS; j++) {
			switch (s[i]) {
			case 'r':
				_board[i1][j]=new Rook(PLAYER2);
				break;
			case 'R':
				_board[i1][j] = new Rook(PLAYER1);
				break;
			case 'K':
				_board[i1][j] = new King(PLAYER1);
				break;
			case 'k':
				_board[i1][j] = new King(PLAYER2);
				break;
			case 'b':
				_board[i1][j] = new Bishop(PLAYER2);
				break;
			case 'B':
				_board[i1][j] = new Bishop(PLAYER1);
				break;
			case 'q':
				_board[i1][j] = new Queen(PLAYER2);
				break;
			case 'Q':
				_board[i1][j] = new Queen(PLAYER1);
				break;
			case '#':
				_board[i1][j] = nullptr;
				break;
			}
			i++;
		}
}

Board::Board(const Board& b)
{
	
	for (int i1 = 0; i1 < ROWS; i1++)
		for (int j = 0; j < COLS; j++) {
			if (!b.getSquare(i1+1, j+1)) { _board[i1][j] = nullptr; continue; };
			if(typeid(*b.getSquare(i1+1, j+1))== typeid(Rook))
				_board[i1][j] = new Rook(Player(b.getSquare(i1+1, j+1)->getPlayer()));
			if (typeid(*b.getSquare(i1+1, j+1)) == typeid(King))
				_board[i1][j] = new King(Player(b.getSquare(i1+1, j+1)->getPlayer()));
			if (typeid(*b.getSquare(i1 + 1, j + 1)) == typeid(Bishop))
				_board[i1][j] = new Bishop(Player(b.getSquare(i1 + 1, j + 1)->getPlayer()));
			if (typeid(*b.getSquare(i1 + 1, j + 1)) == typeid(Queen))
				_board[i1][j] = new Queen(Player(b.getSquare(i1 + 1, j + 1)->getPlayer()));
			
			}
			
		
}

void Board::myLocation(const Piece* p, int loc[]) const
{
    if (sizeof(loc) / sizeof(int) == 2) {
        int row = -1;
        int col = -1;

        for (int i1 = 1; i1 < ROWS + 1; i1++)
        {
            for (int j1 = 1; j1 < COLS + 1; j1++)
            {
                if (p == getSquare(i1, j1))
                {
                    row = i1;
                    col = j1;
                    break;
                }
            }

            if (row != -1 && col != -1)
                break;
        }
        loc[0] = row;
        loc[1] = col;
    }
}



const Piece* Board:: getSquare(int i, int j)const {
	if (i < 1 || i>8 || j < 1 || j>8)
		return nullptr;
	return _board[i-1][j-1];

}

void Board::setSquare(int Isor, int Jsor, int Ides, int Jdes)
{
	if ((Isor > 0 && Isor < 9 && Jsor >0 && Jsor < 9)&&
		(Ides > 0 && Ides < 9 && Jdes >0 && Jdes < 9)) {
		if (_board[Ides -1][Jdes -1])
			delete _board[Ides -1][Jdes -1];
		_board[Ides -1][Jdes -1] = _board[Isor - 1][Jsor - 1];
		_board[Isor - 1][Jsor - 1] = nullptr;
	}
		
	
}

Board::~Board()
{
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            delete(_board[i][j]);
}
