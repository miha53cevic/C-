#include <iostream>
using namespace std;

int main(){
	
	char word[4];
	cin >> word[0] >> word[1] >> word[2] >> word[3];
	
	system("cls");
	
	for(int a=0; a < 4;a++)
	{
		for(int b=0; b < 4;b++)
		{
			for(int c=0;c < 4;c++)
			{
				for(int d=0;d < 4;d++)
				{
					if (a != b && a != c && a != d && b != c && b != d && c != d)
					{
						cout << word[a] << word[b] << word[c] << word[d];
						cout << endl;
					}
				}
			}
		}
	}
		
}
