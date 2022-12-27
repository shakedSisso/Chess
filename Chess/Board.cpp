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
	this->_board = new Piece ** [ROW_COL_SIZE];
	for (i = 0; i < ROW_COL_SIZE; i++) {
		this->_board[i] = new Piece*[ROW_COL_SIZE];
		for (j = 0; j < ROW_COL_SIZE; j++)
		{
			this->_board[i][j] = nullptr;
		}
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
	int j = 0;
	int stringIndex = 0;
	for (i = 0; i < ROW_COL_SIZE; i++)
	{
		for ( j = 0; j < ROW_COL_SIZE; j++)
		{
			stringIndex = i / ROW_COL_SIZE + i % ROW_COL_SIZE;
			if (boardString[stringIndex] == 'K')
            {
				this->_board[i][j] = new King(i, j, WHITE);
            }
            else if (boardString[stringIndex] == 'k')
            {
				this->_board[i][j] = new King(i, j, BLACK);
            }
            else if (boardString[stringIndex] == 'R')
            {
				this->_board[i][j] = new Rook(i, j, WHITE);
            }
            else if (boardString[stringIndex] == 'r')
            {
				this->_board[i][j] = new Rook(i, j, BLACK);
            }
		}
	}
}

void Board::move(const int row, const int col)
{
}

void Board::printBoard()
{
}
