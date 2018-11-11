#include <iostream>
using namespace std;

int main(){
	
	int a;
	int y = 0;
	cin >> a;
	
	for (int i=1;y<a;i++)
	{
		for (int j=0;j<i;j++)
		{
			y++;
			cout << y << "\t";
			
			if (y>=a)
			{
				break;
			}
		}
		cout << endl;
	}
}
