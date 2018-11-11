#include <iostream>
using namespace std;

//The factorial function (symbol: !) says to multiply a series
//of descending natural numbers. Examples:
//  !4 = 4 x 3 x 2 x 1 = 24

int factorial(int x)
{
    //AKO JE 1 VRACA 1
    if (x == 1)
    {
        return 1;
    }
    //NAKON STO DODE DA JE X = 1 IDE UNATRAG DOVRSITI OVU FUNKCIJU TAKO DA RECIMO AKO JE X = 2 DODE DA JE X = 1 I VRATI 1 TE NAKON TOGA DOVRSI FUNKCIJU 2 * 1(JER JE TOLKO VRATIL U DRUGOM KRUGU FUNKCIJE)
    else
    {
        return x * factorial(x - 1);
    }
}

//PRIMJER DA FUNKCIJA DOK JE RETURN VRACA ODMAH ZATO OVAJ DRUGI RETURN 1 UOPCE NE RADI
int yeet(int x)
{
    return x;
    return 1;
}

int main()
{
    int x;
    cin >> x;
    cout<< factorial(x);
    //cout << yeet(x);
}
