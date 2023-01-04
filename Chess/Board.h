#pragma once
#include <iostream>
#include "Piece.h"

#define ROW_COL_SIZE 8

class Piece;

class Board
{
public:
	/*
	* Function: Board
	* ----------------------------
	*   The function builds a new object of the class Board. The function inits the kings points with nullptr and inits the pieces 2d array with null
	*
	*   input: none
	*
	*   returns: builder.
	*/
	Board();
	/*
	* Function: ~Piece
	* ----------------------------
	*   The function is the destructor for the object. The function deletes the dynamicly allocated piece on the board
	*
	*   input: none
	*
	*   returns: destructor.
	*/
	~Board();
	/*
	* Function: buildBoard
	* ----------------------------
	*   The function gets a string and the function builds the board according to the string
	*
	*   const std::string boardString: the string to build upon
	*
	*   returns: void.
	*/
	void buildBoard(const std::string boardString);
	/*
	* Function: move
	* ----------------------------
	*   The function gets a two places on the board (each of them contains a row and a col). 
	*	The function validates that the original place contains a piece (If not, the function throws an InvalidMoveException).
	*	Then the function checks with the piece itself if its able to move to the desitination place.
	*	Then the function checks if the move makes a chess on the player itself (the move is canceled and an InvalidMoveException is thrown)
	*	and if the move makes a chess on the opponent. The function returns an int of 0 or 1. 0 if the move is valid, 1 if the move is valid and chess has occured on the other player.
	*
	*   const int orgRow: the original row of the piece to move
	*	const int orgCol: the original col of the piece to move
	*	const int dstRow: the row to move the piece to
	*	const int dstCol: the col to move the piece to
	*
	*   returns: int. 0 or 1.  0 if the move is valid, 1 if the move is valid and chess has occured on the other player
	*/
	int move(const int orgRow, const int orgCol, const int dstRow, const int dstCol);

	void printBoard(); // function for debugging only
	/*
	* Function: getPiece const
	* ----------------------------
	*   The function gets a row and a col on the board and returns the piece on that places on the board
	*
	*   const int row: the row of the desired piece
	*	const int col: the col of the desired piece
	*
	*   returns: Piece*. The pointer to the piece on the location given
	*/
	Piece* getPiece(const int row, const int col) const;

private:
	Piece* _whiteKing;
	Piece* _blackKing;
	Piece* _board[ROW_COL_SIZE][ROW_COL_SIZE];
};