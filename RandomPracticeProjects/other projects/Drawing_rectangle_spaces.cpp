#include <iostream>
using namespace std;

int main(){
	
	int width,length,done = 0;
	
	cout << "Width: ";
	cin >> width;
	
	cout << "Length: ";
	cin >> length;
	
	for (int i=0; i != width - 2; i++)
	{
		done++;
		if(i == 0)
		{
			for (int k=0; k != length;k++)
			{
				cout << "*";
			}
			cout << endl;
		}
		
		cout << "*";
		
		for (int j=0; j != length - 2;j++)
		{
			cout << " ";
		}
		
		cout << "*";
		cout << endl;
	}
	
	if(done == width - 2)
		{
			for (int k=0; k != length;k++)
			{
				cout << "*";
			}
			cout << endl;
		}
	
	
}
