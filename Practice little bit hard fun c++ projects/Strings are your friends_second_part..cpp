#include <iostream>
#include <string>
using namespace std;
//Strings are your friends, until they betray you.

int main(){
	
	string name,surname;
	
	cout << "Enter your name: ";
	cin >> name;
	cout << "Enter your surname: ";
	cin >> surname;
	
	int name_length = name.length();
	int surname_length = surname.length();
	
	//name
	for (int i=0; i < name_length;i++)
	{
		if(name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u')
		{
			name[i] = 'z';
		}
	}
	
	//surname
	for (int i=0; i < surname_length;i++)
	{
		if(surname[i] == 'a' || surname[i] == 'e' || surname[i] == 'i' || surname[i] == 'o' || surname[i] == 'u')
		{
			surname[i] = 'z';
		}
	}
	
	cout << name + " " + surname;
}

//a, e, i , o, u

