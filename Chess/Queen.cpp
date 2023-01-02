#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "InvalidMoveException.h"

Queen::Queen(const int row, const int col, const bool isWhite)
	: Piece(row, col, isWhite)
{
}

Queen::~Queen()
{
}

bool Queen::isLegalMove(const int row, const int col, const Board& board) const
{
	Piece* testPiece = nullptr;
	if (this->_row == row && this->_col == col) // checking if we are trying to move to the same place
	{
		throw InvalidMoveException(InvalidMoveException::types::SAME_PLACE);
	}
	if (board.getPiece(row, col) != nullptr && board.getPiece(row, col)->getIsWhite() == this->_isWhite) // checking that we are not trying to move to a place that have a piece with the same color
	{
		throw InvalidMoveException(InvalidMoveException::types::SELF_EATING);
	}
	if ((this->_row == row && this->_col != col) || (this->_row != row && this->_col == col))
	{
		try
		{
			testPiece = new Rook(this->_row, this->_col, this->_isWhite);
			testPiece->isLegalMove(row, col, board);
		}
		catch (InvalidMoveException& exception)
		{
			delete testPiece;
			throw exception;
		}
	}
	else
	{
		try
		{
			testPiece = new Bishop(this->_row, this->_col, this->_isWhite);
			testPiece->isLegalMove(row, col, board);
		}
		catch (InvalidMoveException& exception)
		{
			delete testPiece;
			throw exception;
		}
	}
	delete testPiece;
	return true;
}

std::string Queen::toString() const
{
	if (this->_isWhite)
	{
		return "Q";
	}
	return "q";
}
