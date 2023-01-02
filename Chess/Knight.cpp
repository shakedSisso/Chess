#include "Knight.h"
#include "InvalidMoveException.h"

#define POSSIBLE_POSITIONS 8
//#define POSSIBLE_COLS 4

Knight::Knight(const int row, const int col, const bool isWhite)
    : Piece(row, col, isWhite)
{
}

Knight::~Knight()
{
}

bool Knight::isLegalMove(const int row, const int col, const Board& board) const
{
	//int possiblePlacesRows[POSSIBLE_ROWS] = { this->_row + 1, this->_row - 1, this->_row  + 2, this->_row - 1 };
	//int possiblePlacesCols[POSSIBLE_COLS] = { this->_col + 1, this->_col - 1, this->_col + 2, this->_col - 2 };
	int possiblePlacesRows[POSSIBLE_POSITIONS] = {this->_row - 1, this->_row - 2, this->_row - 2, this->_row - 1, this->_row + 1, this->_row + 2, this->_row + 2, this->_row + 1};
	int possiblePlacesCols[POSSIBLE_POSITIONS] = {this->_col - 2, this->_col - 1, this->_col + 1, this->_col + 2, this->_col + 2, this->_col + 1, this->_col - 1, this->_col - 2};
	bool isValid = false;
	int i = 0;
	if (this->_row == row && this->_col == col) // checking if we are trying to move to the same place
	{
		throw InvalidMoveException(InvalidMoveException::types::SAME_PLACE);
	}
	for (i = 0; i < POSSIBLE_POSITIONS && !isValid; i++)
	{
		if (row == possiblePlacesRows[i] && col == possiblePlacesCols[i])
		{
			isValid = true;
		}
	}
	if (!isValid)
	{
		throw InvalidMoveException(InvalidMoveException::types::ILLEGAL_MOVE);
	}
	
}

std::string Knight::toString() const
{
	if (this->_isWhite)
	{
		return "N";
	}
	return "n";
}
