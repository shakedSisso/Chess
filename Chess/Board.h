#pragma once
#include <iostream>
#include "Piece.h"

#define ROW_COL_SIZE 8

class Piece;

class Board
{
public:
	Board();
	~Board();
	void buildBoard(std::string boardString);
	void move(const int row, const int col);
	void printBoard(); // debug
	Piece* getPiece(const int row, const int col);

private:
	Piece* _board[ROW_COL_SIZE][ROW_COL_SIZE];
};