#include <iostream>
using namespace std;

//NAKON KAJ IF PRESTANI VRIJEDITI SVAKA FUNKCIJA OD ZADNJE DO PRVE MORA DOVRSITI TE ZATO JOS ISPISUJE BROJEVE OD 9 DO 1
void printNum(int num)
{
    cout << num;

    if (num < 9)
    {
        printNum(num + 1);
    }
    cout << num;
}

int main()
{
    printNum(1);
}
