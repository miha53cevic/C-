#include <conio.h>
#include <iostream>

using namespace std;

int main(){
char ch;

while( ! kbhit() )
{
	//do stuff
}
 
ch = getch();

if (ch == 'w')
{
	cout << "hello";
}

while (kbhit()) getch();         //clear buffer
fflush (stdin) ;         // clear stdin's buffer

// do other stuff
}

/*
Variation 2
	
	if (kbhit())
	{
		ch = getch();
		
		if (ch == 'w')
		{
			do stuff
		}
	}
	
*/
