#pragma once
#include <exception>
#include <iostream>

class InvalidMoveException : public std::exception
{
public:
	InvalidMoveException(const int type);
	std::string what();
	int getType() const;
	enum types { NOT_PLAYER_PIECE = 2, SELF_EATING, SELF_CHESS, ILLEGAL_INDEX, ILLEGAL_MOVE, SAME_PLACE };
	static types type;
private:
	int _type;
};