#include <conio.h>
#include <iostream>

using namespace std;

int main()
{
    while(1)
    {
    	cout << "Hello";
        if(kbhit())
        {
            break;
        }
    }
    while (kbhit()) getch();         //clear buffer
	fflush (stdin) ;         // clear stdin's buffer
}
