#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

void draw(int array[],int size);
void sort(int array[],int size);
void minimum(int array[],int size,int num1);
void swap(int array[],int num1,int num2);

void sort(int array[],int size)
{
    for (int i=0;i<size;i++)
    {
        minimum(array,size,i);
    }
    cout << "Maximum: " << array[49];
    cout << "\nMinimum: " << array[0];

    int sum = 0;

    for (int j=0;j<size;j++)
    {
        sum += array[j];
    }

    cout << "\nAverage: " << sum/50;
    cout << endl;

    draw(array,size);

}

void minimum(int array[],int size,int num1)
{
    for (int j=num1+1;j<size;j++)
    {
        int num2 = j;

        if (array[num1] > array[num2])
        {
            swap(array,num1,num2);
            j = num1+1;
        }
    }
}

void swap(int array[],int num1,int num2)
{
    int temp = array[num1];
    array[num1] = array[num2];
    array[num2] = temp;
}

void draw(int array[],int size)
{
    cout << "{";

    for (int i=0;i<size;i++)
    {
        cout << array[i];
        if (i != 49)
        {
            cout << ", ";
        }
    }
    cout << "}";
}

int main()
{
    srand(time(NULL));
    int size=50;
    int array[size];

    for(int i=0;i<size;i++)
    {
        array[i] = 1 + rand() % 100;
    }
    sort(array,size);

    return 0;
}
