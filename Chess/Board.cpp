#include "Board.h"
#include "Rook.h"
#include "King.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "Pawn.h"
#include "InvalidMoveException.h"

#define MAX_INDEX 7
#define WHITE true
#define BLACK false
#define CHESS 1
#define VALID 0

Board::Board()
	: _whiteKing(nullptr), _blackKing(nullptr)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW_COL_SIZE; i++) {
		for (j = 0; j < ROW_COL_SIZE; j++) // initing every place on the board with nullptr
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
			if (this->_board[i][j] != nullptr) // checking that there is a piece on that place on the board
			{
				delete this->_board[i][j];
				this->_board[i][j] = nullptr;
			}
		}
	}
}

void Board::buildBoard(const std::string boardString)
{
	int i = 0;
	int j = 0;
	int stringIndex = 0;
	for (i = 0; i < ROW_COL_SIZE; i++)
	{
		for ( j = 0; j < ROW_COL_SIZE; j++)
		{
			stringIndex = i * ROW_COL_SIZE + j; // calculating the index of the current place in the board on the given board's textual representation
			// A BIG LETTER REPRESENTS A WHITE PIECE AND A SMALL LETTER REPRESENTS A SMALL PIECE
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
			else if (boardString[stringIndex] == 'N')
			{
				this->_board[i][j] = new Knight(i, j, WHITE);
			}
			else if (boardString[stringIndex] == 'n')
			{
				this->_board[i][j] = new Knight(i, j, BLACK);
			}
			else if (boardString[stringIndex] == 'B')
			{
				this->_board[i][j] = new Bishop(i, j, WHITE);
			}
			else if (boardString[stringIndex] == 'b')
			{
				this->_board[i][j] = new Bishop(i, j, BLACK);
			}
			else if (boardString[stringIndex] == 'Q')
			{
				this->_board[i][j] = new Queen(i, j, WHITE);
			}
			else if (boardString[stringIndex] == 'q')
			{
				this->_board[i][j] = new Queen(i, j, BLACK);
			}
			else if (boardString[stringIndex] == 'P')
			{
				this->_board[i][j] = new Pawn(i, j, WHITE);
			}
			else if (boardString[stringIndex] == 'p')
			{
				this->_board[i][j] = new Pawn(i, j, BLACK);
			}
		}
	}
}

int Board::move(const int orgRow, const int orgCol, const int dstRow, const int dstCol)
{
	Piece* pieceToMove = nullptr;
	Piece* pieceToDelete = nullptr;
	if (orgRow > MAX_INDEX || orgRow < 0 || orgCol > MAX_INDEX || orgCol < 0 || dstRow > MAX_INDEX || dstRow < 0 || dstCol > MAX_INDEX || dstCol < 0) // checking that all rows and cols given are valid
	{
		throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_INDEX);
	}
	pieceToMove = this->_board[orgRow][orgCol];
	if (pieceToMove == nullptr) // checking that there is a piece on that place on the board
	{
		throw InvalidMoveException(InvalidMoveException::types::NOT_PLAYER_PIECE);
	}
	pieceToMove->isLegalMove(dstRow, dstCol, *this); // if the move will not be legal, an InvalidMoveException will be thrown and this function execution will terminate and the move won't be completed
	pieceToDelete = this->_board[dstRow][dstCol]; // saving the piece on the desitination location for its deallocation and in incase will need to revert the board to it's original state
	this->_board[dstRow][dstCol] = pieceToMove;
	this->_board[orgRow][orgCol] = nullptr;
	pieceToMove->setPlace(dstRow, dstCol); // changing the row and col of the piece we are moving to the dst row and col
	if (pieceToMove->getIsWhite()) // checking the color of the piece we are moving
	{
		if (((King*)(this->_whiteKing))->isChess(*this)) // checking if the move performs chess on its own king
		{
			// Reverting the move
			this->_board[orgRow][orgCol] = pieceToMove;
			this->_board[dstRow][dstCol] = pieceToDelete;
			pieceToMove->setPlace(orgRow, orgCol); // reverting the location of the piece in its vars
			throw InvalidMoveException(InvalidMoveException::types::SELF_CHESS);
		}
		if (((King*)(this->_blackKing))->isChess(*this)) // checking if the move performs chess on the other king
		{
			return CHESS;
		}
	}
	else
	{
		if (((King*)(this->_blackKing))->isChess(*this)) // checking if the move performs chess on its own king
		{
			// Reverting the move
			this->_board[orgRow][orgCol] = pieceToMove;
			this->_board[dstRow][dstCol] = pieceToDelete;
			pieceToMove->setPlace(orgRow, orgCol); // reverting the location of the piece in its vars
			throw InvalidMoveException(InvalidMoveException::types::SELF_CHESS);
		}
		if (((King*)(this->_whiteKing))->isChess(*this)) // checking if the move performs chess on the other king
		{
			return CHESS;
		}
	}
	if (pieceToDelete != nullptr) // checking if the place the piece has moved there was another piece. (Validated on the piece isLegalMove function that the removed piece is from the other color)
	{
		delete pieceToDelete;
	}
	if (dynamic_cast<const Pawn*>(pieceToMove) != nullptr) // checking if the piece we are moving is a pawn and if so, change the didMove field to true
	{
		((Pawn*)pieceToMove)->setDidMoveToTrue();
	}
	return VALID;
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
