#include <iostream>
#include <cstdlib>
using namespace std;
//CHAPTER 23 JUMPING INTO C++

enum TURN {place_holder ,Player_X, Player_O};
enum BOARD_PIECE {EMPTY, X, O};
const int size = 3;

struct board
{
    BOARD_PIECE board[size][size] = {{}};
    TURN player;

    //DELKLARACIJE FUNKCIJA
    TURN get_turn();
    int get_move(TURN x);
    void get_cordinates(int input, int& x, int& y);
    void make_move(int x, int y, TURN turn);
    bool check_win();
    void draw();
};

//FUNKCIJA DRAW CRTA IGRACE POLJE I TEXT TIC TAC TOE
void board::draw()
{
    system("cls");

    //RAW STRING LITERAL POGLEDAJ https://www.geeksforgeeks.org/raw-string-literal-c/
    cout << R"(

_____ _____ _____   _____ ___  _____   _____ _____ _____
|_   _|_   _/  __ \ |_   _/ _ \/  __ \ |_   _|  _  |  ___|
  | |   | | | /  \/   | |/ /_\ \ /  \/   | | | | | | |__
  | |   | | | |       | ||  _  | |       | | | | | |  __|
  | |  _| |_| \__/\   | || | | | \__/\   | | \ \_/ / |___
  \_/  \___/ \____/   \_/\_| |_/\____/   \_/  \___/\____/

    )";

    string razmak = "                        ";
    cout << razmak << "\n\n\n";
    cout << "               Player 1 = X | Player 2 = O" << endl << endl;

    //KORISTI SE DA BI SE SVAKO POLJE NUMERIRALO
    int k = 1;

    for (int i=0;i<size;i++)
    {
        cout << razmak;

        for (int j=0;j<size;j++)
        {
            if (board[i][j] == EMPTY)
            {
                cout << " " << k << " ";
            }
            else if (board[i][j] == X)
            {
                cout << " x ";
            }
            else if (board[i][j] == O)
            {
                cout << " o ";
            }
            k++;
        }
        cout << endl;
    }

}

//VRACA KOJI JE IGRAC NA REDU
TURN board::get_turn()
{
    if (player == Player_X)
    {
        return player = Player_O;
    }
    else
    {
        return player = Player_X;
    }
}

//PITA KORISNIKA NA KOJE POLJE ZELI STAVITI FIGURU
int board::get_move(TURN x)
{
    int input;

    cout << "Player " << x << " : ";
    cin >> input;

    return input;
}

//SAZNAJ KORDINATE POLJA KOJE KORISNIK ZELI PROMJENITI
void board::get_cordinates(int input, int& x, int& y)
{
    switch (input)
    {
    case 1:
        {
            x = 0;
            y = 0;
            break;
        }
    case 2:
        {
            x = 1;
            y = 0;
            break;
        }
    case 3:
        {
            x = 2;
            y = 0;
            break;
        }
    case 4:
        {
            x = 0;
            y = 1;
            break;
        }
    case 5:
        {
            x = 1;
            y = 1;
            break;
        }
    case 6:
        {
            x = 2;
            y = 1;
            break;
        }
    case 7:
        {
            x = 0;
            y = 2;
            break;
        }
    case 8:
        {
            x = 1;
            y = 2;
            break;
        }
    case 9:
        {
            x = 2;
            y = 2;
            break;
        }
    }
}

//PROMJENI POLJE
void board::make_move(int x, int y, TURN turn)
{
    if (turn == Player_X)
    {
        board[y][x] = X;
    }
    else if (turn == Player_O)
    {
        board[y][x] = O;
    }
}

bool board::check_win()
{
    for (int i=0;i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            //HORIZONTAL CHECK
            if (j+2 < size && board[i][j] != EMPTY && board[i][j] == board[i][j+1] && board[i][j] == board[i][j+2])
            {
                return true;
            }
            //VERTICAL CHECK
            else if (i+2 < size && board[i][j] != EMPTY && board[i][j] == board[i+1][j] && board[i][j] == board[i+2][j])
            {
                return true;
            }
            //DIAGONAL LEFT
            else if (j-2 >= 0 && i+2 < size && board[i][j] != EMPTY && board[i][j] == board[i+1][j-1] && board[i][j] == board[i+2][j-2])
            {
                return true;
            }
            //DIAGONAL RIGHT
            else if (j+2 < size && i+2 < size && board[i][j] != EMPTY && board[i][j] == board[i+1][j+1] && board[i][j] == board[i+2][j+2])
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    board a;

    //INITIALIZATION
    TURN turn;
    int input;
    int x,y;

    //MAIN GAME LOOP
    while (1)
    {
        a.draw();
        turn = a.get_turn();
        input = a.get_move(turn);
        a.get_cordinates(input, x, y);
        a.make_move(x,y,turn);

        if (a.check_win())
        {
            a.draw();
            break;
        }
    }
    cout << "Player " << turn << " wins!";
    return 0;
}
