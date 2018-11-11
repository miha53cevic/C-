#include <iostream>
using namespace std;

void func_pointers(string *name, string *surname) //FUNKCIJA TE ADRESE SPREMA U POINTERE
{
    cout << "Name: ";
    cin >> *name; //BITAN * ISPRED VARIJABLE JER TAKO DAVAMO VRIJEDNOST POINTERU, TJ. a,b

    if (surname == NULL)
    {
        cout << "Surname: ";
        cin >> *surname;
    }
}

int main()
{
    string a;
    string b;

    func_pointers(& a, & b);    //SALJE SE ADRESA a i b VARIJABLE PREKO FUNKCIJE

    cout << a << " " << b;
}
