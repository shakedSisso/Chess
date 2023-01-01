#include "Bishop.h"

Bishop::Bishop(const int row, const int col, const bool isWhite)
	: Piece(row, col, isWhite)
{
}

Bishop::~Bishop()
{
}

bool Bishop::isLegalMove(const int row, const int col, const Board& board) const
{
	return false;
}

std::string Bishop::toString() const
{
	if (this->_isWhite)
	{
		return "B";
	}
	return "b";
}
