#include "Pawn.h"
#include "InvalidMoveException.h"

Pawn::Pawn(const int row, const int col, const bool isWhite)
	: Piece(row, col, isWhite), _didMove(false)
{
}

Pawn::~Pawn()
{
}

bool Pawn::isLegalMove(const int row, const int col, const Board& board) const
{
	if (this->_row == row && this->_col == col) // checking if we are trying to move to the same place
	{
		throw InvalidMoveException(InvalidMoveException::types::SAME_PLACE);
	}
	if (board.getPiece(row, col) != nullptr && board.getPiece(row, col)->getIsWhite() == this->_isWhite) // checking that we are not trying to move to a place that have a piece with the same color
	{
		throw InvalidMoveException(InvalidMoveException::types::SELF_EATING);
	}
	if (this->_isWhite)
	{
		if (this->_row + 2 < row)
		{
			throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
		}
		if (this->_col != col && this->_row + 1 == row)
		{
			if (this->_col - 1 == col || this->_col + 1 == col)
			{
				if (board.getPiece(row, col) == nullptr)
				{
					throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
				}
			}
			else
			{
				throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
			}
		}
		else
		{
			if (this->_didMove && this->_row + 2 == row)
			{
				throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
			}
		}
	}
	else
	{
		if (this->_row - 2 > row)
		{
			throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
		}
		if (this->_col != col && this->_row - 1 == row)
		{
			if (this->_col - 1 == col || this->_col + 1 == col)
			{
				if (board.getPiece(row, col) == nullptr)
				{
					throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
				}
			}
			else
			{
				throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
			}
		}
		else
		{
			if (this->_didMove && this->_row - 2 == row)
			{
				throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
			}
		}
	}
	return true;
}

void Pawn::setDidMoveToTrue()
{
	this->_didMove = true;
}

std::string Pawn::toString() const
{
	if (this->_isWhite)
	{
		return "P";
	}
	return "p";
}
