#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//random number password generator
//Mihael Petri�evi�

int main() {
	
	srand(time(0));		//stvara seed koji je random svaki put kada se program ukljuci, bitan jer �elimo da broj bude nasmi�an svaki put
	
	bool begining=0;
	int x;				//varijabla du�ine pasworda
	
	do {
	cout << "Unesi koliko zelis da ti password bude dugi: ";
	cin >> x;
	
	for (int i=0; i!=x; i++)		//tako dugo dok i nije jednak x izvodi kod
	{
		cout << 0 + rand() % 9;		//brojevi koji �e biti prikazani �e biti od 0 do 9
	}
	cout << endl;
	system("pause");
	system("cls");
	begining = 1;
} while (begining);
}
