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
	if (this->_isWhite) // checking if we are white in order to check direction of movement
	{
		if (this->_row + 2 < row) // checking if the place we are trying to go to is far from the current place by at least 3 rows (that means the move is not legal by the rules, a pawn can't move up or down more than two rows)
		{
			throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
		}
		if (this->_col != col && this->_row + 1 == row) // checking if we are eating a piece and moving diagonaly
		{
			if (this->_col - 1 == col || this->_col + 1 == col) // checking that we are not trying to move more than one place left or right (not legal by the rules)
			{
				if (board.getPiece(row, col) == nullptr) // checking that there is a piece on the place we are moving to diagonaly (by the rules, can only move diagonaly if there is a piece to eat)
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
			if (this->_didMove && this->_row + 2 == row) // checking if we've already did the first move and if so checking if we are trying to move up or down by two places (can only move by 2 on the first move by the rules)
			{
				throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
			}
			if (board.getPiece(row, col) != nullptr) // checking if there is a piece in front of it since it can only straight if there is not piece on the way
			{
				throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
			}
		}
	}
	else
	{
		if (this->_row - 2 > row) // checking if the place we are trying to go to is far from the current place by at least 3 rows (that means the move is not legal by the rules, a pawn can't move up or down more than two rows)
		{
			throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
		}
		if (this->_col != col && this->_row - 1 == row) // checking if we are eating a piece and moving diagonaly
		{
			if (this->_col - 1 == col || this->_col + 1 == col) // checking that we are not trying to move more than one place left or right (not legal by the rules)
			{
				if (board.getPiece(row, col) == nullptr) // checking that there is a piece on the place we are moving to diagonaly (by the rules, can only move diagonaly if there is a piece to eat)
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
			if (this->_didMove && this->_row - 2 == row) // checking if we've already did the first move and if so checking if we are trying to move up or down by two places (can only move by 2 on the first move by the rules)
			{
				throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
			}
			if (board.getPiece(row, col) != nullptr) // checking if there is a piece in front of it since it can only straight if there is not piece on the way
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
