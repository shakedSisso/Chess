#pragma once

class Player
{
public:
	Player(bool isWhite);
	~Player();
	void setTurn();
	bool getTurn();
	bool getIsWhite();
private:
	bool _isPlaying;
	bool _isWhite;
};