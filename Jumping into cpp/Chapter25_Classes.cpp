#include <iostream>
using namespace std;
//KADA KORISTITI PRIVATE A KADA PUBLIC, PRIVATE SU METHODS KOJE SU HELPER METHODS, FUNKCIJE KOJE ZOVU U PUBLIC METHODS-ima ALI IH KORISNIK NE MORA VIDJETI
//https://stackoverflow.com/questions/4505938/when-why-to-make-function-private-in-class

class vectorOfint
{
public:

    //CONSTRUCTORS
    vectorOfint();
    vectorOfint(int x);

    //METHODS
    int get(int x);
    void set(int index, int value);
    void pushBack(int x);
    void list_arr();


private:
    //PRIVATE VARIABLES
    int *_arr;
    int _size;
    int _filled;
    //PRIVATE METHODS
    void _get_new_array();

};

vectorOfint::vectorOfint()

    //DEFAULT VALUES
    : _size (32)
    , _arr (new int[_size])
    , _filled (0)

{

}

vectorOfint::vectorOfint(int x)

    : _arr (new int[x])
    , _size (x)
    , _filled (0)
{

}

int vectorOfint::get(int x)
{
    return _arr[x];
}

void vectorOfint::set(int index, int value)
{
    _arr[index] = value;
}

void vectorOfint::pushBack(int x)
{
    if (_filled == _size - 1)
    {
        _get_new_array();
    }

    _arr[_filled] = x;
    _filled += 1;
}

void vectorOfint::_get_new_array()
{
    int *new_array = new int[_size + 1];

    for (int i=0;i<_size;i++)
    {
        new_array[i] = _arr[i];
    }
    _arr = new_array;
    _size += 1;
    //CLEAR ARRAY AFTER COPY
    delete new_array;
}

void vectorOfint::list_arr()
{
    for (int i=0;i<_size;i++)
    {
        cout << "<" << i << "> " << _arr[i] << endl;
    }
}

int main()
{
    vectorOfint a(1);
    int b;

    while(1)
    {
        cin >> b;
        a.pushBack(b);

        if (b == -1)
        {
            break;
        }
    }
    a.list_arr();
}
