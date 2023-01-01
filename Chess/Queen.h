#pragma once
#include "Piece.h"
#include "Board.h"

class Queen : public Piece
{
public:
    /*
    * Function: Queen
    * ----------------------------
    *   The function builds a new object of the class Queen with the bishop's row and col on the board and its color (black or white using a bool)
    *
    *   const int row: the row of the queen on the board
    *   const int col: the col of the queen on the board
    *   const bool isWhite: the color of the queen. true for white, false for black
    *
    *   returns: builder.
    */
    Queen(const int row, const int col, const bool isWhite);
    /*
    * Function: ~Queen
    * ----------------------------
    *   The function is the destructor for the object
    *
    *   input: none
    *
    *   returns: destructor.
    */
    ~Queen();

    bool isLegalMove(const int row, const int col, const Board& board) const override;

    /*
    * Function: toString
    * ----------------------------
    *   The function returns a string with a textual representation of the piece. Q for white, q for black
    *
    *   input: none
    *
    *   returns: std::string. The textual representation of the piece
    */
    std::string toString() const override;
};