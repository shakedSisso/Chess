#include "Rook.h"
#include "InvalidMoveException.h"

Rook::Rook(const int row, const int col, const bool isWhite)
	: Piece(row, col, isWhite)
{
}

Rook::~Rook()
{
}

bool Rook::isLegalMove(const int row, const int col, Board& board) const
{
	int i = 0;
	if (this->_row == row && this->_col == col)
	{
		throw InvalidMoveException(InvalidMoveException::types::SAME_PLACE);
	}
	if (row != this->_row && col != this->_col)
	{
		throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
	}
	if (board.getPiece(row, col) != nullptr && board.getPiece(row, col)->getIsWhite() == this->_isWhite)
	{
		throw InvalidMoveException(InvalidMoveException::types::SELF_EATING);
	}
	if (this->_row < row)
	{
		for (i = this->_row + 1; i < row; i++)
		{
			if (board.getPiece(i, col) != nullptr)
			{
				throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
			}
		}
	}
	else if (this->_row > row)
	{
		for (i = this->_row - 1; i > row; i--)
		{
			if (board.getPiece(i, col) != nullptr)
			{
				throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
			}
		}
	}
	
	if (this->_col < col)
	{
		for (i = this->_col + 1; i < col; i++)
		{
			if (board.getPiece(row, i) != nullptr)
			{
				throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
			}
		}
	}
	else if (this->_col > col)
	{
		for (i = this->_col - 1; i > col; i--)
		{
			if (board.getPiece(row, i) != nullptr)
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
