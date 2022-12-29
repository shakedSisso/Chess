#include "Rook.h"
#include "InvalidMoveException.h"

Rook::Rook(const int row, const int col, const bool isWhite)
	: Piece(row, col, isWhite)
{
}

Rook::~Rook()
{
}

bool Rook::isLegalMove(const int row, const int col, const Board& board) const
{
	int i = 0;
	if (this->_row == row && this->_col == col) // checking if we are trying to move to the same place
	{
		throw InvalidMoveException(InvalidMoveException::types::SAME_PLACE);
	}
	if (row != this->_row && col != this->_col) // checking if we are trying to move to a place that is diagonal to the rook's location (against the rooks movement ability)
	{
		throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
	}
	if (board.getPiece(row, col) != nullptr && board.getPiece(row, col)->getIsWhite() == this->_isWhite) // checking that we are not trying to move to a place that have a piece with the same color
	{
		throw InvalidMoveException(InvalidMoveException::types::SELF_EATING);
	}
	if (this->_row < row) // checking if the rook is moving down the board (from a low row to a high row)
	{
		for (i = this->_row + 1; i < row; i++)
		{
			if (board.getPiece(i, col) != nullptr) // checking if there is a piece on the way that is not on the destination place
			{
				throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
			}
		}
	}
	else if (this->_row > row) // checking if the rook is moving up the board (from a high row to a low row)
	{
		for (i = this->_row - 1; i > row; i--) 
		{
			if (board.getPiece(i, col) != nullptr) // checking if there is a piece on the way that is not on the destination place
			{
				throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
			}
		}
	}
	
	if (this->_col < col) // checking if the rook is moving from left to right on the board (from a low col to a high col)
	{
		for (i = this->_col + 1; i < col; i++)
		{
			if (board.getPiece(row, i) != nullptr) // checking if there is a piece on the way that is not on the destination place
			{
				throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
			}
		}
	}
	else if (this->_col > col) // checking if the rook is moving from right to left on the board (from a high col to a low col)
	{
		for (i = this->_col - 1; i > col; i--)
		{
			if (board.getPiece(row, i) != nullptr) // checking if there is a piece on the way that is not on the destination place
			{
				throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
			}
		}
	}
	
	return true;
}

std::string Rook::toString() const
{
	if (this->_isWhite)
	{
		return "R";
	}
	return "r";
}
