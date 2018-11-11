#include <iostream>
using namespace std;
//Drawing a triangle - hard version

int main(){
	
	//startup
	int size=0;
	int space=0;
	
	//start of main code
	cout << "Please enter the desired size of your triangle: ";
	cin >> size;
	
	space = size;
	
	for (int i=0; i != size; i++)
	{
		for (int j = space; j > 0; j--)
		{
			cout << " ";
		}
		for (int star=0; star <= i * 2; star++)
		{
			cout << "*";
		}
		space--;
		cout << endl;
	}
	
}
