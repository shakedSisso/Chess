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
	// we are using a demo rook and a demo bishop to check the queen's movement since that the queen's movement abilities are the combined abilities of the bishop and the rook
	Piece* testPiece = nullptr;
	if (this->_row == row && this->_col == col) // checking if we are trying to move to the same place
	{
		throw InvalidMoveException(InvalidMoveException::types::SAME_PLACE);
	}
	if (board.getPiece(row, col) != nullptr && board.getPiece(row, col)->getIsWhite() == this->_isWhite) // checking that we are not trying to move to a place that have a piece with the same color
	{
		throw InvalidMoveException(InvalidMoveException::types::SELF_EATING);
	}
	if ((this->_row == row && this->_col != col) || (this->_row != row && this->_col == col)) // checking if we are moving straight (same as a rook)
	{
		try
		{
			testPiece = new Rook(this->_row, this->_col, this->_isWhite); // creating a demo rook to test the movement
			testPiece->isLegalMove(row, col, board);
		}
		catch (InvalidMoveException& exception) // if an exception was thrown from the isLegalMove that means that the queen can't make that move
		{
			delete testPiece;
			throw exception;
		}
	}
	else // if we are not moving straight that must means that either we are trying to move diagonaly or to a place the queen can't move to by the rules (a thing that we'll be raised by the bishop's isLegalMove function)
	{
		try
		{
			testPiece = new Bishop(this->_row, this->_col, this->_isWhite); // creating a demo bishop to test the movement
			testPiece->isLegalMove(row, col, board);
		}
		catch (InvalidMoveException& exception) // if an exception was thrown from the isLegalMove that means that the queen can't make that move
		{
			delete testPiece;
			throw exception;
		}
	}
	delete testPiece; // testPiece won't by nullptr at this point since that if we have reached this point that means there was no InvalidMoveException thrown and that the move is valid and if its valid it means we created a demo piece to check it
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
