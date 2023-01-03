#pragma once
#include "Player.h"
#include "Board.h"
#include <iostream>

class Manager
{
public:
	Manager();
	~Manager();
	std::string handleMove(std::string move);
private:
	Player* _whitePlayer;
	Player* _blackPlayer;
	Board* _board;
	bool _isWhiteTurn;
};