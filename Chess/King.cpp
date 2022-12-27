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

std::ostream& King::operator<<(std::ostream& os) const
{
	if (this->_isWhite)
	{
		os << "K";
	}
	else
	{
		os << "k";
	}
	return os;
}

bool King::isChess(Board& board)
{
	return false;
}
