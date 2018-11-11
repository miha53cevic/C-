#include <iostream>
#include <cstdlib>
using namespace std;
//Tic - Tac - Toe V4 - Using arrays YEET

//KONSTANTE KOJE SE NE MJENJAJU
const int height = 3;
const int width = 3;

void draw(char **board){

    system("cls");

	string razmak = "				";

	cout << "\n\n\n\n\n";
	cout << razmak << "Krizic Kruzic\n\n\n";
	cout << "                          " << "Player1 = X | Computer = O\n\n";

	cout << razmak << "   |   |   " << endl;
	cout << razmak << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout << razmak << "___|___|___" << endl;
	cout << razmak << "   |   |   " << endl;
	cout << razmak << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << razmak << "___|___|___" << endl;
	cout << razmak << "   |   |   " << endl;
	cout << razmak << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
	cout << razmak << "   |   |   " << endl << endl;

}
//STVARANJE 2D Array-a SA POINTER TO POINTER ARRAY-om
char** get_Array()
{
    //STVARA PRVO SET OD 3 POINTER KOJI KASNIJE KAZU NA JOS SET OD 3 CHAR VARIJABLI ZNACI SVAKI POINTER IMA SET OD 3 CHAR VARIJABLI ZNACI 3*3
    char **board = new char*[height];

    //STVARANJE SET CHAR VARIJABLI ZA SVAKI OD POINTER VARIJABLI KOJI SU NASTALI U POINTER TO POINTER
    for (int i=0;i<height;i++)
    {
        board[i] = new char[width];
    }

    //POPUNJAVANJE ARRAY-a
    board[0][0] = '1';
    board[0][1] = '2';
    board[0][2] = '3';
    board[1][0] = '4';
    board[1][1] = '5';
    board[1][2] = '6';
    board[2][0] = '7';
    board[2][1] = '8';
    board[2][2] = '9';

    //VRACA 2D ARRAY U MAIN()
    return board;
}

void add(char** board, char turn, int input, bool* used)
{
    switch (input)
    {
    case 1:
        {
            //AKO JE MJESTO PRAZNO STAVI ZNAK IGRACA/TURN I STAVI DA JE TO MJESTO POPUNJENO
            if (board[0][0] == '1')
            {
                board[0][0] = turn;
                used[0] = 1;
            }
            break;
        }
    case 2:
        {
            if (board[0][1] == '2')
            {
                board[0][1] = turn;
                used[1] = 1;
            }
            break;
        }
    case 3:
        {
            if (board[0][2] == '3')
            {
                board[0][2] = turn;
                used[2] = 1;
            }
            break;
        }
    case 4:
        {
            if (board[1][0] == '4')
            {
                board[1][0] = turn;
                used[3] = 1;
            }
            break;
        }
    case 5:
        {
            if (board[1][1] == '5')
            {
                board[1][1] = turn;
                used[4] = 1;
            }
            break;
        }
    case 6:
        {
            if (board[1][2] == '6')
            {
                board[1][2] = turn;
                used[5] = 1;
            }
            break;
        }
    case 7:
        {
            if (board[2][0] == '7')
            {
                board[2][0] = turn;
                used[6] = 1;
            }
            break;
        }
    case 8:
        {
            if (board[2][1] == '8')
            {
                board[2][1] = turn;
                used[7] = 1;
            }
            break;
        }
    case 9:
        {
            if (board[2][2] == '9')
            {
                board[2][2] = turn;
                used[8] = 1;
            }
            break;
        }
    }
}

//JELI IGRAC POBJEDIO S ZADNJIM POSTAVLJENIM ZNAKOM
int check_win(char **board, char& turn, bool* used)
{
    for (int i=0;i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
            //TURN NAM GOVORI KOJI JE IGRAC ZADNJI STAVIL SVOJ ZNAK TAKO DA ZNAMO TKO JE POBJEDIL, JER AKO FOR LOOP VIDI DA IMA KOMBINACIJU NE ZAMNJEJUJE IGRACE NEGO ODMA VRACA U MAIN ZBOG RETURN

            //HORIZONTAL WIN
            if (j+2 < width && board[i][j] == turn && board[i][j] == board[i][j+1] && board[i][j] == board[i][j+2])
            {
                return 0;
            }
            //VERTICAL WIN
            if (i+2 < height && board[i][j] == turn && board[i][j] == board[i+1][j] && board[i][j] == board[i+2][j])
            {
                return 0;
            }
            //DIAGONAL RIGHT
            if (i+2 < height && j+2 < width && board[i][j] == turn && board[i][j] == board[i+1][j+1] && board[i][j] == board[i+2][j+2])
            {
                return 0;
            }
            //DIAGONAL LEFT
            if (i+2 < height && j-2 >= 0 && board[i][j] == turn && board[i][j] == board[i+1][j-1] && board[i][j] == board[i+2][j-2])
            {
                return 0;
            }
        }
    }

    //JE LI IZJEDNACENO
    if (used[0] == 1 && used[1] == 1 && used[2] == 1 && used[3] == 1 && used[4] == 1 && used[5] == 1 && used[7] == 1 && used[8] == 1)
    {
        return 2;
    }

    //ZAMJENA IGRACA
    if (turn == 'x')
    {
        turn = 'o';
    }
    else
    {
        turn = 'x';
    }

    //IGRA I DALJE TRAJE
    return -1;
}

int main(){

    //POINTER TO POINTER KASNIJE POSTAJE 2D ARRAY KROZ GET_ARRAY()
    char **p_board;
    //TKO JE NA REDU X ILI O IGRAC
    char turn = 'x';
    //KOJE POLJE ZELI IGRAC UNIJETI SVOJ ZNAK
    int input;
    //TRAJE LI IGRA I JE LI NETKO POBJEDIO -1 - TRAJE, 1 - JEDAN IGRAC JE POBJEDIO, 2 - IZJEDNACENA IGRA
    int game_over=-1;
    //ARRAY KOJI JE KORISTEN DA BI SE ZNALO DA LI JE POLJE POPUNJENO
    bool* used = new bool[height * width];

    //POPUNJAVANJE ARRAY-a SA 0 TAKO DA AKO JE 1 ZNAMO DA JE POPUNJEN
    for (int i=0;i<height * width;i++)
        {
            used[i] = 0;
        }

    p_board = get_Array();
    draw(p_board);

    //SVE DOK IGRA TRAJE ZOVI OVAJ LOOP
    while (game_over == -1)
    {
        loop:

        //KORISNIKOV UNOS
        cout << "Player " << turn << " : ";
        cin >> input;

        //AKO JE UNOS NETOCAN ILI JE POLJE POPUNJENO KAZI IGRACU DA JE GLUP
        if (input < 1 || input > 9 || used[input - 1] == 1)
        {
            cout << "WRONG INPUT!\n";
            goto loop;
        }

        add(p_board, turn, input, used);
        game_over = check_win(p_board, turn, used);
        draw(p_board);
    }

    //JE LI IGRAC POBJEDIO ILI JE IZJEDNACENO/DRAW
    switch (game_over)
    {
    case 1:
        {
            cout << "Player " << turn << " WON!";
        }
    case 2:
        {
            cout << "DRAW!";
        }
    }
}
