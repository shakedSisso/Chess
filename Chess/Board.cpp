#include "Board.h"
#include "Rook.h"
#include "King.h"
#include "InvalidMoveException.h"
#include <iostream>

#define ROW_COL_SIZE 8
#define MAX_INDEX 7
#define WHITE true
#define BLACK false

Board::Board()
	: _whiteKing(nullptr), _blackKing(nullptr)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW_COL_SIZE; i++) {
		for (j = 0; j < ROW_COL_SIZE; j++)
		{
			this->_board[i][j] = nullptr;
		}
	}
	
}

Board::~Board()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW_COL_SIZE; i++)
	{
		for (j = 0; j < ROW_COL_SIZE; j++)
		{
			if (this->_board[i][j] != nullptr)
			{
				delete this->_board[i][j];
				this->_board[i][j] = nullptr;
			}
		}
	}
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
			stringIndex = i * ROW_COL_SIZE + j;
			if (boardString[stringIndex] == 'K')
            {
				this->_board[i][j] = new King(i, j, WHITE);
				this->_whiteKing = this->_board[i][j];
            }
            else if (boardString[stringIndex] == 'k')
            {
				this->_board[i][j] = new King(i, j, BLACK);
				this->_blackKing = this->_board[i][j];
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

void Board::move(const int orgRow, const int orgCol, const int dstRow, const int dstCol)
{
	Piece* pieceToMove = nullptr;
	Piece* pieceToDelete = nullptr;
	if (orgRow > MAX_INDEX || orgRow < 0 || orgCol > MAX_INDEX || orgCol < 0 || dstRow > MAX_INDEX || dstRow < 0 || dstCol > MAX_INDEX || dstCol < 0)
	{
		throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_INDEX);
	}
	pieceToMove = this->_board[orgRow][orgCol];
	if (pieceToMove == nullptr)
	{
		throw InvalidMoveException(InvalidMoveException::types::NOT_PLAYER_PIECE);
	}
	pieceToMove->isLegalMove(dstRow, dstCol, *this);
	pieceToDelete = this->_board[dstRow][dstCol];
	this->_board[dstRow][dstCol] = pieceToMove;
	this->_board[orgRow][orgCol] = nullptr;
	pieceToMove->setPlace(dstRow, dstCol);
	if (pieceToMove->getIsWhite())
	{
		if (((King*)(this->_whiteKing))->isChess(*this))
		{
			this->_board[orgRow][orgCol] = pieceToMove;
			this->_board[dstRow][dstCol] = pieceToDelete;
			pieceToMove->setPlace(orgRow, orgCol);
			throw InvalidMoveException(InvalidMoveException::types::SELF_CHESS);
		}
		if (((King*)(this->_blackKing))->isChess(*this))
		{
			std::cout << "Chess on the black player" << std::endl; // DEBUG
		}
	}
	else
	{
		if (((King*)(this->_blackKing))->isChess(*this))
		{
			this->_board[orgRow][orgCol] = pieceToMove;
			this->_board[dstRow][dstCol] = pieceToDelete;
			pieceToMove->setPlace(orgRow, orgCol);
			throw InvalidMoveException(InvalidMoveException::types::SELF_CHESS);
		}
		if (((King*)(this->_whiteKing))->isChess(*this))
		{
			std::cout << "Chess on the white player" << std::endl; // DEBUG
		}
	}
	if (pieceToDelete != nullptr)
	{
		delete pieceToDelete;
	}

}

void Board::printBoard()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW_COL_SIZE; i++)
	{
		for ( j = 0; j < ROW_COL_SIZE; j++)
		{
			if (this->_board[i][j] == nullptr)
			{
				std::cout << "#";
			}
			else
			{
				std::cout << this->_board[i][j]->toString();
			}
			
			
		}
		std::cout << std::endl;
	}
}

Piece* Board::getPiece(const int row, const int col) const
{
	return this->_board[row][col];
}
