#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	King(const int row, const int col, const bool isWhite);
	~King();
	bool isLegalMove(const int row, const int col,  const Board& board) const override;
	std::string toString() const override;
	bool isChess(Board& board);
};