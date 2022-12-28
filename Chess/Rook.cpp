#include "Rook.h"

Rook::Rook(const int row, const int col, const bool isWhite)
	: Piece(row, col, isWhite)
{
	this->_isNull = false;
}

Rook::~Rook()
{
}

bool Rook::isLegalMove(const int row, const int col) const
{
	return false;
}

std::string Rook::toString() const
{
	if (this->_isWhite)
	{
		return "R";
	}
	return "r";
}
