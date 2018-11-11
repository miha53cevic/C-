#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <conio.h>
#include <windows.h>
using namespace std;
//Mihael Petricevic 2018 (Broken Leg Boyo)
//OBJECT ORIANTED PROGRAMMING OOP

enum objects {EMPTY, WALL, SNAKE_HEAD, SNAKE_TAIL, FRUIT};
objects** Map;

//KONSTANTE
const int m_x = 40;
const int m_y = 10;

class GameObject
{
public:

    //INHERITED BY CHILD CLASSES
    virtual void update() = 0;
};

class Snake : public GameObject
{
public:

   void update();

private:
    int _x = 19;
    int _y = 4;
    int _x_old, _y_old;
    int _direction = 3;
    int _tsize = 0;

    //PRIVATE STRUCT
    struct Tail
    {
        int x;
        int y;
    };
    //ARRAY OR TAILS
    vector<Tail>tails;

    //HELPER METHODS
    void _KeyBoard();
    void _MoveSnake();
    void _AddTail();
    bool _Ate();
    void _MoveTail();
    void _Collision();
};

/*

    UZIMA INPUT OD IGRACA I MJENJA SMJER ZMIJE

*/

void Snake::_KeyBoard()
{
    /*
        1                up
    2       3     left        right
        4               down
    */

    if (kbhit())
    {
        char input = getch();

        if (input == 'w')
        {
            _direction = 1;
        }
        else if (input == 'a')
        {
            _direction = 2;
        }
        else if (input == 'd')
        {
            _direction = 3;
        }
        else if (input == 's')
        {
            _direction = 4;
        }
    }
}

/*
*/

void Snake::_MoveSnake()
{
    //SPREMA ZADNJE KORDINATE PRIJE PROMJENE ZA PRVI REP
    _x_old = _x;
    _y_old = _y;

    switch(_direction)
    {
    case 1:
        {
            _y--;
            break;
        }
    case 2:
        {
            _x--;
            break;
        }
    case 3:
        {
            _x++;
            break;
        }
    case 4:
        {
            _y++;
            break;
        }
    }

    //STAVLJA MJESTO GLAVE ZMIJE U IGRACE POLJE
    Map[_y_old][_x_old] = EMPTY;
    Map[_y][_x] = SNAKE_HEAD;
}

/*

    FUNKCIJA DODAVA NOVI REP
    - NA POCETKU DODAVA 2 REPA JER TOLIKO IMA ZMIJA POCETNO
    - KASNIJE AKO JE POJELA VOCE SE DODAVA JOS JEDAN IZA ZADNJEG BAZIRAN O DIREKCIJU U KOJOJ SE MICE ZMIJA

*/

void Snake::_AddTail()
{
    //NA POCETKU IGRE ZMIJA IMA 2 REPA
    if (_tsize == 0)
    {
        for (int i=0;i<2;i++)
        {
            tails.push_back(Tail());
            tails[i].x = 19 - i;    //OVO SAMO STAVLJA REPA 1 IZA GLAVE PA ONDA 2 IZA GLAVE (NIJE 18 JER SE POMAKNE ZA 1 ODMA CIM SE STVORI OBJEKT SNAKE)
            tails[i].y = 4;

            //STAVLJANJE REPA U IGRACE POLJE
            Map[tails[i].y][tails[i].x] = SNAKE_TAIL;
            //POVECANJE BROJA REPA KOJI JE NA POCETKU 0
            _tsize++;
        }
    }

    if (_Ate())
    {
        //DODAVA NOVI REP
        tails.push_back(Tail());

        //ODREDIVANJA KORDINATA NOVOG REPA
        switch(_direction)
        {
        case 1:
            {
                tails[_tsize].x = tails[_tsize - 1].x;
                tails[_tsize].y = tails[_tsize - 1].y - 1;
                break;
            }
        case 2:
            {
                tails[_tsize].x = tails[_tsize - 1].x + 1;
                tails[_tsize].y = tails[_tsize - 1].y;
                break;
            }
        case 3:
            {
                tails[_tsize].x = tails[_tsize - 1].x - 1;
                tails[_tsize].y = tails[_tsize - 1].y;
                break;
            }
        case 4:
            {
                tails[_tsize].x = tails[_tsize - 1].x;
                tails[_tsize].y = tails[_tsize - 1].y + 1;
                break;
            }
        }
        //POVECAVA SE KOLIKI JE BROJ REPA
        _tsize++;
    }
}

