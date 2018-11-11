#include <iostream>
using namespace std;

int *growArray(int* p_values, int& cur_size) //growArray JE POINTER JER INACE NEBI MOGAO VRATITI POINTERA p_new_values
{
    //NOVI ARRAY ZAMJENJUJE STARI POSLIJE U FOR LOOP-U
    int *p_new_values = new int[cur_size * 2]; //STVARAM NOVI ARRAY I STAVLJAM DA JE DVOSTRUKO VECI JER AKO BI POVECAVALI ZA 1 BI BILO SPORO I PROBLEMA KASNIJE

    for (int i=0;i<cur_size;i++)
    {
        //STAVLJA STARE BROJKE IZ STAROV ARRAY POINTERA U NOVI ARRAY POINTER
        p_new_values[i] = p_values[i];
    }

    //TREBA SE OSLOBDOTITI MEMORIJA NAKON INACE JE CRASH
    delete p_values;

    cur_size = cur_size * 2;    //MJENJA SIZE U MAIN FUNKCIJI

    return p_new_values; //VRACA NOVI POINTER ARRAY
}

int main()
{
    int next_element = 0;
    int size = 2;   //VELICINA POCETNOG ARRAYA, ZBOG NEKOG RAZLOGA MOZE IMATI VISE OD 2 NAPOCETKU ALI JE NASUMICNO OVISNO O VRIJEDNOSTI SIZE-a BUDE LI CRASHAL AKO JE ZA 2+ VISE OD SIZE
    int *p_values = new int[size]; //POINTER ARRAY KOJI JE VELICINE SIZE
    int val;    //VRIJEDNOST KOJJU KORISNIK UNOSI

    cout << "Enter a value: ";
    cin >> val;

    while (val > 0)
    {
        if (size == next_element + 1) //AKO JE ARRAY PUN ZOVI FUNKCIJU KOJA GA POVECA
        {
            p_values = growArray(p_values, size);
        }

        p_values[next_element] = val;   //STAVLJA VAL U POINTER ARRAY
        next_element = next_element + 1;    //POVECAVA NEXT_ELEMENT ZA 1 TAKO DA BI SE ARRAY MOGAO POPUNITI

        cout << "Please enter a number (or 0 to exit): ";
        cin >> val;
    }
    cout << "SIZE OF ARRAY: " <<  size << endl << endl; //AKO SE HOCE VIDJETI KOLIKO JE VELIK ARRAY

    for (int i=0;i<size;i++)
    {
        cout << "[" << i << "]" << " = " << p_values[i] << endl;
    }
}
