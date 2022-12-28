#include "King.h"

King::King(int row, int col, bool isWhite) 
	: Piece(row, col, isWhite)
{
	this->_isNull = false;
}

King::~King()
{
}

bool King::isLegalMove(const int row, const int col) const
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
	return false;
}