/*

    GLEDA AKO JE ZMIJA POJELA VOCE

*/

bool Snake::_Ate()
{
    //AKO  ZMIJA IDE U SMJERU VOCA I AKO JE VOCE JEDNO POLJE ISPRED ONDA ZNACI DA GA JE IGRAC POJEO
    if (_direction == 1 && Map[_y - 1][_x] == FRUIT)
    {
        return true;
    }
    else if (_direction == 2 && Map[_y][_x - 1] == FRUIT)
    {
        return true;
    }
    else if (_direction == 3 && Map[_y][_x + 1] == FRUIT)
    {
        return true;
    }
    else if (_direction == 4 && Map[_y + 1][_x] == FRUIT)
    {
        return true;
    }

    return false;
}

/*

    POMICE ZMIJIN REP TAKO DA UZIMA KORDINATE ZADNJEG REPA I PREBACUJE GA NE SLJEDECI

*/

void Snake::_MoveTail()
{
    //ZADNJI REP SE BRISE
    Map[tails[_tsize - 1].y][tails[_tsize - 1].x] = EMPTY;

    //UZIMA KORDINATE ZADNJEG REPA BRISE SVOJE MJESTO I UZIMA KORDINATE SLJEDECOG REPA
    for (int i=_tsize - 1;i!=0;i--)
    {
        tails[i].x = tails[i-1].x;
        tails[i].y = tails[i-1].y;
    }
    //STAVLJAM DA JE PRVI REP SADA NA STAROM MJESTU GLAVE ZMIJE
    tails[0].x = _x_old;
    tails[0].y = _y_old;

    //STAVLJA DA JE PRVI REP NA POZICIJ
    Map[_y_old][_x_old] = SNAKE_TAIL;
}

/*

    PROVJERAVA DA LI JE IGRAC IZGUBIO

*/

void Snake::_Collision()
{
    //JE LI IGRAC UDARIO ZID
    if (_x == 0 || _x == 39)
    {
        cout << "YOU LOST, GET GUD SCRUB!";
        system("pause");
        exit(0);
    }

    if (_direction == 1 && Map[_y - 1][_x] == WALL || _direction == 4 && Map[_y + 1][_x] == WALL)
    {
        cout << "YOU LOST, GET GUD SCRUB!";
        system("pause");
        exit(0);
    }

    //PROVJERA AKO JE IGRAC SE ZALETIO U SVOJ REP
    if (_direction == 1 && Map[_y - 1][_x] == SNAKE_TAIL)
    {
        cout << "YOU LOST, GET GUD SCRUB!";
        system("pause");
        exit(0);
    }
    else if (_direction == 2 && Map[_y][_x - 1] == SNAKE_TAIL)
    {
        cout << "YOU LOST, GET GUD SCRUB!";
        system("pause");
        exit(0);
    }
    else if (_direction == 3 && Map[_y][_x + 1] == SNAKE_TAIL)
    {
        cout << "YOU LOST, GET GUD SCRUB!";
        system("pause");
        exit(0);
    }
    else if (_direction == 4 && Map[_y + 1][_x] == SNAKE_TAIL)
    {
        cout << "YOU LOST, GET GUD SCRUB!";
        system("pause");
        exit(0);
    }
}

/*

    ZOVE SVE HELPER METHODS ZA ZMIJU STVARA LOOP UPDATA SVE PODATKE O ZMIJI I NJEZINOM REPU

*/

void Snake::update()
{
    _KeyBoard();
    _AddTail();
    _Collision();
    _MoveSnake();
    _MoveTail();
}

class Fruit : public GameObject
{
public:

   void update();

private:
    int _x;
    int _y;

    //HELPER METHODS
    void _spawnFruit();
    bool _check_for_fruit();
};

