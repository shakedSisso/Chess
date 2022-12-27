#pragma once
#include "Piece.h"
#include "Board.h"

class King : public Piece
{
public:
	King(const int row, const int col, const bool isWhite);
	~King();
	bool isLegalMove(const int row, const int col) const override;
	bool isChess(Board& board);
};