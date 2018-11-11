#include <iostream>
using namespace std;

void multiplication_table(int height, int width)
{
    //POINTER TO POINTER DEKLARACIJA
    int **p_p_array;
    //STAVLJANJE DA POINTER TO POINTER KAZE NA ARRAY OD POINTER-a KOJA JE VISINA ARRAY-a , NPR. array[HEIGHT][]
    p_p_array = new int*[height];

    for (int i=0;i<height;i++)
    {
        //STVARA POINTER-e NA KOJE POKAZUJU POINTERI U HEIGHT, ZAPRAVO STVARA KOLIKO JE SVAKI OD TIH DUG(WIDTH), NPR. array[height][width]
        p_p_array[i] = new int[width];
    }

    for (int i=0;i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
            //ISPISUJE POINTER TO POINTER ARRAY I STVARA TABLICU MNOZENJA
            p_p_array[i][j] = (i+1)*(j+1);
            cout << "[" << i+1 << "]" << "[" << j+1 << "]" << " = " << p_p_array[i][j] << endl;
        }
    }

    //DELETE ARRAY TO CLEAR MEMORY - OSLOBADA SE OBRNUTO OD INICIJALIZACIJE PRVO WIDTH PA HEIGHT
    for (int i=0;i<width;i++)
    {
        delete [] p_p_array[i];
    }
    //BRISE HEIGHT
    delete [] p_p_array;
}

int main()
{
    int height,width;
    cout << "Enter height: ";
    cin >> height;
    cout << "Enter width: ";
    cin >> width;

    //FUNKCIJA
    multiplication_table(height,width);
}
