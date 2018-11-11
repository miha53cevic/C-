#include <iostream>
using namespace std;

int main(){
	
	int size;
	cin >> size;
	
	bool n=0;
	int i=0;
	int star=1;
	int razmak=size-1;
	
	while (i<size)
	{
		int j = 0;	//treba se staviti j=1 prije loopa jer dok unutarnji loop zavrsi varijabla se ne resetira pa kod ne moze nastaviti
		int k = 0;
			
		while (j<razmak)
		{
			cout << "	";
			j++;
		}
		
		while (k<star)
		{
			cout << "	*";	//Why this work I don't know and can't be bothered
			k++;
		}
		
		cout << endl;	
		
		if (razmak == 0)
		{
			n = 1;
			i = 0;
		}
			
		if (n==0)
		{
			razmak--;
			star = star + 2;	
			i++;
		}
		else if (n==1)
		{
			razmak++;
			star = star - 2;
			i++;
		}
	}
}
