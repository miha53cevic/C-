#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;
//space invaders - Mihael Petricevic

int xpos=10,ypos=8;
int xbullet=0,ybullet=0;
int shoot = 0;
int invader = 0;
int over=0;
int xbomb[2],ybomb[2];
int bombs=0;

int map[10][19] = {
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

void map_draw();
void movement();
void fire();
void refresh();
void enemy();
void checkwin();
void end();

/////////////////////////////////////////////////////////////////////////

int main(){
	//seed generator, starting point of the player, main game loop
	srand(time(0));
	map[ypos][xpos] = 2;
	
	while(1){
		movement();	
		map_draw();
		fire();
		enemy();
		checkwin();
		refresh();
		
		//end game
		if (over == 1 || over == 2)
		{
			end();
			return 0;
		}
	}
}

/////////////////////////////////////////////////////////////////////////

void map_draw(){
	//draws the map of the game
	cout << "    SPACE INVADERS\n by Mihael Petricevic\n\n";
	
	//nested for loop
	for (int i=0; i < 10; i++)
	{
		for (int j=0; j < 19; j++)
		{
			if (map[i][j] == 0)
			{
				cout << " ";
			}
			if (map[i][j] == 1)
			{
				cout << "#";
			}
			if (map[i][j] == 2)
			{
				cout << "H";
			}
			if (map[i][j] == 3)
			{
				cout << "r";
			}
			if (map[i][j] == 4)
			{
				cout << "x";
			}
			if (map[i][j] == 5)
			{
				cout << "o";
			}
		} cout << endl;
	}
	cout << "\nMove = A/D  Shoot = W";
}

/////////////////////////////////////////////////////////////////////////

void movement(){
	
	//checks for user input
	if (kbhit())
	{
		char input;
		input = getch();
		
		if (input == 'a' && map[ypos][xpos - 1] == 0 && xpos > 1)
		{
			//ako je igrac stisnuo a i lijevo od njega nije zid stavi da je njegova trenutna pozicija 0 tj. izbrisi ju i stavi da mu je sada pozicija za 1 lijevo
			map[ypos][xpos] = 0;
			xpos = xpos - 1;
			map[ypos][xpos] = 2;
		}
		
		if (input == 'd' && map[ypos][xpos + 1] == 0 && xpos < 18)
		{
			map[ypos][xpos] = 0;
			xpos = xpos + 1;
			map[ypos][xpos] = 2;
		}
		
		if (input == 'w' && shoot == 0)
		{
			//ako je igrac pritisnuo w i ako je metak vec dovrsio svoje putovanje stavi shoot = 1
			shoot = 1;
		}
	}
	
	//opet provjerava ako bomba nije iznad igraca
	if (map[ypos - 1][xpos] == 5)
	{
		over = 2;
	}
}

/////////////////////////////////////////////////////////////////////////

void fire(){
	
	//firing fuction for the player
	if (shoot == 1)
	{
		shoot = 2;
		xbullet = xpos;		//pocetne pozicije metka su iznad igraca
		ybullet = ypos - 1;
	}
	
	if (map[ybullet - 1][xbullet] != 1 && shoot == 2)	//tako dugo dok metak ne nestane igrac ne moze pucati vise
	{
		//stavlja da je trenutna pozicija metka 0 tj. brise ga i stavlja da je druga pozicija iznad y - 1,
		map[ybullet][xbullet] = 0;
		ybullet = ybullet - 1;
		map[ybullet][xbullet] = 4;
	}
	
	if (map[ybullet - 1][xbullet] == 1 || map[ybullet - 1][xbullet] == 3)
	{
		//ako je metak udario zid ili nesto igrac moze opet pucati i stavi da metak nestaje
		shoot = 0;
		map[ybullet][xbullet] = 0;
	}
}

/////////////////////////////////////////////////////////////////////////

void refresh(){
	
	//sets the cursor on the begining of the screen
	COORD cur = {0, 0};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}

/////////////////////////////////////////////////////////////////////////

void enemy(){
	
	//bullet hits invader
	if (map[ybullet - 1][xbullet] == 3)
	{
		map[ybullet - 1][xbullet] = 0;
	}
	
	//random number gen
	int broj = 1 + rand() % 19;
	int chance;
	
	chance = 1 + rand() % 150;
	
	if (chance == 1)
	{
	
	//spawns bombs and moves them down
	if (bombs == 0)		//spawna i sprema pozicije svake bombe
	{
		bombs = 1;
		xbomb[0] = broj;
		ybomb[0] = 3;
		map[ybomb[0]][xbomb[0]] = 5;
	}
	if (bombs == 1)		//spawna i sprema pozicije svake bombe
	{
		broj = 1 + rand() % 19;
		bombs = 2;
		xbomb[1] = broj;
		ybomb[1] = 3;
		map[ybomb[1]][xbomb[1]] = 5;
	}
}
	
	//bombs going down code and checking if the player is at the coords of the bomb and if so ends the game
	if (map[ybomb[0]+ 1][xbomb[0]] != 1)
	{	
		//ako bomba nije dosla do poda igre stavi da je trenutna pozicija 0 te da je nova pozicija za 1 dolje na y osi
		Sleep(50);
		map[ybomb[0]][xbomb[0]] = 0;
		ybomb[0] = ybomb[0] + 1;
		map[ybomb[0]][xbomb[0]] = 5;
		
		if (map[ybomb[0]+ 1][xbomb[0]] == 2)
		{
			//ako je bomba iznad igraca stavi da je igra zavrsila
			over = 2;
		}
		if (map[ybomb[0]+ 1][xbomb[0]] == 1)
		{
			//ako je bomba udarila zid izbrisi ju
			map[ybomb[0]][xbomb[0]] = 0;
		}
	}
	if (map[ybomb[1]+ 1][xbomb[1]] != 1)
	{
		//isto kao i prosli proces samo za bombu 2
		Sleep(50);
		map[ybomb[1]][xbomb[1]] = 0;
		ybomb[1] = ybomb[1] + 1;
		map[ybomb[1]][xbomb[1]] = 5;
		
		if (map[ybomb[1]+ 1][xbomb[1]] == 2)
		{
			over = 2;
		}
		if (map[ybomb[1]+ 1][xbomb[1]] == 1)
		{
			map[ybomb[1]][xbomb[1]] = 0;
			//tek kada zadnja bomba nestane mogu nastati nove
			bombs = 0;
		}
	}
}

/////////////////////////////////////////////////////////////////////////

void checkwin(){

	invader = 18;	//why you work here???????
	
	//provjerava sva polja od y = 1 x = 1 do y = 1 x = 19
	for (int l=1; l < 19; l++)
	{
		if (map[1][l] == 0)
		{
			invader = invader - 1;
		}
	}
	
	if (invader == 0)
	{
		over = 1;
	}
}

/////////////////////////////////////////////////////////////////////////

void end(){
	
	//kraj igre
	system("cls");
	
	if (over == 1)
	{
		cout << "\n\n\n		YOU WIN!\n";
	}
	
	if (over == 2)
	{
		cout << "\n\n\n		YOU LOSE!\n";
	}
	system("pause");
}

/////////////////////////////////////////////////////////////////////////
