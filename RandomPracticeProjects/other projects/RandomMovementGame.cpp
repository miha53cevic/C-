#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

int xpos,ypos;

int map[10][20] = {
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

void map_draw();
void movement();

int main(){
	
	xpos = 1;
	ypos = 1;
	
	while(1){
		movement();
		map_draw();
	}
}

/////////////////////////////////////////////////////////////

void map_draw(){
	
	COORD cur = {0, 0};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
	
	for (int i=0; i < 10; i++)
	{
		for (int j=0; j < 20; j++)
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
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				cout << "X";
			}
		} cout << endl;
	} Sleep(50);
}

/////////////////////////////////////////////////////////////

void movement(){
	
	if (kbhit())
	{
		char input;
		
		input = getch();
		
		if (input == 'w' && map[ypos - 1][xpos] == 0 && ypos > 0)
		{
			map[ypos][xpos] = 0;
			ypos = ypos - 1;
		}
		if (input == 's' && map[ypos + 1][xpos] == 0 && ypos < 9)
		{
			map[ypos][xpos] = 0;
			ypos = ypos + 1;
		}
		if (input == 'a' && map[ypos][xpos - 1] == 0 && xpos > 0)
		{
			map[ypos][xpos] = 0;
			xpos = xpos - 1;
		}
		if (input == 'd' && map[ypos][xpos + 1] == 0 && xpos < 19)
		{
			map[ypos][xpos] = 0;
			xpos = xpos + 1;
		}
	}
	
	map[ypos][xpos] = 2;
	
	/*
	while (kbhit()) getch();         //clear buffer
	fflush (stdin) ;         // clear stdin's buffer
	*/
}
