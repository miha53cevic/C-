#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <chrono>
#include <thread>
//Flappy Bird - Mihael Petricevic

enum MapObjects { EMPTY, PIPE, BIRD, GROUND };

struct Pipe
    {
        int x;
        int y;
    };

void ClearScr ()
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

void DrawScr ( const int& nMapHeight, const int& nMapWidth, const auto& vecMap, const unsigned int& uScore )
{
    for ( int i = 0; i < nMapHeight; i++ )
    {
        for ( int j = 0; j < nMapWidth; j++ )
        {
            switch ( vecMap[i][j] )
            {
                case EMPTY: std::cout << " "; break;
                case PIPE: std::cout << "*"; break;
                case BIRD: std::cout << "&"; break;
                case GROUND: std::cout << "="; break;
            }
        }

        std::cout << std::endl;
    }

    std::cout << "Score: " << uScore << "\n";
}

bool KeyBoardHit ()
{
    if ( kbhit() )
    {
        getch();

        return true;
    }

    else return false;
}

void DrawObject ( const int& x, const int& y, auto& vecMap, const MapObjects& Object )
{
    vecMap[y][x] = Object;
}

void DeleteObject ( const int& x, const int& y, auto& vecMap )
{
    vecMap[y][x] = EMPTY;
}

void Flap ( int& nPlayerY )
{
    nPlayerY -= 2;

    if ( nPlayerY < 0 )
    {
        nPlayerY = 0;
    }
}

void Collision (const int& nPlayerX, const int& nPlayerY, const int& nMapHeight, const auto& vecMap, bool& GameOver )
{
    if ( nPlayerY == nMapHeight - 1 )
    {
        GameOver = true;
    }

    else if ( vecMap[nPlayerY][nPlayerX + 1] == PIPE )
    {
            GameOver = true;
    }
}

void SpawnPipe ( auto& vecPipes, bool& nextPipe, int& nPipeNum, const int& nMapWidth, const int& nMapHeight )
{

    if ( nPipeNum < 3 && nextPipe == true)
    {
        nextPipe = false;
        nPipeNum++;

        Pipe pipe;
        pipe.x = nMapWidth - 1;
        pipe.y = 2 + rand() % (nMapHeight - 9);

        //NEMOJ RADITI COUT AKO REFRESHAS SCREENA JER ONDA SE MJENJA SAMO ZNAMEKNA KOJA SE TREBA NPR.
        //16 I ONDA MORAM NAPISATI 7 BUDE NAPISAL 76 JER MISLI DA SE 6 NE MJENJA
        //std::cout << pipe.y;

        vecPipes.push_back(pipe);
    }
}

void MovePipe ( auto& vecPipes, bool& nextPipe, int& nPipeNum, const int& nMapWidth )
{

    //Move pipe to the left
    for ( int i=0; i < nPipeNum; i++ )
    {
        vecPipes[i].x -= 1;

        if ( vecPipes[i].x == nMapWidth - 15 )
        {
            nextPipe = true;
        }

        if ( vecPipes[i].x == 0 )
        {
            nPipeNum--;
            vecPipes.erase( vecPipes.begin() + i );
        }
    }
}

void DrawPipe ( const auto& vecPipes, const int& nPipeNum, auto& vecMap, const int& nMapHeight )
{
    for ( int i = 0; i < nPipeNum; i++ )
    {
        for ( int j = 0; j < nMapHeight - 1; j++ )
        {
            //Draw a wall withouth a hole
            vecMap[j][vecPipes[i].x] = PIPE;
        }

        for ( int k = 0; k < 5; k++ )
        {
            //Create the hole in the position gotten before from rand() = y
            vecMap[vecPipes[i].y + k][vecPipes[i].x] = EMPTY;
        }

    }
}

void DeletePipe ( const auto& vecPipes, const int& nPipeNum, auto& vecMap, const int& nMapHeight )
{
    for ( int i = 0; i < nPipeNum; i++ )
        for ( int j = 0; j < nMapHeight - 1; j++ )
        {
            //Delete last pipe position hence the x + 1

            if ( vecPipes[i].x + 1 != 40 )
            {
                vecMap[j][vecPipes[i].x + 1] = EMPTY;
            }

            //Clear the first pipe after it hits the end
            vecMap[j][1] = EMPTY;
        }
}

void AddScore ( const int& nPlayerX, const auto& vecPipes, unsigned int& uScore )
{
    for ( auto &i : vecPipes )
    {
        if ( i.x == nPlayerX ) uScore += 1;
    }
}

int main()
{
    //srand(time(0));

    int const nMapHeight = 20;
    int const nMapWidth = 40;

    bool GameOver = false;

    unsigned int uScore = 0;
    float fSlowDown = 0.f;

    //Creating 2D vector named vecMap
    std::vector< std::vector< MapObjects > > vecMap;
    vecMap.resize( nMapHeight, std::vector < MapObjects > (nMapWidth) );

    //Default Map
    for ( int i = 0; i < nMapHeight; i++ )
        for ( int j = 0; j < nMapWidth; j++ )
        {
            if ( i == nMapHeight - 1 )
            {
                vecMap[i][j] = GROUND;
            }
            else
            {
                vecMap[i][j] = EMPTY;
            }
        }

    //Player COORD
    int const nPlayerX = 3;
    int nPlayerY = nMapHeight / 2;

    //Draw Player at start
    DrawObject ( nPlayerX, nPlayerY, vecMap, BIRD );

    //Pipe variables
    std::vector< Pipe > vecPipes;
    bool nextPipe = true;
    int nPipeNum = 0;

    //Main game loop
    while ( !GameOver )
    {
        //Sleep on thread
        std::this_thread::sleep_for (std::chrono::milliseconds(100));

        //Keyboard input
        if ( KeyBoardHit() )
        {
            //Player controller
            DeleteObject ( nPlayerX, nPlayerY, vecMap );
            Flap ( nPlayerY );
            DrawObject ( nPlayerX, nPlayerY, vecMap, BIRD );
        }

        //Gravity
        if ( fSlowDown == 0.5f )
        {
            fSlowDown = 0.f;

            DeleteObject ( nPlayerX, nPlayerY, vecMap );
            nPlayerY++;
            DrawObject ( nPlayerX, nPlayerY, vecMap, BIRD );
        }
        else fSlowDown += 0.5f;

        //Collision
        Collision ( nPlayerX, nPlayerY, nMapHeight, vecMap, GameOver );

        //Pipe controller
        SpawnPipe ( vecPipes, nextPipe, nPipeNum, nMapWidth, nMapHeight );
        DeletePipe ( vecPipes, nPipeNum, vecMap, nMapHeight );
        DrawPipe( vecPipes, nPipeNum, vecMap, nMapHeight );
        MovePipe ( vecPipes, nextPipe, nPipeNum, nMapWidth );

        //Score System
        AddScore ( nPlayerX, vecPipes, uScore );

        //Draw & Refresh Screen
        ClearScr();
        DrawScr( nMapHeight, nMapWidth, vecMap, uScore );

    }

    system("pause");

    return 0;
}
