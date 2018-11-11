#include <iostream>
#include <thread>
#include <windows.h>
#include <chrono>
#include <conio.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

enum direction { LEFT, RIGHT, SHOOT };
enum objects { EMPTY, WALL, PLAYER, ENEMY, BULLET, BOMB };

struct Bomb
    {
        int x;
        int y;
        bool alive = true;
    };

void Clearscr()
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

bool KeyboardInput( direction& Input )
{
    if (kbhit())
    {
        char input = getch();

        if ( input == 'a')
        {
            Input = LEFT;
            return true;
        }

        else if ( input == 'd' )
        {
            Input = RIGHT;
            return true;
        }

        else if ( input == 'w' )
        {
            Input = SHOOT;
            return true;
        }
    }
    else return false;
}

void Drawscr(const auto &GameMap, const int &nMapSizeX, const int &nMapSizeY, const int& Score)
{

    for (int i = 0; i < nMapSizeY; i++)
    {
        for (int j = 0; j < nMapSizeX; j++)
        {
            switch (GameMap[i][j])
            {
                case EMPTY: std::cout << " "; break;
                case PLAYER: std::cout << "x"; break;
                case WALL: std::cout << "#"; break;
                case ENEMY: std::cout << "M"; break;
                case BULLET: std::cout << "*"; break;
                case BOMB: std::cout << "o"; break;
            }
        }

        std::cout << std::endl;
    }

    //Score and controls
    std::cout << "\nScore: " << Score << "\nControls: W = Shoot, A/D = Move";
}

void DrawObject( auto &GameMap, const int& x, const int& y, const objects& Object )
{
    GameMap[y][x] = Object;
}

void DeleteObject( auto &GameMap, const int& x, const int& y)
{
    GameMap[y][x] = EMPTY;
}

void PlayerMove( int& x, int& y, auto& gameMap, const direction Input )
{
    switch ( Input )
    {
    case LEFT:
        {
            if ( gameMap[y][x - 1] != WALL )
            {
                x--;
            }

            break;
        }
    case RIGHT:
        {
            if ( gameMap[y][x + 1] != WALL )
            {
                x++;
            }

            break;
        }
    }
}

void MoveBullet ( int& BulletX, int& BulletY )
{
    BulletY -= 1;
}

void isBulletAlive ( int& BulletX, int& BulletY, auto& gameMap, bool& BulletAlive, int& EnemyLeft, int& Score )
{
    if ( gameMap[BulletY - 1][BulletX] == ENEMY)
    {
        //Delete Enemy && Remove an enemy from the container
        DeleteObject( gameMap, BulletX, BulletY - 1 );

        //Decrease enemy count by 1
        EnemyLeft--;

        //Add score to player
        Score += 20;

        //Delete Bullet
        DeleteObject( gameMap, BulletX, BulletY );
        BulletAlive = false;
    }
    else if ( BulletY - 1 < 0 )
    {
        DeleteObject( gameMap, BulletX, BulletY );
        BulletAlive = false;
    }
}

bool isGameOver ( const int& EnemyLeft, const bool& bPlayerAlive )
{
    if ( EnemyLeft == 0 )
    {
        return true;
    }

    else if ( !bPlayerAlive )
    {
        return true;
    }

    return false;
}

void BombCollision ( auto& vecBombs, auto& gameMap, bool& bPlayerAlive )
{
    for ( auto &i : vecBombs )
    {
        if ( gameMap[i.y + 1][i.x] == PLAYER )
        {
            bPlayerAlive = false;
        }

        else if ( i.y + 1 > 13 )
        {
            i.alive = false;
            DeleteObject( gameMap, i.x, i.y );
        }
    }
}

void MoveBombs ( auto& vecBombs, auto& gameMap )
{
    for ( auto &i : vecBombs )
    {
        if ( i.alive && i.x != 0)
        {
            DeleteObject( gameMap, i.x, i.y );

            i.y += 1;

            DrawObject( gameMap, i.x, i.y, BOMB);
        }
    }
}

void CreateBombs ( auto& vecBombs, int& nBombCount, const int& nMapSizeX )
{
    Bomb bomb;
    int rSpawn = 1 + rand() % 100;
    bomb.x = 1 + rand() % nMapSizeX - 2;
    bomb.y = 2;
    bomb.alive = true;

    if ( rSpawn <= 5 )
    {
        vecBombs.push_back(bomb);

        nBombCount += 1;
    }
}

