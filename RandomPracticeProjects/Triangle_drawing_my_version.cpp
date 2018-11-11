#include <iostream>
using namespace std;

int main() {
	
	int size;
	int spaces;
	int stars;
	
	cout << "Size of Triangle: ";
	cin >> size;
	
	spaces = size;
	
	for (int i=0; i < size;i++)
	{
		for (int j=0; j < spaces;j++)
		{
			cout << " ";	
		}
		
		for (int star=0; star < stars;star++)
		{
			cout << "*";
		}
		
		cout << endl;
		
		spaces--;
		stars = stars + 2;
	}
	
}
