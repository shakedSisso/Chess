#pragma once
#include "Board.h"
#include "Piece.h"

class Knight : public Piece
{
public:
    /*
    * Function: Knight
    * ----------------------------
    *   The function builds a new object of the class Knight with the knight's row and col on the board and its color (black or white using a bool)
    *
    *   const int row: the row of the knight on the board
    *   const int col: the col of the knight on the board
    *   const bool isWhite: the color of the knight. true for white, false for black
    *
    *   returns: builder.
    */
	Knight(const int row, const int col, const bool isWhite);
    /*
    * Function: ~Knight
    * ----------------------------
    *   The function is the destructor for the object
    *
    *   input: none
    *
    *   returns: destructor.
    */
	~Knight();

	bool isLegalMove(const int row, const int col, const Board& board) const override;

    /*
    * Function: toString
    * ----------------------------
    *   The function returns a string with a textual representation of the piece. N for white, n for black
    *
    *   input: none
    *
    *   returns: std::string. The textual representation of the piece
    */
    std::string toString() const override;
};