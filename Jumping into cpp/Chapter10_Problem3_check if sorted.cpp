#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//DEKLARACIJE FUNKCIJA
void find_smallest_number(int array[], int size, int num1);
void swap(int array[], int num1, int num2);
void draw_array(int array[], int size);

bool wana_sort = false;

//SORT FUNKCIJA U KOJOJ SE NALAZI BROJ 1 = i S KOJIM ÆE SE USPOREÐIVATI
void sort(int array[], int size)
{
    for (int i=0;i<size;i++)
    {
        find_smallest_number(array,size,i);
    }
    draw_array(array, size);
}

//FUNKCIJA DRAW_ARRAY ISPISUJE BROJEVE ARRAY-a
void draw_array(int array[], int size)
{
    cout << "{";

    for (int i=0;i<size;i++)
    {
        cout << array[i];

        if (i!=9)
        {
            cout << ", ";
        }
    }
    cout << "}";
}

//FIND_SMALLEST_NUMBER FUNKCIJA KOJA NALAZI BROJ 2 = i S KOJIM ÆE SE USPOREÐIVATI TE ZOVE FUNCKIJU SWAP KOJA ZAMNJEJUJE MJESTA AKO JE BROJ 1 VECI OD BROJA 2
void find_smallest_number(int array[], int size, int num1)
{
    for (int j=num1+1;j<size;j++)
    {

        if (array[num1] > array[j])
             {
                 if (wana_sort == true)
                 {
                    int num2 = j;
                    swap(array,num1,num2);
                    j=num1+1;  //NAKON STO SU BROJEVI ZAMJENJENI J SE VRAÆA NA BROJ ISPRED BROJA 1 TAKO DA BI SE VIDLO AKO POSTOJI JOS KOJI NIZI BROJ
                 }
                 else
                 {
                     char input;
                     cout << "Would you like to sort? Y/N : ";
                     cin >> input;

                     if (input == 'y')
                     {
                         wana_sort = true;
                         j=num1+1;
                     }
                     else
                     {

                     }
                 }
             }
    }
}

//FUNKCIJA SWAP ZAMJENJUJE MJESTA BROJA 1 i BROJA 2
void swap(int array[], int num1, int num2)
{
    int temp = array[num1];
    array[num1] = array[num2];
    array[num2] = temp;
}

//FUNKCIJA MAIN
int main()
{
    srand(time(NULL));

    int size = 10;
    int array[size];

    for (int i=0;i<size;i++)
    {
        array[i] = rand() % 100;
    }
    draw_array(array, size);
    cout << "\nSorted:\n";

    sort(array, size);

    return 0;
}
