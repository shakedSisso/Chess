#include "King.h"

King::King(int row, int col, bool isWhite) 
	: Piece(row, col, isWhite)
{
}

King::~King()
{
}

bool King::isLegalMove(const int row, const int col, Board& board) const
{
	return false;
}

std::string King::toString() const
{
	if (this->_isWhite)
	{
		return "K";
	}
	return "k";
}

bool King::isChess(Board& board)
{
	int i = 0;
	int j = 0;
	bool result = false;
	Piece* piece;
	for ( i = 0; i < ROW_COL_SIZE; i++)
	{
		for ( j = 0; j < ROW_COL_SIZE; j++)
		{
			piece = board.getPiece(i, j);
			if (piece->getIsWhite() != this->_isWhite && piece->isLegalMove(this->_row, this->_col, board))
			{
				return true;
			}
		}
	}
	return false;
}
