#pragma once
#include "Piece.h"
#include "Board.h"

class Pawn : public Piece
{
public:
    /*
    * Function: Pawn
    * ----------------------------
    *   The function builds a new object of the class Pawn with the pawn's row and col on the board and its color (black or white using a bool)
    *
    *   const int row: the row of the pawn on the board
    *   const int col: the col of the pawn on the board
    *   const bool isWhite: the color of the pawn. true for white, false for black
    *
    *   returns: builder.
    */
    Pawn(const int row, const int col, const bool isWhite);
    /*
    * Function: ~Pawn
    * ----------------------------
    *   The function is the destructor for the object
    *
    *   input: none
    *
    *   returns: destructor.
    */
    ~Pawn();

    bool isLegalMove(const int row, const int col, const Board& board) const override;

    /*
    * Function: toString
    * ----------------------------
    *   The function returns a string with a textual representation of the piece. P for white, p for black
    *
    *   input: none
    *
    *   returns: std::string. The textual representation of the piece
    */
    std::string toString() const override;
};