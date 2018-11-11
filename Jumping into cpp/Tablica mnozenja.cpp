#include <iostream>
using namespace std;

void func(int array[][10], int size)
{
    for (int i=1;i<=size;i++)
    {
        for (int j=1;j<=size;j++)
        {
            array[i][j] = i * j;
            cout << "[" << i << "]" << "[" << j << "]" << " = " << array[i][j] << endl;
        }
    }
}

int main()
{
    int size = 10;
    int array[size][10];

    func(array, size);
}
