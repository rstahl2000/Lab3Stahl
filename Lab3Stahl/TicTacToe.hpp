/*
 * TicTacToe.hpp
 *
 *  Created on: Sep 19, 2019
 *      Author: robertstahl
 */

#ifndef TICTACTOE_HPP_
#define TICTACTOE_HPP_
#include <iostream>
using namespace std;
#include <time.h>
#include <stdlib.h>

 class TicTacToe{
	string player1;
	string player2;
	char** board;
 public:
	TicTacToe(string play1,string play2);
	void newBoard();
	void printBoard();
	bool fullBoard();
	bool checkWin(char playIcon);
	void personPlay(char playIcon);
	void playGame();
	~TicTacToe();
};



#endif /* TICTACTOE_HPP_ */
