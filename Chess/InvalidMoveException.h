#pragma once
#include <exception>
#include <iostream>

class InvalidMoveException : public std::exception
{
public:
	/*
	* Function: InvalidMoveException
	* ----------------------------
	*   The function builds a new object of the class InvalidMoveException with the exception's type
	*
	*   const int type: the type of the exception
	*
	*   returns: builder.
	*/
	InvalidMoveException(const int type);
	/*
	* Function: what
	* ----------------------------
	*   The function returns a string with explantions of what happend and why the exception was thrown
	*
	*   input: none
	*
	*   returns: std::string. An explanation of what happend
	*/
	std::string what();
	/*
	* Function: getType const
	* ----------------------------
	*   The function returns the current type of the exception
	*
	*   input: none
	*
	*   returns: int. The type of the exception
	*/
	int getType() const;
	enum types { NOT_PLAYER_PIECE = 2, SELF_EATING, SELF_CHESS, ILLEGAL_INDEX, ILLEGAL_MOVE, SAME_PLACE };
	static types type;
private:
	int _type;
};