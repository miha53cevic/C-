#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void draw();
void logic();

char slot[3] = {

    '$','$','$'
};

int map[7][17] = {

    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,2,0,0,0,3,0,0,0,4,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

int main()
{
    srand(time(NULL));

    string input;

    draw();

    cout << "\n\nTest your luck!\nType spin!\n\nInput: ";
    cin >> input;

    if (input == "spin")
    {
        logic();
    }
}

void draw()
{
    system("cls");

    for (int i=0;i<7;i++)
    {
        for (int j=0;j<17;j++)
        {
            if (map[i][j] == 1)
            {
                cout << char(219);
            }
            else if (map[i][j] == 0)
            {
                cout << " ";
            }
            else if (map[i][j] == 2)
            {
                cout << slot[0];
            }
            else if (map[i][j] == 3)
            {
                cout << slot[1];
            }
            else if (map[i][j] == 4)
            {
                cout << slot[2];
            }
        }
        cout << endl;
    }
}

void logic()
{
    int rand1,rand2,rand3;

    rand1 = 1 + rand() % 3;
    rand2 = 1 + rand() % 3;
    rand3 = 1 + rand() % 3;

    //Jackopt
    if (rand1 == 1)
    {
        slot[0] = '$';
    }
    else if (rand1 == 2)
    {
        slot[0] = '/';
    }
    else if (rand1 == 3)
    {
        slot[0] = '-';
    }

    //Alright
    if (rand2 == 1)
    {
        slot[1] = '$';
    }
    else if (rand2 == 2)
    {
        slot[1] = '/';
    }
    else if (rand2 == 3)
    {
        slot[1] = '-';
    }

    //Nothing
    if (rand3 == 1)
    {
        slot[2] = '$';
    }
    else if (rand3 == 2)
    {
        slot[2] = '/';
    }
    else if (rand3 == 3)
    {
        slot[2] = '-';
    }

    draw();

    int alright,jackpot,nothing;

    for (int i=0;i<3;i++)
    {
        if (slot[i] == '$')
        {
            jackpot++;
        }
        else if (slot[i] == '/')
        {
            alright++;
        }
        else if (slot[i] == '-')
        {
            nothing++;
        }
    }

    if (jackpot == 3)
    {
        cout << "\nJACKPOT!";
    }
    else if (alright == 3)
    {
        cout << "\nALRIGHT!";
    }
    else if (nothing == 3)
    {
        cout << "\nNOTHING!";
    }
    else
    {
        cout << "\nRIP YOU LOST!";
    }
}

/*///////////////
/               /
/               /
/   1   2   3   /
/               /
/               /
///////////////*/
