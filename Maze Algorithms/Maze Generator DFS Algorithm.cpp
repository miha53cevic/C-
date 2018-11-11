#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <ctime>

//Maze Algorith DFS - Mihael Petricevic 2018

//Global Variables

//Map Size
const int nMapHeight = 20;
const int nMapWidth = 40;

//Map 2D array
int Map[nMapHeight][nMapWidth];

//Direction
std::vector<int>dir = {1, 2, 3, 4};


void drawScr()
{

    //REMOVES CURSOR
    CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

    //REFRESHES SCREEN WITHOUTH FLICKER
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD pos;

    pos.X = 0;
    pos.Y = 0;
    SetConsoleCursorPosition(hConsole, pos);

    //Draws the map
    for (int i = 0; i < nMapHeight; i++)
    {
        for (int j = 0; j < nMapWidth; j++)
        {
            switch (Map[i][j])
            {
                case 0: std::cout << "#"; break;
                case 1: std::cout << "."; break;
            }
        }
    std::cout << "\n";
    }
}

//Nasumicno izmješa brojeve u vectoru
void ShuffleDir (std::vector<int>& dir)
{
    std::random_shuffle(dir.begin(), dir.end());
}

//Stvara labirint pomocu REKURZIJE
void createMaze (int x, int y)
{
    drawScr();
    ShuffleDir(dir);

    for ( int i = 0; i < 4; i++ )
    {
        switch (dir[i])
        {
            /*
                1                    up
            2       3         left        right
                4                   down
            */

        case 1:
            {
                //Is cell 2 away from position in the map and is it a wall
                if (y - 2 > 0 && Map[y - 2][x] == 0)
                {
                    //Set the 2 cells to path
                    Map[y - 2][x] = 1;
                    Map[y - 1][x] = 1;

                    //Kreni na sljedecu poziciju
                    createMaze(x, y - 2);
                }
                break;
            }
        case 2:
            {
                if (x - 2 > 0 && Map[y][x - 2] == 0)
                {
                    Map[y][x - 2] = 1;
                    Map[y][x - 1] = 1;

                    createMaze(x - 2, y);
                }
                break;
            }
        case 3:
            {
                if (x + 2 < nMapWidth - 1 && Map[y][x + 2] == 0)
                {
                    Map[y][x + 2] = 1;
                    Map[y][x + 1] = 1;

                    createMaze(x + 2, y);
                }
                break;
            }
        case 4:
            {
                if (y + 2 < nMapHeight - 1 && Map[y + 2][x] == 0)
                {
                    Map[y + 2][x] = 1;
                    Map[y + 1][x] = 1;

                    createMaze(x, y + 2);
                }
                break;
            }
        }
    }
}

int main()
{
    //Seed
    srand(time(0));

    //Creating map
    for (int i = 0; i < nMapHeight; i++)
        for (int j = 0; j < nMapWidth; j++)
            Map[i][j] = 0;

    //Cell COORD
    int x, y;
    x = 1 + rand() % (nMapWidth - 2);
    y = 1 + rand() % (nMapHeight - 2);

    //std::cout << "x = " << x << "\ny = " << y << "\n";

    createMaze(x, y);

    return 0;
}
