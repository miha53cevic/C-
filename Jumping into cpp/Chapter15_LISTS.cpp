#include <iostream>
#include <cstdlib>
using namespace std;

//pointer->x JE ISTO KAO DA JE (*pointer).x

struct SpaceShip
{
    int x;
    int y;
    //POINTER KOJI SlUZI ZA LISTU
    SpaceShip* nextShip;
};

SpaceShip* getShip(SpaceShip *p_list)
{
    SpaceShip *newShip = new SpaceShip; //TREBA STAVITI JER INACE POINTER NIKAMO NE KAZE
    newShip->x = rand() % 1024;
    newShip->y = rand() % 768;
    //POINTER SPREMA ZADNJI BROD U NEXT SHIP I STAVLJA NOVI U p_list
    newShip->nextShip = p_list;

    return newShip;
}

int main()
{
    SpaceShip *p_list = NULL;

    for (int i=0;i<3;i++)
    {
        //P_LIST POINTA NA ZADNJI NAPRAVLJEN BROD A ZADNJI NAPRAVLJEN BROD POINTA POMOCU nextShip NA BROD PRIJE NJEGA ITD...
        p_list = getShip(p_list);
        cout << p_list->x << endl << p_list->y << endl;
    }
}
