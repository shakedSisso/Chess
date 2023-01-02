#include "Utils.h"

#define SMALL_A_ASCII_VALUE 97
#define ZERO_ASCII_VALUE 48
#define ITEM_AMOUNT 4	

static int* changeStringToPlaces(std::string place)
{
	int* places = new int[ITEM_AMOUNT];
	places[0] = int(place[0]) - SMALL_A_ASCII_VALUE;
	places[1] = int(place[1]) - ZERO_ASCII_VALUE;
	places[2] = int(place[2]) - SMALL_A_ASCII_VALUE;
	places[3] = int(place[3]) - ZERO_ASCII_VALUE;
	return places;
}