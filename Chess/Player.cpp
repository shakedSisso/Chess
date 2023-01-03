#include "Player.h"

Player::Player(bool isWhite)
	: _isWhite(isWhite)
{
}

Player::~Player()
{
}

bool Player::getIsWhite() const
{
	return this->_isWhite;
}
