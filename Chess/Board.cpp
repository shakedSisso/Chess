#include "Board.h"
#include "King.h"
#include "Rook.h"

#define ROW_COL_SIZE 8
#define WHITE true
#define BLACK false

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
	int i = 0;
	int row = 0;
	int col = 0;
	for (i = 0; i < boardString.length(); i++)
	{
		row = i / ROW_COL_SIZE;
		col = i % ROW_COL_SIZE;
		if (boardString[i] == 'K')
		{
			this->_board[row][col] = King(row, col, WHITE);
		}
		else if (boardString[i] == 'k')
		{
			this->_board[row][col] = King(row, col, BLACK);
		}
		else if (boardString[i] == 'R')
		{
			this->_board[row][col] = Rook(row, col, WHITE);
		}
		else if (boardString[i] == 'r')
		{
			this->_board[row][col] = Rook(row, col, BLACK);
		}
	}
}

void Board::move(const int row, const int col)
{
}

void Board::printBoard()
{
}
