 /* Lab2.cpp
 *Sun Bilin
 *  Created on: Sep 3, 2019
 *      Author: robertstahl and Chris Tiso
 */



#include <iostream>
using namespace std;
#include <time.h>
#include <stdlib.h>

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

int main(){
	Quiz test(6);
	for(int i=0;i<=10;i++){
		test.quizUser();
		test.printScore();
	}
	return 0;
}
