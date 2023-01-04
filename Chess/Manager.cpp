#include "Manager.h"
#include "Utils.h"
#include "InvalidMoveException.h"
#include "Piece.h"
#include <string>

#define WHITE true
#define BLACK false
#define ORG_ROW 0
#define ORG_COl 1
#define DST_ROW 2
#define DST_COl 3


Manager::Manager()
	: _isWhiteTurn(true)
{
	this->_whitePlayer = new Player(WHITE);
	this->_blackPlayer = new Player(BLACK);
	this->_board = new Board();
	this->_board->buildBoard("RNBKQBNRPPPPPPPP################################pppppppprnbkqbnr");
}

Manager::~Manager()
{
	delete this->_whitePlayer;
	delete this->_blackPlayer;
	delete this->_board;
	this->_whitePlayer = nullptr;
	this->_blackPlayer = nullptr;
	this->_board = nullptr;
}

std::string Manager::handleMove(const std::string move)
{
	int* places = nullptr;
	Piece* pieceSelected = nullptr;
	bool pieceColor = false;
	int moveResult = 0;
	places = Utils::changeStringToPlaces(move);
	pieceSelected = this->_board->getPiece(places[ORG_ROW], places[ORG_COl]);
	try
	{
		if (pieceSelected == nullptr || pieceSelected->getIsWhite() != this->_isWhiteTurn) // checking if there is not piece in the org place or if the piece there doesn't belong to the current playing player
		{
			delete places;
			throw InvalidMoveException(InvalidMoveException::types::NOT_PLAYER_PIECE);
		}
		moveResult = this->_board->move(places[ORG_ROW], places[ORG_COl], places[DST_ROW], places[DST_COl]);
		this->_isWhiteTurn = !this->_isWhiteTurn; // since the move is legal, switch the turn to the other player
		delete places;
		return std::to_string(moveResult);
	}
	catch (InvalidMoveException& exception) // if this exception was thrown that means that this->_board->move wasn't finished and the move can't be performed (reason in the type code of the exception)
	{
		delete places;
		return std::to_string(exception.getType());
	}

}