/*

    STVARA VOCE NA RANDOM LOKACIJI NA MAPI

*/

void Fruit::_spawnFruit()
{
    int x,y;
    x = 1 + rand() % 38;
    y = 1 + rand() % 8;

    Map[y][x] = FRUIT;
}

/*

    PROVJERAVA AKO JE KORISNIK POJEL VOCE TJ. AKO IMA VOCA NA MAPI

*/

bool Fruit::_check_for_fruit()
{
    for (int i=1;i<m_y - 1;i++)
    {
        for (int j=1;j<m_x - 1;j++)
        {
            if (Map[i][j] == FRUIT)
            {
                return true;
            }
        }
    }
    return false;
}

/*

    ZOVE SVE HELPER METHODS ZA VOCE I STVARA GA AKO GA NEMA NA IGRACEM POLJU

*/

void Fruit::update()
{
    if (!_check_for_fruit())
    {
        _spawnFruit();
    }
}

/*

    STVARA LISTU KOJA UPDATA SVAKI OBJEKT IGRE

*/

void Scene(vector<GameObject*>&updates)
{
    //AKO NEMA OVOGA SE BUDE SVAKI PUT SPREMILA NOVA INSTANCA OBJEKTA SNAKE I FRUIT TE BUDU IMALI DEFAULT VRIJEDNOST I NEBUDU SE UOPCE MJENJALI
    //GLEDAM AKO JE VEKTOR PRAZAN I AKO JE GA POPUNJAVAM SA NOVIM INSTANCAMA OBJEKTI
    //ISTO KAO DA NAPRAVIM Snake a.update(); I ONDA NAKON OPET STVARAM TAJ OBJEKT PA SE ON RESETIRA PA ZA TO SLUZI IF
    //MOGLO SE SAMO I NAPISATI TU Snake a.update(); ISTO BI DOSLO ALI MORA BITI OVAJ IF
    if (updates.size() == 0)
    {
        //SPREAMNJE SUBKLASI U VEKTOR TAKO DA SLAZEMO NOVI POINTER PREMA TOJ SUBKLASI
        updates.push_back(new Snake());
        updates.push_back(new Fruit());
    }

    //ZOVE SE UPDATE SVAKE SUBKLASSE
    for (vector<GameObject*>::iterator itr = updates.begin(), end = updates.end();itr != end; itr++)
    {
        (*itr)->update();
    }


}

/*

    CRTA IGRACE POLJE I OBJEKTE IGRE

*/

void draw()
{
    //REFRESH SCREEN
    COORD cur = {0,0};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);

    //CRATNJE IGRACEG POLJA
    for (int i=0;i<m_y;i++)
    {
        for (int j=0;j<m_x;j++)
        {
            if (Map[i][j] == WALL)
            {
                cout << "*";
            }
            else if (Map[i][j] == EMPTY)
            {
                cout << " ";
            }
            else if (Map[i][j] == SNAKE_HEAD)
            {
                cout << "O";
            }
            else if (Map[i][j] == SNAKE_TAIL)
            {
                cout << "o";
            }
            else if (Map[i][j] == FRUIT)
            {
                cout << "+";
            }
        }
        cout << endl;
    }
}

/*

    FUNKCIJA MAIN()

*/

int main()
{
    //srand(time(0));

    //KREACIJA MAPE
    Map = new objects*[m_y];
    for (int i=0;i<m_y;i++)
    {
        Map[i] = new objects[m_x];
    }

    //ISPUNJAVANJE MAPE
    for (int i=0;i<m_y;i++)
    {
        for (int j=0;j<m_x;j++)
        {
            if (i == 0 || i == m_y-1 || j == 0 || j == m_x-1)
            {
                Map[i][j] = WALL;
            }
            else
            {
                Map[i][j] = EMPTY;
            }
        }
    }

    //KREIRANJE LISTE KOJA UPDATA SVE OBJEKTE CLASSE GAMEOBJECT
    vector<GameObject*>updates;

    //MAIN GAME LOOP
    while (1)
    {
        draw();
        Scene(updates);
        Sleep(200);
    }


    return 0;
}
