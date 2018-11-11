#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
//kamen, škare, papir igra
//Mihael Petrièeviæ

int main() {
	
	srand(time(0));		//stvara seed te je zato broj potpuno nasumièan
	
	bool loop;			//varijabla koja ima samo funkciju da ili ne (0 ili 1), kasnije sluzi da bi se kod ponovio
	int izbor;			//varijabla koja uzima izbor korisnika i sprema ga
	int x;				//varijabla koja sprema izbor raèunala
	
	do {			//poèetak takozvanog loopa ili ponavljanja koda
	cout << "Unesi svoj izbor: " << endl << "1. ROCK" << endl << "2. PAPER" << endl << "3. SCISSORS" << endl << "Odgovor: ";
	cin >> izbor;
	
	x = 1 + rand() % 3;		//uzima nasumièan broj od 1 - 3 te po tome raèunalo dobiva svoj izbor
	
	//mekanike igre
	if (x == 1 && izbor == 2)
	{
		cout << "Computer chose: ROCK" << endl;
		cout << "You win!" << endl;
	} 
	else if (x == 2 && izbor == 3)
	{
		cout << "Computer chose: PAPER" << endl;
		cout << "You win!" << endl;
	} 
	else if (x == 3 && izbor == 1)
	{
		cout << "Computer chose: SCISSORS" << endl;
		cout << "You win!" << endl;
	}
	else if (x == 1 && izbor == 3)
	{
		cout << "Computer chose: ROCK" << endl;
		cout << "You lose!" << endl;
	}
	else if (x == 2 && izbor == 3)
	{
		cout << "Computer chose: PAPER" << endl;
		cout << "You win!" << endl;
	} 
	else if (x == 3 && izbor == 2)
	{
		cout << "Computer chose: SCISSORS" << endl;
		cout << "You lose" << endl;
	}
	else if (x == 1 && izbor == 1)
	{
		cout << "Computer chose: ROCK" << endl;
		cout << "Tie!" << endl;
	}
	else if (x == 2 && izbor == 2)
	{
		cout << "Computer chose: PAPER" << endl;
		cout << "Tie!" << endl;
	}
	else if (x == 3 && izbor == 3)
	{
		cout << "Computer chose: SCISSORS" << endl;
		cout << "Tie!" << endl;
	}
	
	//ponavljanje igre
	system("pause");			//zaustavlja tekst i èeka input od korisnika
	system("cls");				//briše sve sa konzole
	loop = 1;					//zapoèinje loop

} while (loop);		//gleda da li je loop aktiviran i ako je ponavlja cijeli kod u loopu
}
