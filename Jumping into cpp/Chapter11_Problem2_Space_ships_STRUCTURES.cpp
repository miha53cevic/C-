#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int ship_number=5;
int alive[5] = {0,0,0,0,0};

struct Enemy
{
    int x;
    int y;
};

Enemy getNewShip()
{
    Enemy ship;
    ship.x = 0 + rand() % 1024;
    ship.y = 0 + rand() % 768;
    return ship;
}

Enemy moveShip(Enemy ship)
{
    int move = 1 + rand() % 4;

    switch (move)
    {
    case 1:
        {
            ship.x++;
        }
    case 2:
        {
            ship.x--;
        }
    case 3:
        {
            ship.y++;
        }
    case 4:
        {
            ship.y--;
        }
    }
    return ship;
}

void IsAlive(Enemy ship[])
{
    for (int i=0;i<ship_number;i++)
    {
        if (ship[i].x > 1024 || ship[i].x < 0)
        {
            alive[i] = 1;
        }
        else if (ship[i].y > 768 || ship[i].y < 0)
        {
            alive[i] = 1;
        }
    }
}

void draw(Enemy ship[])
{
    for (int i=0;i<ship_number;i++)
    {
        cout << "Ship: " << i << endl;
        cout << "x = " << ship[i].x << endl;
        cout << "y = " << ship[i].y << endl;
        cout << "\n\n";
    }
    //system("pause");
    cout << "\n\n\n";
}

int main()
{
    Enemy ship[ship_number];

        for (int i=0;i<ship_number;i++)
        {
            ship[i] = getNewShip();
        }

    while(alive[0] == 0 || alive[1] == 0 || alive[2] == 0 || alive[3] == 0 || alive[4] == 0)
    {
        for (int i=0;i<ship_number;i++)
        {
            ship[i] = moveShip(ship[i]);
        }

        IsAlive(ship);
        draw(ship);
    }
}
