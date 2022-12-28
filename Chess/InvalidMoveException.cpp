#include "InvalidMoveException.h"

InvalidMoveException::InvalidMoveException(const int type)
	: _type(type)
{	
}

std::string InvalidMoveException::what()
{
	types type = (types)this->_type;
	switch (type)
	{
	case NOT_PLAYER_PIECE:
		return "The piece is not yours or empty";
		break;
	case SELF_EATING:
		return "You can't eat a piece of your own";
		break;
	case SELF_CHESS:
		return "You can't make a move that will put you in a chess";
		break;
	case ILLEGAL_INDEX:
		return "This place doesn't exist on the board";
		break;
	case ILLEGAL_MOVE:
		return "You can't move this piece to this location";
		break;
	case SAME_PLACE:
		return "You are trying to move this piece to its own place";
		break;
	default:
		break;
	}
}

int InvalidMoveException::getType() const
{
	return this->_type;
}
