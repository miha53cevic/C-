#include <iostream>
using namespace std;

int main(){
	
	int place_holder;
	int a,b;
	cin >> a >> b;
	
	place_holder = a;
	
	a = max(a,b);
	b = min(place_holder,b);
	
	cout << "Max: " << a << "\nMin: " << b << "\n";
	
	int c,d;
	c = a;
	d = b;
	
	do
	{
	
		if (c < 1000 && d < 1000)
		{
			for (int i=d; i<=c;i++)
			{
				if (i%7 == 0 && i%2 == 0)
				{
					cout << i << ", ";
				}
			}
			cout << endl << endl;
		}
		
		cin >> c >> d;
		
		place_holder = c;
	
		c = max(c,d);
		d = min(place_holder,d);
		
	}while (c != a && d != b);
	
	if (a != b)
	{
		
		for (int j=b;j>0;j--)
		{
			if (a%j == 0)
			{
				cout << "\n\nNajveci zajednicki djelitelj: " << j;
				break;	
			}
		}
	}
}
