#pragma once

class Player
{
public:
	Player(bool isWhite);
	~Player();
	bool getIsWhite() const;
private:
	bool _isWhite;
};