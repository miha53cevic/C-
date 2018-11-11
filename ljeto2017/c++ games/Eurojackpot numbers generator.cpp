#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
//Eurojackpot numbers generator (error with multiple same numbers version)

int main() {
	
	srand(time(0));		//seed stvara potpuno rnadom broj
	
	int broj;			//varijabla 5 zadanih brojeva
	int joker;			//varijabla 2 dodatna broja
	
	cout << "Eurojackpot numbers today are:" << endl;
	
	for (int i=0; i!=5; i++)		//ukupno je 5 broja
	{
		broj = 1 + rand() % 50;				//brojevi su od 1 do 50
		cout << "(" << broj << ") ";		//ispisiva brojeve u zagradama
	}
	
	cout << "  ";
	
	for (int i=0; i!=2; i++)			//2 su ukupna dodatna broja
	{
		joker = 1 + rand() % 10;		//brojevi su od 1 do 10
		cout << "[" << joker << "] ";
	}
	
}