void isBombAlive ( auto& vecBombs, int& nBombCount )
{
    for ( int i=0; i < nBombCount; i++ )
    {
        if ( vecBombs[i].alive == false )
        {
            vecBombs.erase(vecBombs.begin() + i);
            nBombCount--;
        }
    }
}

int main()
{
    //srand(time(0));

    int nMapSizeX = 20;
    int nMapSizeY = 15;

    std::vector < std::vector <objects> > gameMap;
    gameMap.resize (nMapSizeY, std::vector < objects > (nMapSizeX));

    //DEFAULT GAMEMAP SETTINGS
    for (int i = 0; i < nMapSizeY; i++)
        for (int j = 0; j < nMapSizeX; j++)
        {
            if (j == nMapSizeX - 1 || j == 0 )
            {
                gameMap[i][j] = WALL;
            }
            else if ( i < 2 && j > 0 && j < nMapSizeX - 1)
            {
                gameMap[i][j] = ENEMY;
            }
            else if ( i == nMapSizeY - 1 && j == (nMapSizeX - 1) / 2 )
            {
                gameMap[i][j] = PLAYER;
            }
            else
            {
                gameMap[i][j] = EMPTY;
            }
        }

    int PlayerX = (nMapSizeX - 1) / 2;
    int PlayerY = nMapSizeY - 1;
    bool bPlayerAlive = true;

    int Score = 0;
    int EnemyLeft = (nMapSizeX - 2) * 2;

    int nBombCount = 0;
    const int nMaxBombCount = 3;
    std::vector < Bomb > vecBombs;

    int BulletX = 0;
    int BulletY = 0;
    bool BulletAlive = false;

    direction Input;

    //GAME LOOP
    while ( !isGameOver( EnemyLeft, bPlayerAlive ) )
    {
        //Sleep
        std::this_thread::sleep_for (std::chrono::milliseconds(100));

        //Keyboard input
        if ( KeyboardInput ( Input ) )
        {
            if ( Input == LEFT || Input == RIGHT )
            {
                //PLAYER CONTROLLER
                DeleteObject( gameMap, PlayerX, PlayerY );
                PlayerMove( PlayerX, PlayerY, gameMap, Input );
                DrawObject( gameMap, PlayerX, PlayerY, PLAYER);
            }
            else if ( Input == SHOOT )
            {
                //BULLET CONTROLLER
                if (BulletAlive == false)
                {
                    BulletAlive = true;
                    BulletX = PlayerX;
                    BulletY = PlayerY - 1;
                }
            }
        }

        //MOVE BULLET
        if ( BulletAlive )
        {
            DeleteObject( gameMap, BulletX, BulletY );
            MoveBullet ( BulletX, BulletY );
            DrawObject( gameMap, BulletX, BulletY, BULLET);
            isBulletAlive ( BulletX, BulletY, gameMap, BulletAlive, EnemyLeft, Score );
        }

        //BOMB CONTROLLER
        if ( nBombCount < nMaxBombCount)
        {
            CreateBombs ( vecBombs, nBombCount, nMapSizeX );
        }

        BombCollision ( vecBombs, gameMap, bPlayerAlive );
        MoveBombs ( vecBombs, gameMap );
        isBombAlive ( vecBombs, nBombCount );

        //DRAW & CLEAR
        Clearscr();
        Drawscr( gameMap, nMapSizeX, nMapSizeY, Score );
    }

    if ( EnemyLeft == 0 )
    {
        system ("cls");
        std::cout << R"(
 __     ______  _    _  __          _______ _   _
 \ \   / / __ \| |  | | \ \        / /_   _| \ | |
  \ \_/ / |  | | |  | |  \ \  /\  / /  | | |  \| |
   \   /| |  | | |  | |   \ \/  \/ /   | | | . ` |
    | | | |__| | |__| |    \  /\  /   _| |_| |\  |
    |_|  \____/ \____/      \/  \/   |_____|_| \_|

        )";
        std::cout << std::setw(25) << "SCORE: " << Score;
    }

    else if ( bPlayerAlive == false )
    {
        system ("cls");
        std::cout << R"(
 __     ______  _    _   _      ____   _____ ______
 \ \   / / __ \| |  | | | |    / __ \ / ____|  ____|
  \ \_/ / |  | | |  | | | |   | |  | | (___ | |__
   \   /| |  | | |  | | | |   | |  | |\___ \|  __|
    | | | |__| | |__| | | |___| |__| |____) | |____
    |_|  \____/ \____/  |______\____/|_____/|______|

        )";
        std::cout << std::setw(25) << "SCORE: " << Score;
    }

    return 0;
}
