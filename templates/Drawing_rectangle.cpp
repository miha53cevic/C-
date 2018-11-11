#include<iostream>
using namespace std;
//Cratnje kocke

int main()
{

int length=0, width=0; //varijable

cout << "Enter the length of the rectangle\n";
cin>>length;
cout << "Enter the width of the rectangle\n";
cin>>width;

for(int i=0; i<length; i++)		//ovo se zove nested for loop
{
    for(int j=0; j<width; j++)
 	{
 		cout << "*";
	}
	cout << endl;
}
	//////////////////////////////////
	//objasnjenje nested for loop-a///
	//////////////////////////////////
//nested for loop radi tako da se prvo uvijek obavi unutarnji for loop tek data vanjski for loop nastavlja
//znaci tek kada unutarnji loop tj. j>=width tek data vanjski for loop i=1 i tako dalje
//zbog toga se prvo nacrta width kocke i napravi razmak te se zatim opet ponavlja
//zamisli si samo da kada unutarnji for loop zavrsi svoje i dode do broja koji je zadan tek tada je kod vanjskog for loopa i++ ili na pocetku i=1
//i onda opet ide unutarnji for loop i onda nakon je i=2 i tako dalje i dalje dok program ne zavrsi

//	for(int i=0; i<length; i++)	 ---> pocetak vanjskog for loopa
//	{									
//   	 for(int j=0; j<width; j++)	---> pocetak unutarnjeg for loopa
// 		{
// 			cout << "*";
//		}
//		cout << endl;	---> kraj unutarnjeg for loopa
//}		---> kraj vanjskog for loopa

}
