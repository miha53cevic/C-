#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;
//Guess my number game
//Mihael Petri�evi�

int main(){
	
	srand(time(0));			//stvara seed koji uzima vrijeme rac�unala te zbog toga svaki put daje drugi random rezultat (potreban ctime)
	
	bool startgame;			//ako je igra zapocela i brojevi su odre�eni startgame = true
	bool Normal;
	bool Hard;
	int broj;				//random broj
	int n;					
	int odredenbroj;		//najveci broj kojeg korisnik sam odredi
	int x;					//broj kojim korisnik poga�a rje�enje
	
	begining:				//pomo�u goto saziva da je ovdje po�etak te se na kraju koda vra�a na njega da se igra mo�e ponovno igrat
	cout << "1. Hard" << endl << "2. Normal" << endl << "Unesi odgovor ovdje: ";
	cin >> n;
	if (n == 1)				//play mogu�nost ako je odabrana, igra �e zapo�eti sa najve�im brojem do beskona�no
	{
		Hard = true;
		startgame = true;
	} 
	else if (n == 2)		//settings mogu�nost je odabrana, igra �e zapo�eti s najve�im brojem od odre�enbroj kojeg korisnik sam odredi
	{
		 Normal = true;
		 startgame = true;
	}	
	if (Hard == true)		//ako je igra zapo�ela s beskona�nim najve�im brojem, broj �e biti nasumi�no odabran od 1 do beskona�no
	{
		broj = 1 + rand();
	}
	else if (Normal == true)
	{
		cout << "Upisi do kojeg najveceg broja moze biti broj kojeg ces pogacati!" << endl;
		cin >> odredenbroj;
		broj = 1 + rand() % odredenbroj;	//random broj �e biti broj od 1 do najve�eg odre�enog broja koji je zadao korisnik
	}
	loop:					//pomo�u goto stvara loop tako da se poga�anje mo�e ponavljati
	if (startgame == true)	//samo ako je igra zapo�ela zapo�ni ovaj kod
	{
	cout << "Pogodi broj!" << endl;
	cin >> x;
}
	if (x < broj)			//ako je random broj manji od broja s kojim korisnik poga�a tada mu ka�i da je premalo
	{
		cout << "Premalo!" << endl;
		goto loop;	
	} 
	else if (x > broj)		//isto kao iznad navedno samo ka�e da je preveliko
	{
		 cout << "Preveliko" << endl;
		 goto loop;			//vrati se na loop
	}
	else if (x = broj)
	{
		cout << "Pogodio si moj broj!" << endl;
		system("pause");
		system("cls");
		goto begining;		//vrati se na po�etak koda
	} 
}
