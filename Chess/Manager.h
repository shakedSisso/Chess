#pragma once
#include "Player.h"
#include "Board.h"
#include <iostream>

class Manager
{
public:
	/*
	* Function: Manager
	* ----------------------------
	*   The function builds a new object of the class Manager. The function creates the objects of the white and black player and creates the board object and calls the buildBoard function
	*
	*   input: none
	*
	*   returns: builder.
	*/
	Manager();
	/*
	* Function: ~Manger
	* ----------------------------
	*   The function is the destructor for the object. The function deletes the dynamicly allocated players and board
	*
	*   input: none
	*
	*   returns: destructor.
	*/
	~Manager();
	/*
	* Function: handleMove
	* ----------------------------
	*   The function gets a string with two places on the board that represents a move (a org place and dst place). the function checks the current player and if the player "owns" the piece its trying to move 
	*	and then validates and performs the move using the move function of the board object.
	*	The function returns a string with a code, 0 if move is legal and was performed, 1 if move is legal and was performed and chess occured on the other player and any other number represents an error (match to the errors on InvalidMoveException)
	*
	*   const std::string move: the string of the places of the move
	*
	*   returns: std::string. A string with the result code of the move attempt as mentioned above
	*/
	std::string handleMove(const std::string move);
private:
	Player* _whitePlayer;
	Player* _blackPlayer;
	Board* _board;
	bool _isWhiteTurn;
};