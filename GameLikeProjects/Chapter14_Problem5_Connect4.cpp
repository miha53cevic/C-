#include <iostream>
#include <cstdlib>
using namespace std;

char** board(int height, int width)
{
    //POINTER TO POINTER SLUZI ZA STVARANJE 2D ARRAY-a
    char **board = new char*[height];

    //DRUGI DIO ARRAY-a, array[height][width]
    for (int i=0;i<height;i++)
    {
        board[i] = new char[width];
    }

    //POPUNJAVANJE ARRAY-a SA PRAZNIM POLJIMA
    for (int i=0;i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
            board[i][j] = '-';
        }
    }
    //VRACANJE ARRAY-a TAKO DA BI U MAIN() BIO TAJ ARRAY ZA DALJNJE SLANJE KROZ FUNKCIJE
    return board;
}

void draw(char** board, int height, int width)
{
    system("cls");

    //ISPISUJE ARRAY KAO POLJE
    for (int i=0;i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
    //DODAJE BROJEVE NA DNO DA SE LAKSE VIDI KOJE JE TO POLJE
    for (int i=1;i<width+1;i++)
    {
        cout << i;
    }
    cout << endl << endl;
}

void add(int spot, char** board, int height, char& turn)
{
    //RAZLOG JER JE ARRAY I POCINJE OD 0
    height = height - 1;
    spot = spot - 1;

    //AKO JE POLJE SLOBODNO POPUNI GA S IGRACEVOM FIGUROM/ZNAKOM
    if (board[height][spot] == '-')
    {
        board[height][spot] = turn;
    }
    //AKO NIJE TRAZI SLOBODNO MJESTO IZNAD TOG POLJA I TAKO DUGO DOK SVA POLJA NISU PRODENA IZNAD TOG POPUNJENOG
    else
    {
        while (board[height][spot] != '-' && height != 0)
        {
            //U TO ISTO VRIJEME SMANJUJ HEIGHT ZNACI POLJA IZNAD SE GLEDAJU DALJE ARR[height][width]
            height--;
        }
        //NA KRAJU AKO JE PRONADENO POLJE UPISI UNUTAR NJEGA IGRACEVU FIGURU/ZNAK
        board[height][spot] = turn;
    }
}

int check_win(char **p_board, int height, int width, char& turn)
{
    //HORIZONTAL
    for (int i=0;i<height;i++)
    {
        for (int j=0;j<width;j++)

            //BITNO JE STAVITI DA AKO JE U OVOM SLUCAJU J+3 < width JER INACE BUDE TRAZIL MJESTA U ARRAYU KOJA NE POSTOJE I CRASHAL PROGRAMA
            if (j+3 < width && p_board[i][j] == turn && p_board[i][j] == p_board[i][j+1] && p_board[i][j] == p_board[i][j+2] && p_board[i][j] == p_board[i][j+3])
            {
                switch (turn)
                {
                    case '+':
                    {
                        return 0;
                    }
                    case 'x':
                    {
                        return 1;
                    }
                }
            }
        }
    //VERTICAL WIN
    for (int i=0;i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
            if (i+3 < height && p_board[i][j] == turn && p_board[i][j] == p_board[i+1][j] && p_board[i][j] == p_board[i+2][j] && p_board[i][j] == p_board[i+3][j])
            {
                switch (turn)
                {
                    case '+':
                    {
                        return 0;
                    }
                    case 'x':
                    {
                        return 1;
                    }
                }
            }
        }
    }
    //DIAGONAL RIGHT
    for (int i=0;i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
            if (i+3 < height && j+3 < width && p_board[i][j] == turn && p_board[i][j] == p_board[i+1][j+1] && p_board[i][j] == p_board[i+2][j+2] && p_board[i][j] == p_board[i+3][j+3])
            {
                switch (turn)
                {
                    case '+':
                    {
                        return 0;
                    }
                    case 'x':
                    {
                        return 1;
                    }
                }
            }
        }
    }
    //DIAGONAL LEFT
    for (int i=0;i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
            if (i+3 < height && j-3 >= 0 && p_board[i][j] == turn && p_board[i][j] == p_board[i+1][j-1] && p_board[i][j] == p_board[i+2][-2] && p_board[i][j] == p_board[i+3][j-3])
            {
                switch (turn)
                {
                    case '+':
                    {
                        return 0;
                    }
                    case 'x':
                    {
                        return 1;
                    }
                }
            }
        }
    }

    //PROMJENI IGRACA
    if (turn == '+')
    {
        turn = 'x';
    }
    else
    {
        turn = '+';
    }

    //VRACAJ -1 ZNACI IGRA DALJE TRAJE
    return -1;
}

int main()
{
    //VELICINA IGRE
    int height,width;
    cout << "Enter height of board (najbolje radi s brojevima do 9) = ";
    cin >> height;
    cout << "Enter width of board (najbolje radi s brojevima do 9) = ";
    cin >> width;

    //POINTER TO POINTER - KORISTEN KASNIJE KAO 2D ARRAY arr[y][x]
    char **p_board;
    char turn = 'x';
    int input;
    int game_over=-1;

    //STVARNAJE 2D Array-acase 0:
            {
                cout << "\n\nPlayer + wins!";
            }
    p_board = board(height,width);
    //CRTANJE IGRACEG POLJA
    draw(p_board,height,width);


    while (game_over == -1)
    {
        cout << "Player " << turn << ":";
        cin >> input;

        //DODAVANJE FIGURE NA MJESTO KOJE JE IGRAC IZABRAO
        add(input, p_board, height, turn);
        //CHECKS WHO WON
        game_over = check_win(p_board, height, width, turn);
        //CRTA IGRACE POLJE
        draw(p_board,height,width);

        //WHO WON
        switch (game_over)
        {
        case 0:
            {
                cout << "\n\nPlayer + wins!";
            }
        case 1:
            {
                cout << "\n\nPlayer x wins!";
            }
        }
    }
}
