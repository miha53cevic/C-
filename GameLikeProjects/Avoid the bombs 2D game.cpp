#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
using namespace std;
//2D game - Avoid Bombs - Mihael Petricevic

char input;

int numbomb=0;
int game=0;
int xbomb,ybomb;
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
void gui();
void bombs();
void end();

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
	
	gui();
	
	while (game == -1)
	{
	map[ypos][xpos] = 2;
	map_draw();
	bombs();
	
	//sets the cursosr on the beggining on the screen
	COORD cur = {0, 0};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);	
	//basicly redraws everything
	
	loop();
	
	}
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
			else if (map[i][j] == 3)
			{
				cout << "o";
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
		
		if (kbhit())
		{
			input = getch();
			
			if (input == 'w')
			{
			xpos_old = xpos;
			ypos_old = ypos;
			
			map[ypos_old][xpos_old] = 0;
			
			if(map[ypos-1][xpos] != 1)
			{
			ypos = ypos - 1;
			
			if (map[ypos][xpos] == 3){end();}
			
			map[ypos][xpos] = 2;
			}
		}
		
		if (input == 's')
		{
			xpos_old = xpos;
			ypos_old = ypos;
			
			map[ypos_old][xpos_old] = 0;
			
			if(map[ypos+1][xpos] != 1)
			{	
			ypos = ypos + 1;
			
			if (map[ypos][xpos] == 3){end();}
			
			map[ypos][xpos] = 2;
			}
			
		}
		
		if (input == 'a')
		{
			xpos_old = xpos;
			ypos_old = ypos;
			
			map[ypos_old][xpos_old] = 0;
			
			if(map[ypos][xpos-1] != 1)
			{	
			xpos = xpos - 1;
			
			if (map[ypos][xpos] == 3){end();}
			
			map[ypos][xpos] = 2;
			}
			
		}
		
		if (input == 'd')
		{
			xpos_old = xpos;
			ypos_old = ypos;
			
			map[ypos_old][xpos_old] = 0;
			
			if(map[ypos][xpos+1] != 1)
			{
			xpos = xpos + 1;
			
			if (map[ypos][xpos] == 3){end();}
			
			map[ypos][xpos] = 2;
			}
			
		}
		
	}
}

	
	/*
		void loop(); uzima igracev input i prema njemu mjenja njegove kordinate na mapi
		Ovisno o tome ako se na kordinati na koju igrac pokusava doci nalazi 1 (zid) igrac ne moze ici tamo
		
		Kako radi:
		Prvo gleda ako je input = right/left/up/down te zatim stavlja trenutne kordinate u xpos_old i ypos_old kako bi mogli izbrisati igraca na tim kordinatama.
		Izbrise igraca tako da stavi da promijeni njegovo polje od 2 na 0 jer igra crta 0 kao razmak to jest prazninu.
		Nakon toga igra provjerava ako je na tim kordinatama zid (1) i ako nije mjenja kordinate igraca i vraca u main() gdje se igra ponovno crta
	*/
	
	void gui(){
		
		system("cls");
		cout << "\n\n\n			Goal: Avoid all of the bombs and survive!\n";
		cout << "				";
		system("pause");
		game = -1;
		system("cls");
	}
	
	/*
		gui je samo pocetna strana igre, objasnjava pravila i stavlja game = -1 sto znaci da je igra zapocela
	*/
	
	void bombs(){
		
		srand(time(0));
		numbomb = numbomb + 3;
		
		for (int k=0;k < 3;k++)
		{
		xbomb = 1 + rand() % 19;
		ybomb = 1 + rand() % 8;
		
			if (map[ypos][xpos] != 1)
			{
			map[ybomb][xbomb] = 3;
			}
			else {
				xbomb = 1 + rand() % 19;
				ybomb = 1 + rand() % 8;
				map[ybomb][xbomb] = 3;
			}
		}
	}
	
	/*
		Unosi bombe u igru koje na poljima iznose 3.
		k je zapravo broj bombi koje se mogu spawnati nakon jednog poteza igraca.
		Ako su kordinate na igracu napravi nove.
	*/
	
	void end(){
		
		{
			system("cls");
			cout << "You survived " << numbomb << " Bombs!";
			exit(0);
		}
		
	}
	
	/*
		Zavrsava igru i izlazi iz aplikacije
	*/
