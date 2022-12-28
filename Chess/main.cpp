#include <iostream>
#include "Board.h"
#include "King.h"
#include "InvalidMoveException.h"

int main()
{
	/*
	This file is an example of creating the board. Moving the pieces (Kings and Rooks) and preventing a self chess situation.
	*/
	Board board;
	board.buildBoard("R##K###R################################################r##k###r");
	board.printBoard();
	std::cout << std::endl;
	try 
	{
		board.move(7, 3, 7, 4);
		board.move(0, 0, 1, 0);
		board.printBoard();
		std::cout << std::endl;
		board.move(1, 0, 1, 3);
		board.printBoard();
		std::cout << std::endl;
		board.move(7, 0, 6, 0);
		board.printBoard();
		std::cout << std::endl;
		board.move(6, 0, 6, 3);
		board.printBoard();
		std::cout << std::endl;
		board.move(1, 3, 1, 2);
		board.printBoard();
		std::cout << std::endl;
	}
	catch (InvalidMoveException& exception)
	{
		std::cout << exception.what() << std::endl;
	}
	std::cout << std::endl;
	board.printBoard();
}