#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <ctime>
using namespace std;
//Attempt at a snake game

int map[11][21] = {
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

int x[10],y[10];
int direction=0;
int tail_num=0;

void draw();
void controls();
void moving();
void fruit();
void collision();
void tails();

///////////////////////////////////////////////////////////////////////////////

int main(){
	
	srand(time(0));
	
	x[0] = 10;
	y[0] = 5;
	map[y[0]][x[0]] = 2;
	fruit();
	
	while(1){
		
		draw();
		controls();
		moving();
		collision();
		tails();
		Sleep(500);
	}
}

///////////////////////////////////////////////////////////////////////////////

void draw(){
	
	//sets the cursor on the begining of the screen
	COORD cur = {0, 0};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
	
	for (int i=0;i < 11;i++)
	{
		for (int j=0;j < 21;j++)
		{
			if (map[i][j] == 1)
			{
				cout << "#";
			}
			if (map[i][j] == 0)
			{
				cout << " ";
			}
			if (map[i][j] == 2)
			{
				cout << "o";
			}
			if (map[i][j] == 3)
			{
				cout << "x";
			}
		}
		cout << endl;
	}
}

///////////////////////////////////////////////////////////////////////////////

void controls(){
	
/*
		1			w
	3		4	a		d
		2			s
*/
	
	
	//koji je unos korisnik dao
	if (kbhit())
	{
		char key = getch();
		
		if (key == 'w' && map[y[0]-1][x[0]] == 0)
		{
			direction = 1;	
		}
		
		else if (key == 's' && map[y[0]+1][x[0]] == 0)
		{
			direction = 2;	
		}
		
		else if (key == 'a' && map[y[0]][x[0]-1] == 0)
		{
			direction = 3;	
		}
		
		else if (key == 'd' && map[y[0]][x[0]+1] == 0)
		{
			direction = 4;	
		}
	}
}

///////////////////////////////////////////////////////////////////////////////

void moving(){
	
//kretanje u neku stranu
	if (direction == 1 && map[y[0]-1][x[0]] == 0)
	{
		map[y[0]][x[0]] = 0;
		y[0]--;
		map[y[0]][x[0]] = 2;
	}
	
	else if (direction == 2 && map[y[0]+1][x[0]] == 0)
	{
		map[y[0]][x[0]] = 0;
		y[0]++;
		map[y[0]][x[0]] = 2;
	}
	
	else if (direction == 3 && map[y[0]][x[0]-1] == 0)
	{
		map[y[0]][x[0]] = 0;
		x[0]--;
		map[y[0]][x[0]] = 2;
	}
	
	else if (direction == 4 && map[y[0]][x[0]+1] == 0)
	{
		map[y[0]][x[0]] = 0;
		x[0]++;
		map[y[0]][x[0]] = 2;
	}
}

///////////////////////////////////////////////////////////////////////////////

void fruit(){
	
	int fx,fy;
	
	fx =  0 + rand() % 20; 
	fy =  0 + rand() % 10;
	
	while (map[fy][fx] != 0)
	{
		fx =  0 + rand() % 20; 
		fy =  0 + rand() % 10;
	} 
	
	map[fy][fx] = 3;
}

///////////////////////////////////////////////////////////////////////////////

void collision(){
	
	if (map[y[0]-1][x[0]] == 3 && direction == 1)
	{
		tail_num++;
	}
	
	else if (map[y[0]+1][x[0]] == 3 && direction == 2)
	{
		tail_num++;
		
	}
	
	else if (map[y[0]][x[0]-1] == 3 && direction == 3)
	{
		tail_num++;
		
	}
	
	else if (map[y[0]][x[0]+1] == 3 && direction == 4)
	{
		tail_num++;
		
	}
}

///////////////////////////////////////////////////////////////////////////////

void tails(){
	
	for(int i=1;i <= tail_num;i++)
	{
		y[tail_num+1-i] = y[tail_num-i]
		x[tail_num+1-i] = x[tail_num-i]
	}
	
	if (map[y[0]-1][x[0]] == 3 && direction == 1)
	{
		map[y[0]-1][x[0]] = 0;
	}
	
	else if (map[y[0]+1][x[0]] == 3 && direction == 2)
	{
		map[y[0]+1][x[0]] = 0;
	}
	
	else if (map[y[0]][x[0]-1] == 3 && direction == 3)
	{
		map[y[0]][x[0]-1] = 0;
	}
	
	else if (map[y[0]][x[0]+1] == 3 && direction == 4)
	{
		map[y[0]][x[0]+1] = 0;
	}
}

///////////////////////////////////////////////////////////////////////////////
