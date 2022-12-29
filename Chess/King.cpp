#include "King.h"
#include "InvalidMoveException.h"

King::King(int row, int col, bool isWhite) 
	: Piece(row, col, isWhite)
{
}

King::~King()
{
}

bool King::isLegalMove(const int row, const int col, const Board& board) const
{
	if (this->_row == row && this->_col == col) // checking if we are trying to move to the same place
	{
		throw InvalidMoveException(InvalidMoveException::types::SAME_PLACE);
	}
	if (row > this->_row + 1 || row < this->_row - 1 || col > this->_col + 1 || col < this->_col - 1) // checking if we are trying to move the king to a place that is not one square away from the current location (against the king's movement ability)
	{
		throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
	}
	if (board.getPiece(row, col) != nullptr && board.getPiece(row, col)->getIsWhite() == this->_isWhite) // checking that we are not trying to move to a place that have a piece with the same color
	{
		throw InvalidMoveException(InvalidMoveException::types::SELF_EATING);
	}
	return true;
}

std::string King::toString() const
{
	if (this->_isWhite)
	{
		return "K";
	}
	return "k";
}

bool King::isChess(Board& board)
{
	int i = 0;
	int j = 0;
	bool result = false;
	Piece* piece;
	for ( i = 0; i < ROW_COL_SIZE; i++)
	{
		for ( j = 0; j < ROW_COL_SIZE; j++)
		{
			piece = board.getPiece(i, j);
			if (piece != nullptr && piece->getIsWhite() != this->_isWhite ) // checking if the current location contains a piece and that's the piece color is different than the king's color
			{
				try
				{
					piece->isLegalMove(this->_row, this->_col, board);
					return true; // if an exception wasn't thrown, that means that the current piece can move and theoraticly "eat" directly the king and thats a chess situation,
				}
				catch (InvalidMoveException& exception) // catching to avoid throwing exceptions on theoratical moves for checking chess
				{
					
				}
			}
		}
	}
	return false; // if we haven't returned true from within the loop that means that no piece on the board can currently threat directly the king
}
