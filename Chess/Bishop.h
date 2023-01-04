#pragma once
#include "Board.h"
#include "Piece.h"

class Bishop : public Piece
{
public:
    /*
    * Function: Bishop
    * ----------------------------
    *   The function builds a new object of the class Bishop with the bishop's row and col on the board and its color (black or white using a bool)
    *
    *   const int row: the row of the bishop on the board
    *   const int col: the col of the bishop on the board
    *   const bool isWhite: the color of the bishop. true for white, false for black
    *
    *   returns: builder.
    */
	Bishop(const int row, const int col, const bool isWhite);
    /*
    * Function: ~Bishop
    * ----------------------------
    *   The function is the destructor for the object
    *
    *   input: none
    *
    *   returns: destructor.
    */
	~Bishop();

    /*
    * Function: isLegalMove
    * ----------------------------
    *   The function gets a row and col on the board to check the move to and the board to check for other pieces. The function checks if the bishop can move to that location, and returns true if it cans.
    *   Otherwise, if the move is not valid it will throw an InvalidMoveException with according type of reason why the move is not legal
    *
    *   const int row: the row to move the bishop to
    *   const int col: the col to move the bishop to
    *   const Board& board: the reference to the playing board to check for other piece on the board that can invalidate the move
    *
    *   returns: bool. true if the move is valid and will throw an exception (InvalidMoveException) with the type if the move is not valid
    */
	bool isLegalMove(const int row, const int col, const Board& board) const override;

    /*
    * Function: toString
    * ----------------------------
    *   The function returns a string with a textual representation of the piece. B for white, b for black
    *
    *   input: none
    *
    *   returns: std::string. The textual representation of the piece
    */
    std::string toString() const override;
};