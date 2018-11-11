#include <iostream>
using namespace std;
//Classes template

class Ucenik
{
	public: //if it's not public the variables can't be used
		string ime;
		string prezime;
		string redni_broj;
};

void print_info(Ucenik ucenik){
	
	cout << ucenik.ime << endl;
	cout << ucenik.prezime << endl;
	cout << ucenik.redni_broj << endl;
	
}

int main(){
	
	Ucenik ucenik;
	
	Ucenik Mihael;
	Mihael.ime = "Mihael";
	Mihael.prezime = "Petricevic";
	Mihael.redni_broj = "18";
	
	Ucenik Marko;
	Marko.ime = "Marko";
	Marko.prezime = "Novak";
	Marko.redni_broj = "16";
	
	//prints out the information
	print_info(Mihael);
	
	print_info(Marko);
	
}
