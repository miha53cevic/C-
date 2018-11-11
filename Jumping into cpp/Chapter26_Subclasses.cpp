#include <iostream>
#include <vector>
using namespace std;

//PARENT CLASS
class drawing
{
public:

    virtual void draw() = 0;
};

class Ship:public drawing
{
public:

    virtual void draw();
};

void Ship::draw()
{
    //CODE TO DRAW SHIP
    cout << "hello";
}

int main()
{

//store the Ship in the vector by creating a new ship pointer

    vector<drawing*>list_of_objects;
    list_of_objects.push_back(new Ship());

    for (vector<drawing*>::iterator itr = list_of_objects.begin(), end = list_of_objects.end();itr!=end;++itr)
    {
        (*itr)->draw();
    }

}
