#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

//GLOBAL VARIABLES
enum direction {LEFT, RIGHT};;

class platform
{
public:

    //CONSTRUCTORS
    platform();

    //METHODS
    void draw();
    void platform_move();
    bool enter();
    bool check();

    //PUBLIC VARIABLES
    bool won;

private:

    //PRIVATE VARIABLES
    int _size;
    int _platform_x;
    int **_map;
    int _x_map, _y_map;
    int _speed;
    int _pressed;
    direction _LR;

    //HELPER METHODS
    void _platform_draw();
    bool _wall_hit();
};

/*

    CONSTRUCTOR PLATFORM KADA SE ZOVE NPR. platform a; AUTOMATSKI STAVLJA DA SU OVE VRIJEDNOSTI TOCNE
    ISTO KAO KADA NPR RADIMO INT, INT AUTOMATSKI SE SLAZE DA MOZE UZIMATI BROJEVE

    - U FUNKCIJI STAVLJAM DEFAULT ARGUMENTE KAO NPR. DA JE POCETNA PLATFORMA VELICINE 5
    - STVARAM 2D ARRAY I TIME IGRACE POLJE

*/

platform::platform()
{
    _size = 5;
    _platform_x = 13;
    _x_map = 15;
    _y_map = 5;
    _speed = 250;
    _pressed = 0;
    _LR = LEFT;

    won = false;

    //2D Array Construction & Initalization
    _map = new int*[_y_map];
    for (int i=0;i<_y_map;i++)
    {
        _map[i] = new int[_x_map];
    }

    //Filling 2D Array
    for (int i=0;i<_y_map;i++)
    {
        for (int j=0;j<_x_map;j++)
        {
            if (j == 0 || j == 14)
            {
                _map[i][j] = 1;
            }
            else
            {
                _map[i][j] = 0;
            }
        }
    }

}

/*

    CRTA IGRACE POLJE I UPDATA LOKACIJU PLATFORMI

*/

