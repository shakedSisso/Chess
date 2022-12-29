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
	void move(const int orgRow, const int orgCol, const int dstRow, const int dstCol);
	void printBoard(); // debug
	Piece* getPiece(const int row, const int col) const;

private:
	Piece* _whiteKing;
	Piece* _blackKing;
	Piece* _board[ROW_COL_SIZE][ROW_COL_SIZE];
};