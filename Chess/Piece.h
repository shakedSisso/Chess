#pragma once
#include <iostream>
#include "Board.h"

class Board;

class Piece
{
public:
	/*
	* Function: Piece
	* ----------------------------
	*   The function builds a new object of the class Piece with the piece's row and col on the board and its color (black or white using a bool)
	*
	*   const int row: the row of the piece on the board
	*   const int col: the col of the piece on the board
	*   const bool isWhite: the color of the piece. true for white, false for black
	*
	*   returns: builder.
	*/
	Piece(const int row, const int col, const bool isWhite);
	/*
	* Function: ~Piece
	* ----------------------------
	*   The function is the destructor for the object
	*
	*   input: none
	*
	*   returns: destructor.
	*/
	~Piece();
	/*
	* Function: getIsWhite const
	* ----------------------------
	*   The function returns the color of the piece
	*
	*   input: none
	*
	*   returns: bool. True if the piece is white, false if the piece is black
	*/
	bool getIsWhite() const;
	// isLegalMove is a pure virtual function, documantion about that functions can be found in the header files of the class that inherit the class piece
	virtual bool isLegalMove(const int row, const int col, const Board& board) const = 0;
	// toString is a pure virtual function, documantion about that functions can be found in the header files of the class that inherit the class piece
	virtual std::string toString() const = 0;
	/*
	* Function: setPlace
	* ----------------------------
	*   The function gets a place on the board (row and col) and sets this as the place of the piece
	*
	*   const int row: the row to set
	*	const int col: the col to set
	*
	*   returns: void.
	*/
	void setPlace(const int row, const int col);
	/*
	* Function: getRow const
	* ----------------------------
	*   The function returns the current row of the piece on the board
	*
	*   input: none
	*
	*   returns: int. The number of the row of the piece on the board
	*/
	int getRow() const;
	/*
	* Function: getCol const
	* ----------------------------
	*   The function returns the current col of the piece on the board
	*
	*   input: none
	*
	*   returns: int. The number of the col of the piece on the board
	*/
	int getCol() const;
protected:
	bool _isWhite;
	int _row;
	int _col;
};