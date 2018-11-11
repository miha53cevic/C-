#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//computer guesses your number

int main(){
	
	srand(time(0));
	
	int min=1,max=100;
	
	int guess =  1 + rand() % 100;
	int tries=0;
	string high_low;
	
	cout << "Welcome to my number guessing name!\nIn this game the computer has to guess your number!\n\nThink of a number from 1 to 100!\n";
	system("pause");
	system("cls");
	
	do{	
	
		cout << "I guess: " << guess;
		cout << "\nhigh/low/correct? - ";
		cin >> high_low;
		
		if (high_low == "high")
		{
			max = guess;
			guess = (max+min) / 2;
		}
		
		else if (high_low == "low")
		{
			min = guess;
			guess = (max+min) / 2;
			
		}
		else if (high_low == "correct")
		{
			cout << "\nYour number is " << guess;
			cout << "\nIt only took me " << tries << " tries!";
		}
		
		tries++;
		
	}while(high_low != "correct");
}
