#include <iostream>
using namespace std;

void fill(int *array)
{
    array[0] = 14;
}

int main()
{
    int num = 2;
    int *p = NULL;

    //cout << *p << endl; //CRASH

    cout << p << endl; //AKO NIJE STAVLJEN NULL IMA VRIJEDNOST U MEMORIJI

    p = & num;
    cout << p << endl; //COUTS ADRESS OD NUM
    cout << *p << endl; //ISPISUJE VRIJEDNOST OD NUM

    int* k = & num; //ISTO KAO DA JE INT *k
    cout << k << endl;

    int x;
    int *p_x = & x;

    //Set new value to that address
    *p_x = 4; // initialize x to 2 - TRAZI GDJE POINTER KAZE I DAJ MU VRIJEDNOST 2, U OVOM SLUCAJU JE TO 2

    //A pointer stores an address, so when you use the bare pointer, you get that address back. You have to add something extra, the asterisk, in order to retrieve or modify the value stored at the address.

    //A variable stores a value, so when you use the variable, you get its value. You have to add some extra, the ampersand, in order to retrieve the address of that variable.

    cout << x << endl;

    //REFERENCE EXAMPLE
    int &yeet = num;
    cout << yeet << endl; //PRINTS NUM, IN THIS CASE 2

    //POINTERS AND ARRAYS
    int arr[8];
    int *p_arr = arr; //ASSIGN POINTER TO ARRAY ARR

    for (int i=0;i<8;++i)
    {
        p_arr[i] = i;
        cout << p_arr[i]; //YOU CAN USE P_ARR INSTEAD OF ARR
    }
    cout << endl << endl;

    //ASSIGNING AN ARRAY WITH NEW AND POINTER
    int *p_numbers = new int[8]; //p_number requests a chuck of memory that can hold an int array of 8 and can be used as an array

    for (int i=0;i<8;++i) //ZBOG NEKOG RAZLOGA ARRAY MOZE IMATI I VISE BEZ DA CRASHA ALI JE OVISNO O VRIJEDNOSTI ISTA STVAR KOD TEMPLATA INFINITE ARRAY
    {
        p_numbers[i] = i+1;
        cout << p_numbers[i];
    }
    cout << endl;
    cout << endl;

    int array[5];
    array[0] = 13;
    fill (array); //SEND ARRAY OVER FUNCTION AND USE IT AS A POINTER IN THE FUNCTION THAT POINTS TO THE ARRAY

    cout << array[0] << endl << endl;

}
