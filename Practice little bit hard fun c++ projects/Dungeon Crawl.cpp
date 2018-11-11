#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;
//Dungeon Crawl

int map[6][10] = {
	4,4,4,4,4,4,4,4,4,4,
	4,0,0,0,0,0,0,0,0,4,
	4,0,0,0,0,0,0,0,0,4,
	4,0,0,0,0,0,0,0,0,4,
	4,0,0,0,0,0,0,0,0,4,
	4,4,4,4,4,4,4,4,4,4
	};
	
	int turn=0;
	int xpos=5,ypos=3;
	int l=0;
	int xenemy;
	int yenemy;
	
	void draw();
	void logic();
	void moving();
	void traps();
	void enemy();
	void enemy_movement();

int main(){
	
	srand(time(0));
	map[ypos][xpos] = 1;
	
	traps();
	enemy();
	
	while(1)
	{
		draw();
		moving();
		enemy_movement();
	}
}

void draw(){
	
	//drawing the game board
	
	//sets the cursor on the begining of the screen
	COORD cur = {0, 0};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
	
	for (int i=0;i<6;i++)
	{
		for (int j=0; j<10;j++)
		{
			if (map[i][j] == 0)
			{
				cout << ".";
			}
			if (map[i][j] == 1)
			{
				cout << "P";
			}
			if (map[i][j] == 2)
			{
				cout << "T";
			}
			if (map[i][j] == 3)
			{
				cout << "E";
			}
			if (map[i][j] == 4)
			{
				cout << "*";
			}
		}
		cout << endl;
	}
}

void moving(){
	
	if (kbhit())
	{
		
		turn = 1;
		
		char key;
		key = getch();
		
		//is the player on the enemy
		if (key == 'a' && map[ypos][xpos-1] == 3)
		{
			map[yenemy][xenemy] = 0;
			map[ypos][xpos] = 3;
			exit(0);
		}
		if (key == 'd' && map[ypos][xpos+1] == 3)
		{
			map[yenemy][xenemy] = 0;
			map[ypos][xpos] = 3;
			exit(0);
		}
		if (key == 'w' && map[ypos-1][xpos] == 3)
		{
			map[yenemy][xenemy] = 0;
			map[ypos][xpos] = 3;
			exit(0);
		}
		if (key == 's' && map[ypos+1][xpos] == 3)
		{
			map[yenemy][xenemy] = 0;
			map[ypos][xpos] = 3;
			exit(0);
		}
		
		//Is the player on a trap
		if (key == 'a' && map[ypos][xpos-1] == 2)
		{
			exit(0);
		}
		if (key == 'd' && map[ypos][xpos+1] == 2)
		{
			exit(0);
		}
		if (key == 'w' && map[ypos-1][xpos] == 2)
		{
			exit(0);
		}
		if (key == 's' && map[ypos+1][xpos] == 2)
		{
			exit(0);
		}
		
		//movment controls
		if (key == 'a' && map[ypos][xpos-1] == 0)
		{
			map[ypos][xpos] = 0;
			xpos = xpos-1;
			map[ypos][xpos] = 1;
		}
		
		if (key == 'd' && map[ypos][xpos+1] == 0)
		{
			map[ypos][xpos] = 0;
			xpos = xpos+1;
			map[ypos][xpos] = 1;
		}
		
		if (key == 'w' && map[ypos-1][xpos] == 0)
		{
			map[ypos][xpos] = 0;
			ypos = ypos-1;
			map[ypos][xpos] = 1;
		}
		
		if (key == 's' && map[ypos+1][xpos] == 0)
		{
			map[ypos][xpos] = 0;
			ypos = ypos+1;
			map[ypos][xpos] = 1;
		}
	}
}

void traps(){
	
	//drawing traps at random x,y
	
	while (l < 2)
	{
		int xbroj = 0 + rand() % 9;
		int ybroj = 0 + rand() % 5;
		
		if (map[ybroj][xbroj] == 0)
		{
			map[ybroj][xbroj] = 2;
			l++;
		}
		else
		{
			traps();
		}
	}
}

void enemy(){
	
	//enemy starting pos
	
	xenemy = 0 + rand() % 9;
	yenemy = 0 + rand() % 5;
	
	if (map[yenemy][xenemy] == 0)
	{
		map[yenemy][xenemy] = 3;	
	}
	else enemy();
}

void enemy_movement(){
	
	//random movement of enemy
	
	int random = 1 + rand() % 4;
	
	//if theres a wall or trap move to the other direction
	if (turn == 1)
	{
	
	if (random == 1 && map[yenemy][xenemy-1] != 0)
		{
			enemy_movement();
		}
	else if (random == 2 && map[yenemy][xenemy+1] != 0)
		{
			enemy_movement();
		}
	else if (random == 3 && map[yenemy-1][xenemy] != 0)
		{
			enemy_movement();
		}
	else if (random == 4 && map[yenemy+1][xenemy] != 0)
		{
			enemy_movement();
		}
	}
	//is the player touched by the enemy
	if (random == 1 && map[yenemy][xenemy-1] == 1)
		{
			map[yenemy][xenemy] = 0;
			map[ypos][xpos] = 3;
			draw();
			exit(0);
		}
	else if (random == 2 && map[yenemy][xenemy+1] == 1)
		{
			map[yenemy][xenemy] = 0;
			map[ypos][xpos] = 3;
			draw();
			exit(0);
		}
	else if (random == 3 && map[yenemy-1][xenemy] == 1)
		{
			map[yenemy][xenemy] = 0;
			map[ypos][xpos] = 3;
			exit(0);
		}
	else if (random == 4 && map[yenemy+1][xenemy] == 1)
		{
			map[yenemy][xenemy] = 0;
			map[ypos][xpos] = 3;
			draw();
			exit(0);
		}
	
	//moving the enemy in random directions
	
	if (turn == 1)
	{
		if (random == 1 && map[yenemy][xenemy-1] == 0)
		{
			map[yenemy][xenemy] = 0;
			xenemy = xenemy - 1;
			map[yenemy][xenemy] = 3;
		}
		else if (random == 2 && map[yenemy][xenemy+1] == 0)
		{
			map[yenemy][xenemy] = 0;
			xenemy = xenemy + 1;
			map[yenemy][xenemy] = 3;
		}
		else if (random == 3 && map[yenemy-1][xenemy] == 0)
		{
			map[yenemy][xenemy] = 0;
			yenemy = yenemy - 1;
			map[yenemy][xenemy] = 3;
		}
		else if (random == 4 && map[yenemy+1][xenemy] == 0)
		{
			map[yenemy][xenemy] = 0;
			yenemy = yenemy + 1;
			map[yenemy][xenemy] = 3;
		}
		
		turn = 0;
	}
}
/*
	1 = lijevo
	2 = desno
	3 = gore
	4 = dolje
*/
