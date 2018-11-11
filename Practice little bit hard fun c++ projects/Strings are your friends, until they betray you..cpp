#include <iostream>
#include <string>
using namespace std;
//Strings are your friends, until they betray you.

int main(){
	
	//strings to be used
	string name,surname;
	string full_name;
	string reverse_name;
	
	//receving the name and surname of user
	cout << "Enter your first name: ";
	cin >> name;
	
	cout << "Enter your surname: ";
	cin >> surname;
	
	//combining the 2 strings into one with a space in between
	full_name = name + " " + surname;
	
	//creating the reverse name and surname
	int length_name, length_surname;
	
	//backup variables so that the letters can be swapped
	string backup_name = name;
	string backup_surname = surname;
	
	//calculates the amount of charachters in the name and surname and does a - 1 to that number
		//the reason is that the name[0] starts counting from zero up so that means the highest number will be the length - 1
	length_name = name.length() - 1;
	length_surname = surname.length() - 1;

	//loop that repleaces the first letter of the name name[0] with the backup_name last letter which is length_name - i
		//length_name + 1 is because the the total number of letters is still the same but it counts from zero up so we had to get rid of 1 before
	for (int i=0; i < length_name + 1;i++)
	{
		name[i] = backup_name[length_name - i];
	}
	
	//same thing just for the surname
	for (int j=0; j < length_surname + 1;j++)
	{
		surname[j] = backup_surname[length_surname - j];
	}
	
	//combining the 2 strings with a space in between
	reverse_name = name + " " + surname;
	
	//outputing the name and the reverse name
	cout << "\nYour name is " << full_name;
	cout << endl;
	cout << reverse_name;
}
