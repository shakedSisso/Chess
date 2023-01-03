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

std::string Manager::handleMove(std::string move)
{
	int* places = nullptr;
	Piece* pieceSelected = nullptr;
	bool pieceColor = false;
	int moveResult = 0;
	places = Utils::changeStringToPlaces(move);
	pieceSelected = this->_board->getPiece(places[ORG_ROW], places[ORG_COl]);
	try
	{
		if (pieceSelected == nullptr || pieceSelected->getIsWhite() != this->_isWhiteTurn)
		{
			throw InvalidMoveException(InvalidMoveException::types::NOT_PLAYER_PIECE);
		}
		moveResult = this->_board->move(places[ORG_ROW], places[ORG_COl], places[DST_ROW], places[DST_COl]);
		this->_isWhiteTurn = !this->_isWhiteTurn;
		return std::to_string(moveResult);
	}
	catch (InvalidMoveException& exception)
	{
		return std::to_string(exception.getType());
	}

}
