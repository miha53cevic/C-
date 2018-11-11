#include <iostream>
using namespace std;
//2D game map with Arrays - Mihael Petricevic

string input;

int xpos=10,ypos=4;
int xpos_old=0,ypos_old=0;

int map[10][21] = {
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
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

void loop();
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
	
	map[ypos][xpos] = 2;
	
	map_draw();
	
	cout << "Where would you like to go?\n" << "UP/DOWN/LEFT/RIGHT\n" << "Answer: ";
	cin >> input;
	
	loop();
}

/*
	xpos i ypos su pozicije igraca,a xpos_old i ypos_old su njegove zadnje poznate kordinate

	Pocetne kordinate su u sredini mape i upisujem ih obrnuto jer tako rade 2D arrayi ali zbog lakseg razumjevanja su obrnuti kada crtam igraca
*/

void map_draw(){
	
	for (int i=0; i < 10;i++)
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
	cout << "\n";
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

	void loop(){
		
		if (input == "up" || input == "w")
		{
			xpos_old = xpos;
			ypos_old = ypos;
			
			map[ypos_old][xpos_old] = 0;
			
			if(map[ypos-1][xpos] != 1)
			{
			ypos = ypos - 1;
			map[ypos][xpos] = 2;
			}
			
		}
		
		if (input == "down"|| input == "s")
		{
			xpos_old = xpos;
			ypos_old = ypos;
			
			map[ypos_old][xpos_old] = 0;
			
			if(map[ypos+1][xpos] != 1)
			{
			ypos = ypos + 1;
			map[ypos][xpos] = 2;
			}
			
		}
		
		if (input == "left"|| input == "a")
		{
			xpos_old = xpos;
			ypos_old = ypos;
			
			map[ypos_old][xpos_old] = 0;
			
			if(map[ypos][xpos-1] != 1)
			{
			xpos = xpos - 1;
			map[ypos][xpos] = 2;
			}
			
		}
		
		if (input == "right"|| input == "d")
		{
			xpos_old = xpos;
			ypos_old = ypos;
			
			map[ypos_old][xpos_old] = 0;
			
			if(map[ypos][xpos+1] != 1)
			{
			xpos = xpos + 1;
			map[ypos][xpos] = 2;
			}
			
		}
		
		system("cls");
		main();
	}
	
	/*
		void loop(); uzima igracev input i prema njemu mjenja njegove kordinate na mapi
		Ovisno o tome ako se na kordinati na koju igrac pokusava doci nalazi 1 (zid) igrac ne moze ici tamo
		
		Kako radi:
		Prvo gleda ako je input = right/left/up/down te zatim stavlja trenutne kordinate u xpos_old i ypos_old kako bi mogli izbrisati igraca na tim kordinatama.
		Izbrise igraca tako da stavi da promijeni njegovo polje od 2 na 0 jer igra crta 0 kao razmak to jest prazninu.
		Nakon toga igra provjerava ako je na tim kordinatama zid (1) i ako nije mjenja kordinate igraca i vraca u main() gdje se igra ponovno crta
	*/
