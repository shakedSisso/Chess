#include "Knight.h"

Knight::Knight(const int row, const int col, const bool isWhite)
    : Piece(row, col, isWhite)
{
}

Knight::~Knight()
{
}

bool Knight::isLegalMove(const int row, const int col, const Board& board) const
{
    return false;
}

std::string Knight::toString() const
{
	if (this->_isWhite)
	{
		return "N";
	}
	return "n";
}
