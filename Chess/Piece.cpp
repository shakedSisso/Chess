#include "Piece.h"

#define BIGGEST_INDEX 7

Piece::Piece(const int row, const int col, const bool isWhite) :
	_row(row), _col(col), _isWhite(isWhite), _isNull(true)
{
}

Piece::Piece() :
	_row(0), _col(0), _isWhite(true), _isNull(true)
{
}

Piece::~Piece()
{
}

bool Piece::getIsWhite() const
{
	return this->_isWhite;
}

bool Piece::isLegalMove(const int row, const int col) const
{
	return false;
}

std::ostream& Piece::operator<<(std::ostream& os) const
{
	os << "#";
	return os;
}


void Piece::setPlace(const int row, const int col)
{
	if (row < 0 || row > BIGGEST_INDEX || col < 0 || col > BIGGEST_INDEX)
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
