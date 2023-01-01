#include "Queen.h"

Queen::Queen(const int row, const int col, const bool isWhite)
	: Piece(row, col, isWhite)
{
}

Queen::~Queen()
{
}

bool Queen::isLegalMove(const int row, const int col, const Board& board) const
{
	return false;
}

std::string Queen::toString() const
{
	if (this->_isWhite)
	{
		return "Q";
	}
	return "q";
}
