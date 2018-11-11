#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;
//Guess my number game
//Mihael Petrièeviæ

int main(){
	
	srand(time(0));			//stvara seed koji uzima vrijeme racèunala te zbog toga svaki put daje drugi random rezultat (potreban ctime)
	
	bool startgame;			//ako je igra zapocela i brojevi su odreðeni startgame = true
	bool Normal;
	bool Hard;
	int broj;				//random broj
	int n;					
	int odredenbroj;		//najveci broj kojeg korisnik sam odredi
	int x;					//broj kojim korisnik pogaða rješenje
	
	begining:				//pomoæu goto saziva da je ovdje poèetak te se na kraju koda vraæa na njega da se igra može ponovno igrat
	cout << "1. Hard" << endl << "2. Normal" << endl << "Unesi odgovor ovdje: ";
	cin >> n;
	if (n == 1)				//play moguænost ako je odabrana, igra æe zapoèeti sa najveæim brojem do beskonaèno
	{
		Hard = true;
		startgame = true;
	} 
	else if (n == 2)		//settings moguænost je odabrana, igra æe zapoèeti s najveæim brojem od odreðenbroj kojeg korisnik sam odredi
	{
		 Normal = true;
		 startgame = true;
	}	
	if (Hard == true)		//ako je igra zapoèela s beskonaænim najveæim brojem, broj æe biti nasumièno odabran od 1 do beskonaæno
	{
		broj = 1 + rand();
	}
	else if (Normal == true)
	{
		cout << "Upisi do kojeg najveceg broja moze biti broj kojeg ces pogacati!" << endl;
		cin >> odredenbroj;
		broj = 1 + rand() % odredenbroj;	//random broj æe biti broj od 1 do najveæeg odreðenog broja koji je zadao korisnik
	}
	loop:					//pomoæu goto stvara loop tako da se pogaðanje može ponavljati
	if (startgame == true)	//samo ako je igra zapoèela zapoèni ovaj kod
	{
	cout << "Pogodi broj!" << endl;
	cin >> x;
}
	if (x < broj)			//ako je random broj manji od broja s kojim korisnik pogaða tada mu kaži da je premalo
	{
		cout << "Premalo!" << endl;
		goto loop;	
	} 
	else if (x > broj)		//isto kao iznad navedno samo kaže da je preveliko
	{
		 cout << "Preveliko" << endl;
		 goto loop;			//vrati se na loop
	}
	else if (x = broj)
	{
		cout << "Pogodio si moj broj!" << endl;
		system("pause");
		system("cls");
		goto begining;		//vrati se na poèetak koda
	} 
}
