#include "Rook.h"

Rook::Rook(const int row, const int col, const bool isWhite)
	: Piece(row, col, isWhite)
{
}

Rook::~Rook()
{
}

bool Rook::isLegalMove(const int row, const int col) const
{
	return false;
}
