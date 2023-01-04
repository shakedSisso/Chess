#include "Knight.h"
#include "InvalidMoveException.h"

#define POSSIBLE_POSITIONS 8

Knight::Knight(const int row, const int col, const bool isWhite)
    : Piece(row, col, isWhite)
{
}

Knight::~Knight()
{
}

bool Knight::isLegalMove(const int row, const int col, const Board& board) const
{
	// creating two arrays that with every index from both arrays we have a place that the knight can move to by the rules of the game
	int possiblePlacesRows[POSSIBLE_POSITIONS] = {this->_row - 1, this->_row - 2, this->_row - 2, this->_row - 1, this->_row + 1, this->_row + 2, this->_row + 2, this->_row + 1};
	int possiblePlacesCols[POSSIBLE_POSITIONS] = {this->_col - 2, this->_col - 1, this->_col + 1, this->_col + 2, this->_col + 2, this->_col + 1, this->_col - 1, this->_col - 2};
	bool isValid = false;
	int i = 0;
	if (this->_row == row && this->_col == col) // checking if we are trying to move to the same place
	{
		throw InvalidMoveException(InvalidMoveException::types::SAME_PLACE);
	}
	for (i = 0; i < POSSIBLE_POSITIONS && !isValid; i++) // going through the possible allowed places and checking if the we have been given is among those allowed places
	{
		if (row == possiblePlacesRows[i] && col == possiblePlacesCols[i])
		{
			isValid = true;
		}
	}
	if (!isValid) // if the flag wasn't changed to true that means that the place we have been given is not a place the knight can move to by the rules of the game
	{
		throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
	}
	if (board.getPiece(row, col) != nullptr && board.getPiece(row, col)->getIsWhite() == this->_isWhite) // checking that we are not trying to move to a place that have a piece with the same color
	{
		throw InvalidMoveException(InvalidMoveException::types::SELF_EATING);
	}
	return true;
}

std::string Knight::toString() const
{
	if (this->_isWhite)
	{
		return "N";
	}
	return "n";
}
