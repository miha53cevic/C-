#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
//passord gen with letter only
//Mihael Petrièeviæ

int main() {
	
	srand(time(0));
	
	bool loop;
	int broj;
	int kolicina;
	
	do{
	cout << "How long would you like your password to be: ";
	cin >> kolicina;
	
	for (int i; i != kolicina; i++)
	{
		broj = 1 + rand() % 23;
		if (broj == 1) cout << "a";
		else if (broj == 2) cout << "b";
		else if (broj == 3) cout << "c";
		else if (broj == 4) cout << "d";
		else if (broj == 5) cout << "e";
		else if (broj == 6) cout << "f";
		else if (broj == 7) cout << "g";
		else if (broj == 8) cout << "h";
		else if (broj == 9) cout << "i";
		else if (broj == 10) cout << "j";
		else if (broj == 11) cout << "k";
		else if (broj == 12) cout << "l";
		else if (broj == 13) cout << "m";
		else if (broj == 14) cout << "n";
		else if (broj == 15) cout << "o";
		else if (broj == 16) cout << "p";
		else if (broj == 17) cout << "q";
		else if (broj == 18) cout << "r";
		else if (broj == 19) cout << "s";
		else if (broj == 20) cout << "t";
		else if (broj == 21) cout << "w";
		else if (broj == 22) cout << "y";
		else if (broj == 23) cout << "z";
	}
	cout << endl;
	system("pause");
	system("cls");
	loop = 1;
	
	} while (loop);
}
