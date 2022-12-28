#pragma once
#include <exception>
#include <iostream>

class InvalidMoveException : public std::exception
{
public:
	InvalidMoveException(const int type);
	std::string what();
	int getType() const;
	static enum types;
private:
	int _type;
};