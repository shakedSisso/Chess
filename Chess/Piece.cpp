#include "Piece.h"

#define BIGGEST_INDEX 7

Piece::Piece(const int row, const int col, const bool isWhite) :
	_row(row), _col(col), _isWhite(isWhite)
{
}

Piece::~Piece()
{
}

bool Piece::getIsWhite() const
{
	return this->_isWhite;
}

void Piece::setPlace(const int row, const int col)
{
	if (row < 0 || row > BIGGEST_INDEX || col < 0 || col > BIGGEST_INDEX) // validating input
	{
		return;
	}
	this->_row = row;
	this->_col = col;
}

int Piece::getRow() const
{
	return this->_row;
}

int Piece::getCol() const
{
	return this->_col;
}
