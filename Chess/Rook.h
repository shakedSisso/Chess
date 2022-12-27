#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(const int row, const int col, const bool isWhite);
	~Rook();
	bool isLegalMove(const int row, const int col) const override;
	std::ostream& operator<<(std::ostream& os) const override;
};