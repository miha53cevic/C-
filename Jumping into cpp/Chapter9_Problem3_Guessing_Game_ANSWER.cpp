#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(NULL));

    int guess;
    string input;

    cout << "I can guess any number you can think of in 7 tries!\nBetween 1 - 100";
    cout << "\nType in low or high dependent on my guess!\n\n";

    int min=1,max=100;
    int tries=1;

    guess = min + rand() % max;

    cout << guess;
    cout << "\nTries: " << tries << endl ;

    while (tries < 8)
    {
        cin >> input;

        if (input == "low")
        {
            min = guess;
            guess = (min+max) / 2;
        }
        else if (input == "high")
        {
            max = guess;
            guess = (min+max) / 2;
        }

        tries++;

        cout << guess;
        cout << "\nTries: " << tries << endl << endl;
    }
}
