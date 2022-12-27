#include "Board.h"

#define ROW_COL_SIZE 8

Board::Board()
{
	int i = 0;
	int j = 0;
	this->_board = new Piece * [ROW_COL_SIZE];
	for (i = 0; i < ROW_COL_SIZE; i++) {
		this->_board[i] = new Piece[ROW_COL_SIZE];
	}
	
}

Board::~Board()
{
	int i = 0;
	for (i = 0; i < ROW_COL_SIZE; i++) {
		delete[] this->_board[i];
	}
	delete[] this->_board;
}

void Board::buildBoard(std::string boardString)
{
}

void Board::move(const int row, const int col)
{
}

void Board::printBoard()
{
}
