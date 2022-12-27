#pragma once
#include <iostream>
#include "Piece.h"

class Board
{
public:
	Board();
	~Board();
	void buildBoard(std::string boardString);
	void move(const int row, const int col);
	void printBoard(); // debug

private:
	Piece** _board;
};