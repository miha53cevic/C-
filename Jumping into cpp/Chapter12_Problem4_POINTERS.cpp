#include <iostream>
using namespace std;

int func(int a, int *b)
{
    int temp = *b;
    *b = temp*a;

    return a + temp;
}

int main()
{
    int a,b;
    cin >> a >> b;

    cout << "SUM: " << func(a, & b) << endl;
    cout << "MULTIPLICATION: " << b;

}
