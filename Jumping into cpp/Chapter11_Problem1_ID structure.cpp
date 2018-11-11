#include <iostream>
using namespace std;

int main()
{
    struct ID
    {
        string name;
        string adress;
        string phone;
    };

    ID somebody;

    cout << "Enter persons name: ";
    cin >> somebody.name;

    cout << "\nEnter " << somebody.name << "'s adress: ";
    cin >> somebody.adress;

    cout << "\nEnter " << somebody.name << "'s phone number: ";
    cin >> somebody.phone;

    cout << endl << endl << endl;

    cout << somebody.name << endl << somebody.adress << endl << somebody.phone;
}
