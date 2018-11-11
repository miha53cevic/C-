#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

//STRUCTURE KOJA CUVA INFORMACIJE O PRIJATELJIMA
struct storage
{
    string name;
    int days;
};

storage *growFriends (storage *p_friends, int& cur_size)
{
    storage *p_friends_new;
    //MAKE THE NEW ARRAY BIGGER THEN THE LAST ONE
    p_friends_new = new storage[cur_size + 1];

    for (int i=0;i<cur_size;i++)
    {
        //FILL NEW ARRAY WITH OLD ARRAY DATA
        p_friends_new[i] = p_friends[i];
    }
    cur_size = cur_size + 1;
    //CLEAR MEMEORY
    delete p_friends;
    //RETURN NEW ARRAY
    return p_friends_new;
}

storage* add_friend(storage *p_friends, int& size)
{
    char input;

    while (input != 'n')
    {
        //POVECAVA POINTER ARRAY ZA 1
        p_friends = growFriends(p_friends, size);

        cout << "Name: ";
        //DODAJE NOVO IME U POINTER ARRAY
        cin >> p_friends[size-1].name;
        cout << "Days since talked: ";
        //DODAJE NOVI BROJ DANA U POINTER ARRAY
        cin >> p_friends[size-1].days;

        cout << "Add more? y/n\n";
        cin >> input;

        //CISTI EKRAN
        system("cls");
    }
    //VRACA POINTER ARRAY TAKO DA BI SE MOGAO PROMJENITI ONAJ U MAIN(), MOGAO BI SE KORISTITI I JOS JEDAN POINTER ZA TO, ALI I OVO RADI
    return p_friends;
}

void edit_friend(storage *p_friends, int size)
{
    int input;
    char more;

    while (more != 'n')
    {
        cout << "FRIEND LIST\n";

        //ISPISUJE SVA IMENA U POINTER ARRAY BAZI
        for (int i=0;i<size;i++)
        {
            cout << "[" << i << "]" << p_friends[i].name << endl;
        }

        cout << "Edit (Enter number next to friends name :)\n";
        cin >> input;

        //MJENJA BROJ DANA I PRIKAZUJE TRENUTNI ZADNJI UNOS
        cout << "Days since talked change from " << p_friends[input].days << " to ";
        cin >> p_friends[input].days;

        cout << "Change someone else? y/n\n";
        cin >> more;

        system("cls");
    }
}

void sorted_list(storage *p_friends, int size)
{
    cout << "MOST RECENTLY TALKED TO FRIENDS" << endl;
}

int main()
{
    int size=0;
    storage *Friends;
    Friends = new storage[size];
    int input;

    //VRACA NA START POZICIJU PROGRAM
    reset:  //GOTO TU DOBRO DODE
    system ("cls");

    cout << "1.Add new friend\n2.Edit friend\n3.Show last spoken to list\nInput: ";
    cin >> input;

    switch(input)
    {
    case 1:
        {
            //NAPOMENA SIZE SE VRACA PREKO DVIJE FUNKCIJE TAKO DA JE AKO SE BILO KOJI SIZE PROMJENI MJENJA SE I OVAJ U MAIN()
            Friends = add_friend(Friends, size);
            goto reset;
        }
    case 2:
        {
            edit_friend(Friends, size);
            goto reset;
        }
    case 3:

        {
            sorted_list(Friends, size);
            goto reset;
        }
    default:
        {
            cout << "Wrong input!\n";
            system("pause");
            goto reset;
        }
    }
}
