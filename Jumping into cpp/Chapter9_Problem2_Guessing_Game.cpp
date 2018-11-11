#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));

    int num = 1 + rand() % 100;

    int guess;

    while(guess != num)
    {
        cout << "Take a guess young one :P\nGuess: ";
        cin >> guess;

        if (guess > num) cout << "High\n\n";
        else if (guess < num) cout << "Low\n\n";
    }

    cout << "You got it!\nThe number was " << num;

    return 0;
}
