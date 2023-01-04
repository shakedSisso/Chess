#pragma once
#include "Piece.h"
#include "Board.h"

class Pawn : public Piece
{
public:
    /*
    * Function: Pawn
    * ----------------------------
    *   The function builds a new object of the class Pawn with the pawn's row and col on the board and its color (black or white using a bool) and its direction of movement (true for up, false for down)
    *
    *   const int row: the row of the pawn on the board
    *   const int col: the col of the pawn on the board
    *   const bool isWhite: the color of the pawn. true for white, false for black
    *   const bool isMovingUp: the direction of movement of the pawn. true for up on the board, false for down the board
    *
    *   returns: builder.
    */
    Pawn(const int row, const int col, const bool isWhite, const bool isMovingUp);
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

    /*
    * Function: isLegalMove
    * ----------------------------
    *   The function gets a row and col on the board to check the move to and the board to check for other pieces. The function checks if the pawn can move to that location, and returns true if it cans.
    *   Otherwise, if the move is not valid it will throw an InvalidMoveException with according type of reason why the move is not legal
    *
    *   const int row: the row to move the pawn to
    *   const int col: the col to move the pawn to
    *   const Board& board: the reference to the playing board to check for other piece on the board that can invalidate the move
    *
    *   returns: bool. true if the move is valid and will throw an exception (InvalidMoveException) with the type if the move is not valid
    */
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
    /*
    * Function: setDidMoveToTrue
    * ----------------------------
    *   The function sets the didMove field to true
    *
    *   inout: none
    *
    *   returns: void.
    */
    void setDidMoveToTrue();
private:
    bool _didMove;
    bool _isMovingUp;
};