#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    while(1){

    srand(time(NULL));

    int flip = 1 + rand() % 3;

    switch (flip)
    {
        case 1:
            {
                cout << "HEADS!"; break;
            }
        case 2:
            {
                cout << "TAILS!"; break;
            }
        case 3:
            {
                cout << "BALANCE!";break;
            }
    }

    cout << endl;
    system("pause");
    system ("cls");
    }
}
