#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

//VELICINA EKRANA
const int height = 25;
const int width = 50;
//KOLICINA BRODOVA NA MAPI
const int size = 5;

//KORISTENI POSLIJE DA BI SE ZNALO DA LI CE BROD IZACI IZ EKRANA
bool x_up;
bool x_down;
bool y_up;
bool y_down;

//STRUKTURA SADRZI INFORMACIJE O BRODOVIMA - x,y,alive
struct SpaceShip
{
    int x;
    int y;
    int alive;
};

//STVARA 2D Array ISTO KAO I Array[][], ALI NAPRAVLJENO S POINTERIMA
char** get_array()
{
    //POINTER TO POINTER TO CHAR ARRAY
    char **p_array = new char*[height]; //POINTER KOJI POKAZUJE NA SET POINTERA KOJI ZATIM POKAZUJU NA SET CHAR VARIJABLI I TAKO SE DOBIJE 2D ARRAY

    for (int i=0;i<height;i++)
    {
        p_array[i] = new char[width]; //SET CHAR-a NA KOJE POKAZUJU POINTERI
    }
    //POPUNJAVANJE ARRAY-a SA PRAZNIM MJESTIMA
    for (int i=0;i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
            p_array[i][j] = '-';
        }
    }
    //VRACANJE NOVO STVORENOG 2D ARRAY-a
    return p_array;
}

//DAJE POCETNE KORDINATE BRODOVIMA
SpaceShip get_ship(char** map) //char** map = char map[][] ---> POINTER TO POINTER 2D ARRAY
{
    //STVARANJE BRODA KOJI DOBIVA KORDINATE I SALJE SE NATRAG U ARRAY BRODOVA U MAIN()
    SpaceShip ship;
    ship.x = 0 + rand() % width;
    ship.y = 0 + rand() % height;
    //STAVLJANJE DA JE BROD ZIV I NIJE IZVAN EKRANA
    ship.alive = 1;

    //UPISIVANJE BRODA U POLJE
    map[ship.y][ship.x] = '*';
    //VRACANJE BRODA U ARRAY BRODOVA U MAIN()
    return ship;
}

//MJENA POZICIJE BRODOVA - UZIMA 2D ARRAY, I ARRAY BRODOVA OD MAIN()
SpaceShip moveShip(SpaceShip ship, char** map)
{
    //STAVLJA STARU POZICIJU BRODA DA JE PRAZNO MJESTO
    map[ship.y][ship.x] = '-';
    //RANDOM KOJI ODLUCUJE U KOJU CE STRANU BROD ICI
    int direction = 1 + rand() % 4;

    //MJENA POZICIJU BRODA I STAVLJA DA SE POMAKNUL GORE/DOLJE/LIJEVO/DESNO U BOOL VARIJABLMA POMOCU CEGA SE POSLIJE MOZE VIDJETI DA LI JE BROD IZVAN ARRAY-a & EKRANA
    switch(direction)
    {
    case 1:
        {
            x_up = true;
            ship.x++;
            break;
        }
    case 2:
        {
            x_down = true;
            ship.x--;
            break;
        }
    case 3:
        {
            y_up = true;
            ship.y++;
            break;
        }
    case 4:
        {
            y_down = true;
            ship.y--;
            break;
        }
    }
    //VRACA BROD S NOVIM KORDINATAM U ARRAY OD BRODOVA U MAIN()
    return ship;
}

//GLEDA DA LI JE BROD IZVAN EKRANA/ARRAY-a I STAVLJA DA LI JE ZIV I BRISE MU POZICIJU
void isAlive(SpaceShip *ship, char **map) //SpaceShip *ship = SpaceShip ship[size]; ---> ARRAY BRODOVA IZ MAIN()
{
    for (int i=0;i<size;i++)
    {
        //AKO JE BROD NA KRAJU ARRAY-a I MORA ZELI NASTAVITI ZNACI DA JE IZVAN EKRANA I BRISE SE, SLUZE PRIJE NAVEDENE BOOL VARIJABLE
        if (ship[i].x == 49 && x_up == true || ship[i].x == 0 && x_down == true)
        {
            ship[i].alive = 0;
            //BRISE POZICIJU JER JE MRTAV
            map[ship[i].y][ship[i].x] = '-';
        }
        if (ship[i].y == 24 && y_up == true || ship[i].y == 0 && y_down == true)
        {
            ship[i].alive = 0;
            //BRISE POZICIJU JER JE MRTAV
            map[ship[i].y][ship[i].x] = '-';
        }
    }
    //VRACA BOOL VARIJABLE ZA POMAKNUTO NATRAG NA DEFAULT = FALSE;
    x_up = false;
    x_down = false;
    y_up = false;
    y_down = false;
}

//CRTA IGRACE POLJE
void draw(char** map)
{
    COORD cur = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);

    for (int i=0;i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
}

int main()
{
    //UZIMA 2D ARRAY POMOCU POINTER TO POINTER
    char **map = get_array();
    //ARRAY BRODOVA KAO POINTER -----> ISTO KAO DA NAPRAVIS SpaceShip ship[size]; === OVO JE SAMO VERZIJA S POINTERIMA
    SpaceShip *ship = new SpaceShip[size];

    for (int i=0;i<size;i++)
    {
        //UZIMA POCETNE KORDINATE ZA BRODOVE I VRACA IH U ARRAY BRODOVA U MAIN()
        ship[i] = get_ship(map);
    }

    //SVE DOK JE JEDAN BROD ZIV NASTAVI SIMULACIJU
    while (ship[0].alive == 1 || ship[1].alive == 1 || ship[2].alive == 1 || ship[3].alive == 1 || ship[4].alive == 1)
    {
        //USPORAVA KOD
        Sleep(1000);

        for (int i=0;i<size;i++)
        {
            //AKO JE BROD ZIV NASTAVI AKO NIJE PRESKOCI
            if (ship[i].alive == 1)
            {
                //MJENJAJ KORDINATE BRODA I VRACAJ U MAIN() U ARRAY BRODOVA
                ship[i] = moveShip(ship[i], map);
                //GLEDAJ AKO JE BROD ZIV
                isAlive(ship,map);
                //STAVI ZVJEZDU NA NOVU POZICIJU BRODA AKO JE ZIV
                if (ship[i].alive == 1)
                {
                    map[ship[i].y][ship[i].x] = '*';
                }
            }
            //CRTAJ POLJE
            draw(map);
        }
    }
}
