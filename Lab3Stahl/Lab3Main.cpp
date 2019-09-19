 /* Lab3 Main
 *Sun Bilin
 *  Created on: Sep 3, 2019
 *      Author: Robert Stahl and Chris Tiso
 */



#include <iostream>
using namespace std;
#include <time.h>
#include <stdlib.h>
#include "TicTacToe.hpp"
#include "Box.hpp"

//Quiz Class Definition
class Quiz{
	int quizNum;
	int qRight;
	int totQuiz;
public:
	Quiz(int num){
		quizNum=num;
		qRight=0;
		totQuiz=0;
		srand(time(NULL));
	}
	void quizUser(){
		int test=rand()%13+1;
		int userAnswer;
		cout<<"What is "<<test<<" * "<<quizNum<<"?"<<endl;
		cin>>userAnswer;
		if (userAnswer==(test*quizNum)){
			qRight++;
			cout<<"Correct!"<<endl;
		}
		else{
			cout<<"Incorrect! Answer Was "<<(test*quizNum)<<endl;
		}
		totQuiz++;

	}
	void printScore(){
		cout<<"You have "<<qRight<<" correct out of "<<totQuiz<<endl;
	}
};

//Hanning Filter Class Declaration
class Hanning{
	int windowSize;
	int* ogArr;
	int arrSize;
	int* filtArr;
public:
	Hanning(int wsize,int ogarr[],int asize,int finArr[]);
	int weightAvg(int startPoint);
	void filterArray();
	void printGraph(bool filtered);
	void changeWindow(int newWind);
	void printArray(bool filtered);
};

int main(){
	//Test For Quiz. Uses 6 as the multiple;
	Quiz test(6);
	for(int i=0;i<=10;i++){
		test.quizUser();
		test.printScore();
	}
	cout<<"-----------------------"<<endl;//For Better Console Spacing

	//Hanning Test
	int testArr[9]={3,8,2,5,1,4,6,0,2};
	int filtArrTest[9];
	Hanning testH(3,testArr,9,filtArrTest);
	testH.filterArray();
	testH.printArray(false);
	testH.printArray(true);
	testH.printGraph(false);
	cout<<"-----------------------"<<endl;//For Better Console Spacing
	testH.printGraph(true);
	testH.changeWindow(5);
	testH.printArray(false);
	testH.printArray(true);
	testH.printGraph(false);
	cout<<"-----------------------"<<endl;//For Better Console Spacing
	testH.printGraph(true);
	cout<<"-----------------------"<<endl;//For Better Console Spacing

	//Tic Tac Toe Test
	TicTacToe testToe("Bobby","Chris");
	testToe.playGame();
	cout<<"-----------------------"<<endl;//For Better Console Spacing

	//Box Operator Test
	bool boxTest;
	Box Box1(3.3, 1.2, 1.5);
	Box Box2(8.5, 6.0, 2.0);
	boxTest=Box1==Box2;
	cout<<boxTest<<endl;//Should Print 0
	Box Box3(3.3,1.2,1.5);
	boxTest=Box1==Box3;
	cout<<boxTest<<endl;//Should Print 1
	return 0;
}

//Hanning Function Definitions

Hanning::Hanning(int wsize,int* ogarr,int asize,int* finArr){
	windowSize=wsize;
	ogArr=ogarr;
	arrSize=asize;
	filtArr=finArr;
}

int Hanning::weightAvg(int arrIndex){
	int avgVal=0;
	if(arrIndex<(windowSize/2)||arrIndex>((arrSize-1)-(windowSize/2))){
		return avgVal;
	}
	else{
		int skip=2;
		int divisor=0;
		int weight=(windowSize/2)+1;
		avgVal+=ogArr[arrIndex]*weight;
		divisor+=weight;
		for(int i=arrIndex+1;i<=(arrIndex+(windowSize/2));i++){
			weight--;
			divisor+=2*weight;
			avgVal+=weight*ogArr[i];
			avgVal+=weight*ogArr[i-skip];
			skip+=2;
		}
		avgVal/=divisor;
		return avgVal;
	}
}
void Hanning::filterArray(){
	for(int i=0;i<arrSize;i++){
		this->filtArr[i]=weightAvg(i);
	}
}

void Hanning::printGraph(bool filtered){
	int *printArr;
	if(filtered){
		printArr=filtArr;
	}
	else{
		printArr=ogArr;
	}
	int maxVal=printArr[0];
	int minVal=printArr[0];
	for(int i=0;i<arrSize;i++){
		if (printArr[i]<minVal){
			minVal=printArr[i];
		}
		else if(printArr[i]>maxVal){
			maxVal=printArr[i];
		}
	}
	int distance=maxVal-minVal;
	for(int i=0;i<=distance;i++){
		cout<<maxVal-i<<":";
		int number=maxVal-i;
		for(int j=0;j<arrSize;j++){
			if(printArr[j]==number){
				cout<<"*";
			}
			else{
				cout<<" ";
			}
		}
		cout<<endl;
	}
}

void Hanning::changeWindow(int newWind){
	if(newWind%2==0){
		newWind--;
	}
	this->windowSize=newWind;
	filterArray();
}


void Hanning::printArray(bool filtered){
	int* printArr;
	if(filtered){
		printArr=filtArr;
	}
	else{
		printArr=ogArr;
	}
	for(int i=0;i<arrSize;i++){
		cout<<printArr[i]<<" ";
	}
	cout<<endl;
}
