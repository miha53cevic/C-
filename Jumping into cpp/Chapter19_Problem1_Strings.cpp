#include <string>
#include <iostream>
using namespace std;

int main()
{
    string a = "needle", b = "haystack needle";
    int instances_of_a = 0;

    //STRING::NPOS KRAJ STRINGA --> VRACA .FIND AKO NE NADE NISTA
    //.FIND ("RIJEC", POCETNA POZICIJA U STRINGU)
    for (int i=b.find(a, 0); i != string::npos; i = b.find(a, i))
    {
        //I++ POMICE POZICIJU DALJE JER .FIND VRACA POZICIJU/BROJ GDJE POCINJE TRAZENA RIJEC U STRINGU PA ZATO SE RADI I++ DA BI SE TRAZILO DALJE I ZATO JE b.find(a,i), GDJE JE I SLOVO DALJE OD PRONAÐENE RIJECI AKO JE PRONADENA
        i++;
        instances_of_a++;
    }
    cout << instances_of_a;
}
