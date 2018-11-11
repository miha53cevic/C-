#include <iostream>
#include <cstdlib>
using namespace std;

void draw();
bool win();
void logic(int);

bool plyr = 0;
int turn=1;

enum TicTacToeSquare {BLANK = 0, O = 1, X = 2};
TicTacToeSquare square[9] = {BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK};

int main()
{
    int choice;

    draw();

    if (plyr == 0)
    {
        cout << "PLAYER X: ";
        cin >> choice;
        turn = 1;
        plyr = 1;
        logic(choice);
    }
    else
    {
        cout << "PLAYER O: ";
        cin >> choice;
        turn = 2;
        plyr = 0;
        logic(choice);
    }

    return 0;
}

void draw()
{
    system("cls");
    string razmak = "				";

	cout << "\n\n\n\n\n";
	cout << razmak << "Krizic Kruzic\n\n\n";
	cout << "                          " << "Player = X | Computer = O\n\n";

	cout << razmak << "   |   |   " << endl;
	cout << razmak << " " << square[0] << " | " << square[1] << " | " << square[2] << endl;
	cout << razmak << "___|___|___" << endl;
	cout << razmak << "   |   |   " << endl;
	cout << razmak << " " << square[3] << " | " << square[4] << " | " << square[5] << endl;
	cout << razmak << "___|___|___" << endl;
	cout << razmak << "   |   |   " << endl;
	cout << razmak << " " << square[6] << " | " << square[7] << " | " << square[8] << endl;
	cout << razmak << "   |   |   " << endl << endl;
}

void logic(int x)
{
    switch (turn)
    {
    case 1:
        if (square[x-1] == BLANK)
        {
            square[x-1] = X;
        }
    case 2:
        if (square[x-1] == BLANK)
        {
            square[x-1] = O;
        }
    }

    if (win())
    {
        system ("cls");
        cout << "END OF MATCH!";
    }
    else main();
}

bool win()
{
    return false;
}
