#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int size = 5;

struct ID
{
    string name;
    int oib;
};

void add(ID person[])
{
    for (int i=0;i<size;i++)
    {
        string name;
        int oib;

        cout << "Name: ";
        cin >> name;
        cout << "\nOib: ";
        cin >> oib;

        person[i].name = name;
        person[i].oib = oib;

        system("cls");
    }
}

void display(ID person[])
{
    for (int i=0;i<size;i++)
    {
        cout << person[i].name << endl << person[i].oib << endl << endl;
    }
    cout << endl;

    system("pause");
    system("cls");
}

void sort(ID person[])
{
    cout << "Enter starting letter: ";
    string letter;
    cin >> letter;

    cout << "\n\nPeople with the requested letter " << letter << endl;


    for (int i=0;i<size;i++)
    {


        if (person[i].name[0] == letter[0])
        {
            cout << person[i].name << endl;
        }

        cout << endl;

        system("pause");
        system("cls");
    }
}

int main()
{
    int input;
    ID person[size];

    cout << "ADRESS BOOK" << endl;
    cout << "1. Add\n2.Display all\n3.Search for\nInput: ";
    cin >> input;

    switch(input)
    {
    case 1:
        {
            add(person);
            main();
        }
    case 2:
        {
            display(person);
            main();
        }
    case 3:
        {
            sort(person);
            main();
        }
    }
}
