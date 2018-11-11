#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
//Eurojackpot numbers generator (error corrected version but not compact code)

int main() {
	
	srand(time(0));		//seed stvara potpuno rnadom broj
	
	int broj1,broj2,broj3,broj4,broj5;			//varijabla 5 zadanih brojeva
	int joker1,joker2;									//varijabla 2 dodatna broja
	
	cout << "Eurojackpot numbers today are:" << endl;
	
	broj1 = 1 + rand() % 50;
	broj2 = 1 + rand() % 50;
	broj3 = 1 + rand() % 50;
	broj4 = 1 + rand() % 50;
	broj5 = 1 + rand() % 50;
	
	joker1 = 1 + rand() % 10;
	joker2 = 1 + rand() % 10;
	
	loop:
	if (broj1 == broj2)
	{
		broj1 = 1 + rand() % 50;
		goto loop;
	}
	if (broj2 == broj3)
	{
		broj2 = 1 + rand() % 50;
		goto loop;
	} 
	if (broj3 == broj4)
	{
		broj3 = 1 + rand() % 50;
		goto loop;
	}
	if (broj4 == broj5)
	{
		broj4 = 1 + rand() % 50;
		goto loop;
	}
	if (broj1 == broj3)
	{
		broj1 = 1 + rand() % 50;
		goto loop;
	}
	if (broj1 == broj4) 
	{
		broj1 = 1 + rand() % 50;
		goto loop;
	}
	if (broj1 == broj5)
	{
		broj1 = 1 + rand() % 50;
		goto loop;
	} 
	if (broj2 == broj4)
	{
		broj2 = 1 + rand() % 50;
		goto loop;
	}
	if (broj2 == broj5) 
	{
		broj2 = 1 + rand() % 50;
		goto loop;
	}
	if (broj3 == broj4)
	{
		broj3 = 1 + rand() % 50;
		goto loop;
	} 
	if (broj3 == broj5)
	{
		broj3 = 1 + rand() % 50;
		goto loop;
	}
	if (broj4 == broj5)
	{
		broj4 = 1 + rand() % 50;
		goto loop;
	} 
	
	if (joker1 == joker2) joker1 = 1 + rand() % 50;
	
	cout << "(" << broj1 << ") " << "(" << broj2 << ") " << "(" << broj3 << ") " << "(" << broj4 << ") " << "(" << broj5 << ")  " << "[" << joker1 << "] " << "[" << joker2 << "]";
	
}
