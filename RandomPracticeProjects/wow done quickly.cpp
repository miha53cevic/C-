#include <iostream>
using namespace std;

int main(){
	
	start:
	
	int n;
	cin >> n;
	if (n <= 50)
	{
	cout << "W";
	
	for (int i=0; i != n;i++)
	{
		cout << "o";
	}
	
	cout << "w" << endl;
}
	else cout << "Number too big!\n";
	system ("pause");
	system("cls");
	goto start;
}
