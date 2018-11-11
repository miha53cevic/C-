#include <iostream>
using namespace std;

int map[11][21] = {
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1

};


void map_draw();

/*
	map = 2D array

	primjer:

	map[3][2] = {		//map je zapravo onda map[y][x]
		1, 2,
		3, 4
		4, 5
	};

	sve u zagradi je sto popunjava mapu
*/

int main(){
	
	int xpos=10,ypos=5;
	int xpos_old=0,ypos_old=0;
	
	map[ypos][xpos] = 2;
	
	map_draw();
}

/*
	xpos i ypos su pozicije igraca,a xpos_old i ypos_old su njegove zadnje poznate kordinate

	Pocetne kordinate su u sredini mape i upisujem ih obrnuto jer tako rade 2D arrayi ali zbog lakseg razumjevanja su obrnuti
*/

void map_draw(){
	
	for (int i=0; i < 11;i++)
	{
		for (int j=0; j < 21;j++)
		{
			if (map[i][j] == 1)
			{
				cout << "#";
			}
			else if (map[i][j] == 0)
			{
				cout << " ";
			}
			else if (map[i][j] == 2)
			{
				cout << "X";
			}
		}
		cout << endl;
	}

/*
	map_draw crta igrace polje pomocu nested for loopa
	Prvo se crta x os te zatim y os.
	
	Kako radi:
	Vanjski for loop ceka da unutarnji for loop zavrsi prvo te zatim izvrsava svoju radnju.
	Unutarnji for loop pregledava prvo sve x kordinate kada je y=0 i ako se negdje nalazi 1 stavlja #, ako se nalazi 0 stavlja razmak i ako se nalazi 2 crta igraca.
	Tek kada unutarnji for loop zavrsi i=1 i zatim se zavrsava ta linija i ide na drugu te zatim opet unutarnji for loop trazi ali sada je j = 1 sto znaci da trazi u drugom redu.
	To se stalno ponavlja tako dugo dok se cijela igra ne nacrta
*/

}
