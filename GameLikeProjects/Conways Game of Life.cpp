#include <iostream>
#include <windows.h>
#include <ctime>
#include <thread>
#include <chrono>
//Mihael Petricevic - Conway's Game Of Life Console Version

//Global Variables
const int nScreenHeight = 25;
const int nScreenWidth = 75;

void ClearScr()
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
}

void DrawScr(int output[][nScreenWidth])
{
    for (int i = 0; i < nScreenHeight; i++)
    {
        for (int j = 0; j < nScreenWidth; j++)
        {
            switch (output[i][j])
            {
                case 0: std::cout << ' '; break;
                case 1: std::cout << char(178); break;
            }
        }
         std::cout << "\n";
    }
}

int main()
{
    srand(time(0));

    //Variables
    int output[nScreenHeight][nScreenWidth];
    int state[nScreenHeight][nScreenWidth];

    //On startup
    memset(output, 0, nScreenHeight * nScreenWidth);
    memset(state, 0, nScreenHeight*nScreenWidth);

    for (int i = 0; i < nScreenHeight; i++)
        for (int j = 0; j < nScreenWidth; j++)
            state[i][j] = rand() % 2;

    //Game Loop
    while (1)
    {
        //Get the last state to output
        for (int i = 0; i < nScreenHeight; i++)
            for (int j = 0; j < nScreenWidth; j++)
                output[i][j] = state[i][j];


        //Get number of neighbours of the cell
        for (int y = 1; y < nScreenHeight - 1; y++)
            for (int x = 1; x < nScreenWidth - 1; x++)
            {
                int nSusjed = output[y - 1][x - 1] + output[y - 1][x + 0] + output[y - 1][x + 1] +
                              output[y + 0][x - 1] +          0           + output[y + 0][x + 1] +
                              output[y + 1][x - 1] + output[y + 1][x + 0] + output[y + 1][x + 1];

                //If im alive
                if (output[y][x] == 1)
                {
                    //If I don't have 2 or 3 neighbours then I die of lonelyness :(
                    if (nSusjed != 2 && nSusjed != 3) state[y][x] = 0;
                }
                //Else if I'm dead and have 3 neighbours then I'm alive again and not lonely :P
                else if (nSusjed == 3) {state[y][x] = 1;}
            }

            //Clear Scr & Draw Scr
            ClearScr();
            DrawScr(output); //Drawing output to Scr
            std::this_thread::sleep_for (std::chrono::milliseconds(200));
    }
}
