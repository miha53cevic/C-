#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool game=true;

char obstacle;
char block = '/0';
char wall = char(178);
char space = ' ';
char plyr = char(254);

int x=1,y=1;
char map[10][20] = {
	wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,
	wall,plyr,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,wall,
	wall,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,wall,
	wall,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,wall,
	wall,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,wall,
	wall,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,wall,
	wall,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,wall,
	wall,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,wall,
	wall,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,space,wall,
	wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall
};

void gotoxy(int gox, int goy){
	map[y][x] = block;
	x = gox;
	y = goy;
	map[y][x] = plyr;
}

/////////////////////////////////////////////////////////////////////

void draw(){
	
	system("cls");
	
	for (int i=0; i<10;i++)
	{
		for (int j=0; j<20;j++)
		{
			if (map[i][j] == wall)
			{
				cout << wall;
			}
			else if (map[i][j] == space)
			{
				cout << " ";
			}
			else if (map[i][j] == plyr)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				cout << plyr;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else if (map[i][j] == block)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				cout << char(254);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
		} cout << endl;
	}
}
/////////////////////////////////////////////////////////////////////

void update(){
	
	draw();
}

/////////////////////////////////////////////////////////////////////

void move(){
	
	if (kbhit())
	{
		char ch = getch();
		
		if (ch == 'w')
		{
			if (map[y-1][x] == space)
			{
				gotoxy(x,y-1);
			}
		} 
		else if (ch == 's')
		{
			if (map[y+1][x] == space)
			{
				gotoxy(x,y+1);
			}
		} 
		else if (ch == 'a')
		{
			if (map[y][x-1] == space)
			{
				gotoxy(x-1,y);
			}
		} 
		else if (ch == 'd')
		{
			if (map[y][x+1] == space)
			{
				gotoxy(x+1,y);
			}
		} 
		update();
	} 
}

/////////////////////////////////////////////////////////////////////

void logic(){
	
	for (int i=1;i<8;i++)
	{
		for (int j=1;j<18;i++)
		{
			if (map[i][j] == block)
			{
				int filled_blocks = 0;
				filled_blocks++;
				
				if (filled_blocks == 144)
				{
					game == false;
				}
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////

int main(){
	
	draw();
	
	while (game == true)
	{	
		move();
		logic();
	}
}
