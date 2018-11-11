#include <iostream>
using namespace std;

//PROBAJ NACRTATI DIJAGRAM KAO U JUMPING INTO C++ RECURSIONS
/*
ZA PRIMJER 3^3 = 27

        x * pow(x, y - 1)
POW2    3       3    1      return 3
POW1    3       3    2      return 3 * pow(3, 2 - 1) --> return 3 * 3 JER UZIMA KAJ JE VRATIL POW2
POW     3       3    3      return 3 * pow(3, 3 - 1) --> return 3 * 9 JER UZIMA KAJ JE VRATIL POW1
MAIN                        VRACA 3 * 9 = 27

POW2    x = 3, y = 1    return 3
 ^
POW1    x = 3, y = 2    return 3 x 3 = 9
 ^
POW     x = 3, y = 3    return 3 x 9 = 27
 ^
MAIN    27
*/
int pow(int x, int y)
{
    if (y == 1)
    {
        return x;
    }
    else
    {
        return x * pow(x,y - 1);
    }
}

int main()
{
    int x,y;
    cout << "Enter a number: ";
    cin >> x;
    cout << "Enter the ^number you would like to use: ";
    cin >> y;

    cout << pow(x,y);
}
