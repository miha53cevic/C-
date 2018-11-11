#include <iostream>

int getReverse(int n)
{
    int nRemainder(0);
    int nReverse(0);

    while (n != 0)
    {
        nRemainder = n % 10;
        nReverse = nReverse*10 + nRemainder;
        n /= 10;
    }
    return nReverse;
}

int main()
{
    int n;
    std::cin >> n;

    std::cout << getReverse( n );

}
