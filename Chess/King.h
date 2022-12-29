#pragma once
#include "Piece.h"

class King : public Piece
{
public:
    /*
    * Function: King
    * ----------------------------
    *   The function builds a new object of the class King with the king's row and col on the board and its color (black or white using a bool)
    *
    *   const int row: the row of the king on the board
    *   const int col: the col of the king on the board
    *   const bool isWhite: the color of the king. true for white, false for black
    *
    *   returns: builder.
    */
	King(const int row, const int col, const bool isWhite);
   /*
   * Function: ~King
   * ----------------------------
   *   The function is the destructor for the object
   *
   *   input: none
   *
   *   returns: destructor.
   */
	~King();
    /*
    * Function: isLegalMove
    * ----------------------------
    *   The function gets a row and col on the board to check the move to and the board to check for other pieces. The function checks if the king can move to that location, and returns true if it cans.
    *   Otherwise, if the move is not valid it will throw an InvalidMoveException with according type of reason why the move is not legal
    *
    *   const int row: the row to move the king to
    *   const int col: the col to move the king to
    *   const Board& board: the reference to the playing board to check for other piece on the board that can invalidate the move
    *
    *   returns: bool. true if the move is valid and will throw an exception (InvalidMoveException) with the type if the move is not valid
    */
	bool isLegalMove(const int row, const int col,  const Board& board) const override;
    /*
    * Function: toString
    * ----------------------------
    *   The function returns a string with a textual representation of the piece. K for white, k for black
    *
    *   input: none
    *
    *   returns: std::string. The textual representation of the piece
    */
	std::string toString() const override;
    /*
    * Function: isLegalMove
    * ----------------------------
    *   The function gets the board to check for other pieces. The function checks if in the current state of the board, the king is under chess. The function returns true if the king is in chess and false otherwise
    *
    *   const Board& board: the reference to the playing board to check for other piece on the board that can put the king in chess
    *
    *   returns: bool. true if the king is under chess, false otherwise
    */
	bool isChess(Board& board);
};