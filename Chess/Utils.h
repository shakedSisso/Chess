#pragma once
#include <iostream>

class Utils
{
public:
	/*
	* Function: static changeStringToPlaces
	* ----------------------------
	*   The function gets a string with two places on the board. The function translates the places on the board (represented by a letter for the col and a number for the row) to two numbers, the row first than the col.
	*	The function returns a pointer to an array with 4 cells, the first two cells are the row and col of the first place on the string and the last two cells are the row and col of the second place on the string
	*
	*   const std::string place: the string of the places to change to numerical rows and cols of the board
	*
	*   returns: int*. A pointer to an array with the converted places from the string given
	*/
	static int* changeStringToPlaces(const std::string place);
};