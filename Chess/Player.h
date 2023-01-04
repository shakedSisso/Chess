#pragma once

class Player
{
public:
	/*
	* Function: Player
	* ----------------------------
	*   The function builds a new object of the class Player with the player's color (black or white using a bool)
	*
	*   const bool isWhite: the color of the player. true for white, false for black
	*
	*   returns: builder.
	*/
	Player(bool isWhite);
	/*
	* Function: ~Player
	* ----------------------------
	*   The function is the destructor for the object
	*
	*   input: none
	*
	*   returns: destructor.
	*/
	~Player();
	/*
	* Function: getIsWhite const
	* ----------------------------
	*   The function returns the color of the player
	*
	*   input: none
	*
	*   returns: bool. True if the player is white, false if the player is black
	*/
	bool getIsWhite() const;
private:
	bool _isWhite;
};