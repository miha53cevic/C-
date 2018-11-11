#include <iostream>
using namespace std;

int main()
{
    //PRIMJER INPUTA MIHAEL, PETRICEVIC
    //PRIMJER OUTPOUTA MIHAEL PETRICEVIC
    while(1)
    {
        string name;
        getline(cin, name, ',');    //CIN TU LINIJU U NAME SVE DO ',' SIMABOLA

        //AKO JE IME PRAZNO ZAUSTAVI PROGRAM
        if (name.size() == 0)
        {
            break;
        }

        string surname;
        getline(cin, surname, '\n'); //DO NOVE LINIJE SPREMI U SURNAME (BEZ NOVE LINIJE)

        cout << name << " " << surname;
    }
}
