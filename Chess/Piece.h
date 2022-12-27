#pragma once


class Piece
{
public:
	Piece(const int row, const int col, const bool isWhite);
	Piece();
	~Piece();
	bool getIsWhite() const;
	virtual bool isLegalMove(const int row, const int col) const;
	void setPlace(const int row, const int col);
	int getRow() const;
	int getCol() const;
protected:
	bool _isWhite;
	int _row;
	int _col;
};