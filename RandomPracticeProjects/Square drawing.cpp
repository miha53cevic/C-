#include <iostream>
using namespace std;

int main (){
	
	int size;
	string charachter;
	
	cout << "Enter the symbol you would like to use: ";
	cin >> charachter;
	
	cout << "Enter the size: ";
	cin >> size;
	
	for (int i=0;i < size;i++)
	{
		for (int j=0;j < size;j++)
		{
			cout << charachter;
		}
		cout << endl;
	}
	
}
