#include <iostream>
using namespace std;

void adress(int height,int width)
{
    //POINTER TO POINTER
    int **p_p_array;
    //HEIGHT OF ARRAY, array[height][]
    p_p_array = new int*[height];

    for (int i=0;i<height;i++)
    {
        //WIDTH OF ARRAY, array[][width]
        p_p_array[i] = new int[width];
    }

    //HOLDS MEMORY ADRESS OF ELEMENT
    int *memory = NULL;

    for (int i=0;i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
            memory = & p_p_array[i][j];
            cout << memory << endl;
        }
    }
    //CLEARING MEMORY
    for (int i=0;i<width;i++)
    {
        delete [] p_p_array[i];
    }
    delete [] p_p_array;
}

int main()
{
    int height,width;
    cout << "Enter height,width\n";
    cin >> height;
    cin >> width;

    adress(height,width);
}
