#include <iostream>
using namespace std;
//drawing a triangle - easy

int main (){
	
	//startup
	int size=0;		//velicina trokuta
	int value=0;	//varijabla koristena za nested for loop
	
	//main code
	cout << "Enter the size of desired triangle: ";
	cin >> size;
	
	value = size;	//varijabla ima isti iznos kao i velicina trokuta
	
	for (int i=0;i != size;i++) //nested for loop pogledaj primjer u temolatu
	{
		for (int j=0;j != value;j++)
		{
		cout << "*";
		}
	
	value--;	//oduzimam tako da bi isli od x broj * za jedan manje te da dobijemo trokut
	cout << endl;
	
	}
}