void platform::draw()
{
    Sleep(_speed);
    //REFRESH SCREEN
    COORD cur = {0,0};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);

	_platform_draw();

    for (int i=0;i<_y_map;i++)
    {
        for (int j=0;j<_x_map;j++)
        {
            if (_map[i][j] == 0)
            {
                cout << " ";
            }
            else if (_map[i][j] == 1)
            {
                cout << "|";
            }
            else if (_map[i][j] == 2)
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}

/*

    STVARA PLATFORMU PREMA SIZE
    - OVISNO O VELICINI (SIZE) GLAVNI DIO PLATFORME DOBIVA ODREDEN BROJ DODATAKA

*/

void platform::_platform_draw()
{
        if(_LR == RIGHT)
        {
            for (int i=0;i<_size;i++)
            {
                _map[_size - 1][_platform_x + i] = 2;
            }
        }
        else if(_LR == LEFT)
        {
            for (int j=0;j<_size;j++)
            {
                _map[_size - 1][_platform_x - j] = 2;
            }
        }
}

/*

    POMICE PLATFORMU LIJEVO I DESNO NA EKRANU
    - PRVO SE BRISE ZADNJA POZICIJA GLAVNOG DIJELA PLATFORME TE SE GLEDA DA LI SE PLATFORMA MICE LIJEVO ILI DESNO I POMICE GLAVNI DIO
      ZA 1 ILI LIJEVO ILI DESNO TE ILI LIJEVO ILI DESNO OD NJEGA ISPISUJE OSTALE DIJELOVE PLATFORME
    - POMOCU WALL_HIT FUNKCIJA PROVJERAVA AKO JE PLATFORMA DOSLA DO ZIDA I AKO JEST
      STAVLJA DA MORA ICI U DRUGI SMJER I STAVLJA POZICIJU GLAVNOG DIJELA PLATFORME NA KRANJU TOCKU TAKO DA BI ONDA MOGA SE POMAKNUTI ZA 1
      I ISPISIVATI OSTALE DIJELOVE ISPRED ILI IZA SEBE

      NPR. |*****<--- GLAVNI DIO PLATFORME
      NAKON STO JE DOSAO DO KRAJA KAO SADA MJENJAJ SMJER U OVOM SLUCAJU IZ LIJEVO U DESNO
      | * <-- GLAVNI DIO PLATFORME  OSTALI DIJELOVI: ****
      MJENJA SE GDJE JE GLAVNI DIO PLATFORME I SADA SE SAMO IZBRISE MJESTO TOG GLAVNOG DIJELA
      | ****
      TE SE ZATIM DODA +1 U OVOM SLUCAJU ZA GLAVNI DIO PLATFORME (_platform_x)
      TE SE NAKON TOGA MU DODA U OVOM SLUCAJU 3 DODATNA DIJELA PLATFORME ZNACI
      | ***** <-- NOVI DIO SADA NACRTAN I TAKO ISTO ZA DRUGU STRANU

*/

void platform::platform_move()
{
    _map[_size - 1][_platform_x] = 0;

    if (_LR == RIGHT)
    {
        _platform_x += 1;
    }
    else if (_LR == LEFT)
    {
        _platform_x -= 1;
    }

    if (_wall_hit())
    {
        if (_LR == RIGHT)
        {
            _platform_x += _size - 1;
            _LR = LEFT;
        }
        else if (_LR == LEFT)
        {
            _platform_x -= _size - 1;
            _LR = RIGHT;
        }
    }
}

/*

    GLEDA AKO JE PLATFORMA UDARILA ZIDA I DA VRACA DA ILI NE
    - TOCNIJE GLEDA AKO JE NAKON *****| I AKO JE VRACA TRUE AKO NIJE VRACA FALSE

*/

bool platform::_wall_hit()
{
    if (_LR == RIGHT && _map[_size - 1][_platform_x + _size] == 1 || _LR == LEFT && _map[_size - 1][_platform_x - _size] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*

    CHECKS KEYBOARD INPUT
    - GETCH() OCISTI BUFFER JER BUDE INACE MISLIL DA JE STALNO KLIKNUT ENTER

*/

bool platform::enter()
{
    if (kbhit())
    {
        //CLEAR BUFFER
        getch();

        if (_size >= 0)
        {
            _size -= 1;
            _speed -= 50;
            _pressed++;

            //STVARA NOVU PLATFORMU NA DESNOJ STRANI SVAKI PUT AKO SE MAKNE OVAJ DIO STVARA TOCNO IZNAD ZADNJE POSTAVLJENE
            _platform_x = 13;
            _LR = LEFT;
        }
        return true;
    }
    return false;
}

/*

    GLEDA AKO JE IGRAC USPIO SASTAVITI ZGRADU OD ZVIJEZDA I AKO JEST VRACA TRUE A AKO NIJE VRACA FALSE

*/

bool platform::check()
{
    int counter=0;

    for (int i=0;i<_x_map;i++)
    {
        for (int j=4;j>=0;j--)
        {
            if (_map[j][i] == 2)
            {
                counter++;

                if (counter == _pressed)
                {
                    //AKO JE PRESSED = 5 I IGRA NIJE ZAVRSILA STAVI DA JE IGRAC POBIJEDIO
                    if (_pressed == 5)
                    {
                        won = true;
                    }
                    return true;
                }
            }
            else
            {
                counter = 0;
            }
        }
    }
    return false;
}

/*

    FUNKCIJA MAIN()
    - KORISTI PUBLIC FUNKCIJE KLASSE PLATFORM

*/

int main()
{
    platform a;
    //INITIAL DRAW (NE TREBA ALI AKO SE MAKNE BUDE SE ODMAH GLAVNI DIO UNISTIL PA BUDE IH SAMO 4 DO NOVOG DRAWA, NIJE PREVISE BITNO ALI ONO XD)
    a.draw();

    while(1)
    {
        a.platform_move();
        a.draw();
        if (a.enter())
        {
            if (!a.check())
            {
                cout << "\n\nYou lost!\n";
                break;
            }
        }

        if (a.won == true)
        {
            cout << "\n\nYou win!\n";
            break;
        }
    }
    system("pause");
    return 0;
}
