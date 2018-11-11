#include <iostream>
using namespace std;

void func_pointers(string *name, string *surname) //FUNKCIJA TE ADRESE SPREMA U POINTERE
{
    cout << "Name: ";
    cin >> *name; //BITAN * ISPRED VARIJABLE JER TAKO DAVAMO VRIJEDNOST POINTERU, TJ. a,b

    cout << "Surname: ";
    cin >> *surname;
}

void func_reference(string& name, string& surname)
{
    cout << "Name: ";
    cin >> name;

    cout << "Surname: ";
    cin >> surname;
}

int main()
{
    string a,b;
    func_pointers(& a, & b);    //SALJE SE ADRESA a i b VARIJABLE PREKO FUNKCIJE
    //func_reference(a,b);

    cout << a << " " << b;
}
