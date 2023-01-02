#include "Bishop.h"
#include "InvalidMoveException.h"
#include <math.h>

Bishop::Bishop(const int row, const int col, const bool isWhite)
	: Piece(row, col, isWhite)
{
}

Bishop::~Bishop()
{
}

bool Bishop::isLegalMove(const int row, const int col, const Board& board) const
{
	int i = 0;
	if (this->_row == row && this->_col == col) // checking if we are trying to move to the same place
	{
		throw InvalidMoveException(InvalidMoveException::types::SAME_PLACE);
	}
	if (board.getPiece(row, col) != nullptr && board.getPiece(row, col)->getIsWhite() == this->_isWhite) // checking that we are not trying to move to a place that have a piece with the same color
	{
		throw InvalidMoveException(InvalidMoveException::types::SELF_EATING);
	}
	if (abs(this->_row - row) != abs(this->_col - col))
	{
		throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
	}
	if (this->_row < row && this->_col < col) 
	{
		for (i = 1; i < abs(this->_row - row); i++)
		{
			if (board.getPiece(this->_row + i, this->_col + i) != nullptr) // checking if there is a piece on the way that is not on the destination place
			{
				throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
			}
		}
	}
	else if (this->_row > row && this->_col < col)
	{
		for (i = 1; i < abs(this->_row - row); i++)
		{
			if (board.getPiece(this->_row - i, this->_col + i) != nullptr) // checking if there is a piece on the way that is not on the destination place
			{
				throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
			}
		}
	}
	if (this->_row > row && this->_col > col) // checking if the rook is moving from left to right on the board (from a low col to a high col)
	{
		for (i = 1; i < abs(this->_row - row); i++)
		{
			if (board.getPiece(this->_row - i, this->_col - i) != nullptr) // checking if there is a piece on the way that is not on the destination place
			{
				throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
			}
		}
	}
	else if (this->_row < row && this->_col > col) // checking if the rook is moving from right to left on the board (from a high col to a low col)
	{
		for (i = 1; i < abs(this->_row - row); i++)
		{
			if (board.getPiece(this->_row + i, this->_col - i) != nullptr) // checking if there is a piece on the way that is not on the destination place
			{
				throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
			}
		}
	}
	return true;
}

std::string Bishop::toString() const
{
	if (this->_isWhite)
	{
		return "B";
	}
	return "b";
}
