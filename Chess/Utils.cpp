#include "Utils.h"
#include <math.h>

#define SMALL_A_ASCII_VALUE 97
#define ZERO_ASCII_VALUE 48
#define ITEM_AMOUNT 4	
#define MAX_ROW 8

int* Utils::changeStringToPlaces(const std::string place)
{
	int* places = new int[ITEM_AMOUNT]; 
	places[1] = int(place[0]) - SMALL_A_ASCII_VALUE;
	places[0] = abs(int(place[1]) - ZERO_ASCII_VALUE - MAX_ROW); // reverting the value as in the graphics the top row is 8 and in our board the top row is 0
	places[3] = int(place[2]) - SMALL_A_ASCII_VALUE;
	places[2] = abs(int(place[3]) - ZERO_ASCII_VALUE - MAX_ROW); // reverting the value as in the graphics the top row is 8 and in our board the top row is 0

	return places;
}
