#include "Player.h"

Player::Player(bool isWhite)
	: _isWhite(isWhite), _isPlaying(false)
{
}

Player::~Player()
{
}

void Player::setTurn()
{
	this->_isPlaying = !this->_isPlaying;
}

bool Player::getTurn()
{
	return this->_isPlaying;
}

bool Player::getIsWhite()
{
	return this->_isWhite;
}
