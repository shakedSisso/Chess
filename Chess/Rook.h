#pragma once
#include "Piece.h"

class Rook : public Piece
{
public:
	Rook(const int row, const int col, const bool isWhite);
	~Rook();
	bool isLegalMove(const int row, const int col, Board& board) const override;
	std::string toString() const override;
};