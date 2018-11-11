#include <iostream>
using namespace std;
//drawing a cube with numbers

int main (){
	
	//startup
	int input,broj;
	
	//start of main code
	cout << "Enter the size of your cube: ";
	cin >> input;
	
	for (int i=0;i != input;i++)
	{
		for (int j=0;j != input;j++)
		{
			cout << i;
		}
		cout << endl;
	}
	
}
