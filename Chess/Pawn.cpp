#include "Pawn.h"

Pawn::Pawn(const int row, const int col, const bool isWhite)
	: Piece(row, col, isWhite)
{
}

Pawn::~Pawn()
{
}

bool Pawn::isLegalMove(const int row, const int col, const Board& board) const
{
	return false;
}

std::string Pawn::toString() const
{
	if (this->_isWhite)
	{
		return "P";
	}
	return "p";
}
