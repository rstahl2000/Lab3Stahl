/*
 * TicTacToe.cpp
 *
 *  Created on: Sep 19, 2019
 *      Author: Robert Stahl and Chris Tiso
 */

#include "TicTacToe.hpp"
TicTacToe::TicTacToe(string play1,string play2){
	board=new char*[3];
	for(int i=0;i<3;i++){
		board[i]=new char[3];
	}
	player1=play1;
	player2=play2;
	this->newBoard();
}

void TicTacToe::newBoard(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			this->board[i][j]='_';
		}
	}
}

void TicTacToe::printBoard(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<board[i][j]<<"\t";
		}
		cout<<endl;
	}
}

bool TicTacToe::fullBoard(){
	bool full=true;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(board[i][j]=='_'){
				full=false;
			}
		}
	}
	return full;
}

bool TicTacToe::checkWin(char playIcon){
	for(int i=0;i<3;i++){
		if(board[i][0]==playIcon&&board[i][0]==board[i][1]&&board[i][2]==board[i][0]){
			return true;
		}
		else if(board[0][i]==playIcon&&board[1][i]==playIcon&&board[2][i]==playIcon){
			return true;
		}
	}
	if(board[0][0]==playIcon&&board[1][1]==board[0][0]&&board[2][2]==board[0][0]){
		return true;
	}
	if(board[0][2]==playIcon&&board[1][1]==board[0][2]&&board[2][0]==board[0][2]){
		return true;
	}
	return false;
}

void TicTacToe::personPlay(char playIcon){
	string playname;
	bool taken=true;
	int row;
	int col;
	if(playIcon=='X'){
		playname=player1;
	}
	else{
		playname=player2;
	}
	cout<<playname<<"'s turn:"<<endl;
	cout<<playname<<": enter row:";
	cin>>row;
	cout<<playname<<": enter column:";
	cin>>col;
	if(board[row][col]=='_'){
		taken=false;
	}
	while(taken){
		cout<<"Position Already Taken"<<endl;
		cout<<playname<<": enter row:";
		cin>>row;
		cout<<playname<<": enter column:";
		cin>>col;
		if(board[row][col]=='_'){
			taken=false;
		}
	}
	this->board[row][col]=playIcon;
	this->printBoard();
}

void TicTacToe::playGame(void){
	bool endgame=true;
	char victorChar;
	bool tie=false;
	char playerChar='X';
	while(endgame){
		personPlay(playerChar);
		if(checkWin(playerChar)){
			endgame=false;
			victorChar=playerChar;
		}
		else if(fullBoard()){
			endgame=false;
			tie=true;
		}
		if(playerChar=='X'){
			playerChar='O';
		}
		else{
			playerChar='X';
		}
	}
	if(tie){
		cout<<"It's a tie!"<<endl;
	}
	else{
		if(victorChar=='X'){
			cout<<player1<<" won!"<<endl;
		}
		else{
			cout<<player2<<" won!"<<endl;
		}
	}
	printBoard();
}

TicTacToe::~TicTacToe(){
	delete board;
	cout<<"Board Erase"<<endl;
}
