#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
using namespace std;

void add(map<string,string> &adress_book)   //DA NEMA & (REFERENCE PASSING) SIMBOLA NEBI SE ADRESS_BOOK U MAINU MJENJAL
{
    int input;

    //AKO JE ADRESS_BOOK EMPTY //TAK SLOZEN AKO BUDEM POSLIJE IH HTEL DODADAVATI IZ .TXT DOKUMENTA
    if (adress_book.empty())
    {
        while (input != 0)
        {
            string name;
            string email;

            cout << "Name: ";
            cin >> name;
            cout << "Email: ";
            cin >> email;

            //MAP NAME = KEY, EMAIL = VRIJEDNOST
            adress_book[name] = email;

            cout << "Would you like to stop adding? Enter 0, otherwise enter any other number";
            cin >> input;
        }
    }
    //AKO NIJE SAMO DODAJ JER JE KORISNIK ODLUCIO DA ZELI DODDATI JOS LJUDI
    while (input != 0)
    {
        string name;
        string email;

        cout << "Name: ";
        cin >> name;
        cout << "Email: ";
        cin >> email;

        adress_book[name] = email;

        cout << "Would you like to stop adding? Enter 0, otherwise enter any other number";
        cin >> input;
    }
}

void remove (map<string, string> adress_book)
{
    int input;

    while (input != 0)
    {
        for (map<string, string>::iterator it = adress_book.begin(), end = adress_book.end();it != end; ++it)
        {
            cout << it->first << endl;
        }

        cout << "Enter who you would like to remove P.S. watch for capital letters! :=\n)";
        string remove_name;
        cin >> remove_name;
        adress_book.erase(remove_name);

        cout << "Quit? Enter 0\n";
        cin >> input;
        system("cls");
    }
}

void list (map<string, string> adress_book)
{
    for (map<string, string>::iterator it = adress_book.begin(), end = adress_book.end(); it != end; ++it)
    {
        cout << it->first << " --> " << it->second << endl;
    }
}

int main()
{
    int input;
    map<string, string> adress_book;
    add(adress_book);

    while (input != 4)
    {
        cout << "What would you like to do?\n";
        cout << "1. Add more people\n2. Remove someone\n3. List all entries\n4. Exit\n\nInput: ";
        cin >> input;

        system("cls");

        switch (input)
        {
        case 1:
            {
                add(adress_book);
                break;
            }
        case 2:
            {
                remove(adress_book);
                break;
            }
        case 3:
            {
                list(adress_book);
                break;
            }
        }
    }
    return 0;
}
