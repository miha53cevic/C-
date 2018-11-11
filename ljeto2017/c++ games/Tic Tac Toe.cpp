#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
//križiæ kružiæ igra
//Mihael Petrièeviæ

int main() {
	
	begining:
	
	srand(time(0));
	
	string a = "-";
	string b = "-";
	string c = "-";
	string d = "-";
	string e = "-";				//varijable koje sluze kao polja za x i o, a mogu biti i -
	string f = "-";
	string g = "-";
	string h = "-";
	string i = "-";
	bool iskoristenoX1=false, iskoristenoX2=false, iskoristenoX3=false, iskoristenoX4=false, iskoristenoX5=false, iskoristenoX6=false, iskoristenoX7=false, iskoristenoX8=false, iskoristenoX9=false;
	bool iskoristenoO1=false, iskoristenoO2=false, iskoristenoO3=false, iskoristenoO4=false, iskoristenoO5=false, iskoristenoO6=false, iskoristenoO7=false, iskoristenoO8=false, iskoristenoO9=false;         
	bool igra;					//gleda ako je igra zapoèela i zapoèinje tek kada korisnik unese svoje prvo mjesto
	bool xwin=false,owin=false;		//varijable koje gledaju koji je igraè pobijedio
	bool loopdone;				//gleda ako je loop završio služi da bi se o prikazao odmah nakon što ga korisnik upiše
	int x=0;			//sprema input od usera za polje gdje æe x biti
	int o=0;			//sprema input od usera za polje gdje æe o biti
	int n;			//random varijabla, služi na kraju da se loopdone nebi dogodio kod kružiæa
	string razmak = "                          "; 	//služi za smanjeno pisanjei da razmak uvijek bude isti
	
	igra = false;		//igra je na poèetku false
	
	//diffrent combination board layouts
	loop:
	
	if (x == 1 && o != 1 && iskoristenoX1 == false && iskoristenoO1 == false){a = "x"; iskoristenoX1 = true;}	//gleda ako polje nije isto kao koje
	if (x == 2 && o != 2 && iskoristenoX2 == false && iskoristenoO2 == false){b = "x"; iskoristenoX2 = true;}	//je od drugog igraæa i provjerava je
	if (x == 3 && o != 3 && iskoristenoX3 == false && iskoristenoO3 == false){c = "x"; iskoristenoX3 = true;}	//je li to polje veæ zauzeto od x ili
	if (x == 4 && o != 4 && iskoristenoX4 == false && iskoristenoO4 == false){d = "x"; iskoristenoX4 = true;}	//o polja
	if (x == 5 && o != 5 && iskoristenoX5 == false && iskoristenoO5 == false){e = "x"; iskoristenoX5 = true;}
	if (x == 6 && o != 6 && iskoristenoX6 == false && iskoristenoO6 == false){f = "x"; iskoristenoX6 = true;}
	if (x == 7 && o != 7 && iskoristenoX7 == false && iskoristenoO7 == false){g = "x"; iskoristenoX7 = true;}
	if (x == 8 && o != 8 && iskoristenoX8 == false && iskoristenoO8 == false){h = "x"; iskoristenoX8 = true;}
	if (x == 9 && o != 9 && iskoristenoX9 == false && iskoristenoO9 == false){i = "x"; iskoristenoX9 = true;}

	if (x != 1 && o == 1 && iskoristenoO1 == false && iskoristenoX1 == false){a = "o"; iskoristenoO1 = true;} 
	if (x != 2 && o == 2 && iskoristenoO2 == false && iskoristenoX2 == false){b = "o"; iskoristenoO2 = true;}
	if (x != 3 && o == 3 && iskoristenoO3 == false && iskoristenoX3 == false){c = "o"; iskoristenoO3 = true;}
	if (x != 4 && o == 4 && iskoristenoO4 == false && iskoristenoX4 == false){d = "o"; iskoristenoO4 = true;}
	if (x != 5 && o == 5 && iskoristenoO5 == false && iskoristenoX5 == false){e = "o"; iskoristenoO5 = true;}
	if (x != 6 && o == 6 && iskoristenoO6 == false && iskoristenoX6 == false){f = "o"; iskoristenoO6 = true;}
	if (x != 7 && o == 7 && iskoristenoO7 == false && iskoristenoX7 == false){g = "o"; iskoristenoO7 = true;}
	if (x != 8 && o == 8 && iskoristenoO8 == false && iskoristenoX8 == false){h = "o"; iskoristenoO8 = true;}
	if (x != 9 && o == 9 && iskoristenoO9 == false && iskoristenoX9 == false){i = "o"; iskoristenoO9 = true;}
	
	//opet crta layouta igre te ga tako zapravo update-a
	system("cls");
	cout << endl << endl;
	cout << razmak << razmak << "    Tutorial" << endl;
	cout << razmak << a << "|" << b << "|" << c << razmak << "1" << "|" << "2" << "|" << "3" << endl;		//crta polja i slaže tutorial
	cout << razmak << d << "|" << e << "|" << f << razmak << "4" << "|" << "5" << "|" << "6" << endl;
	cout << razmak << g << "|" << h << "|" << i << razmak << "7" << "|" << "8" << "|" << "9" << endl;
	
	//pobjeda loop
		
		//PLayer 1 (X) pobjeda
		if (iskoristenoX1 == true && iskoristenoX2 == true && iskoristenoX3 == true) xwin = true;
		if (iskoristenoX4 == true && iskoristenoX5 == true && iskoristenoX6 == true) xwin = true;
		if (iskoristenoX7 == true && iskoristenoX8 == true && iskoristenoX9 == true) xwin = true;
		
		if (iskoristenoX1 == true && iskoristenoX4 == true && iskoristenoX7 == true) xwin = true;
		if (iskoristenoX2 == true && iskoristenoX5 == true && iskoristenoX8 == true) xwin = true;		//provjerava sve moguæe naèine za pobjedu
		if (iskoristenoX3 == true && iskoristenoX6 == true && iskoristenoX9 == true) xwin = true;
		
		if (iskoristenoX1 == true && iskoristenoX5 == true && iskoristenoX9 == true) xwin = true;
		if (iskoristenoX3 == true && iskoristenoX5 == true && iskoristenoX7 == true) xwin = true;
		
		//PLayer 2 (O) pobjeda
		if (iskoristenoO1 == true && iskoristenoO2 == true && iskoristenoO3 == true) owin = true;
		if (iskoristenoO4 == true && iskoristenoO5 == true && iskoristenoO6 == true) owin = true;
		if (iskoristenoO7 == true && iskoristenoO8 == true && iskoristenoO9 == true) owin = true;
		
		if (iskoristenoO1 == true && iskoristenoO4 == true && iskoristenoO7 == true) owin = true;
		if (iskoristenoO2 == true && iskoristenoO5 == true && iskoristenoO8 == true) owin = true;
		if (iskoristenoO3 == true && iskoristenoO6 == true && iskoristenoO9 == true) owin = true;
		
		if (iskoristenoO1 == true && iskoristenoO5 == true && iskoristenoO9 == true) owin = true;
		if (iskoristenoO3 == true && iskoristenoO5 == true && iskoristenoO7 == true) owin = true;
	
	//end mechanics
	if (xwin == true) {system("cls"); cout << "Player 1 wins!" << endl; system("pause"); goto begining;}
	if (owin == true) {system("cls"); cout << "Player 2 wins!" << endl; system("pause"); goto begining;}	//provjerava je li netko pobjedio
	
	if (igra == true && n == 1) {loopdone == true; goto odabir;}
	if (igra == true) goto krug;  
	
	
	//odabir gdje su krug i križiæ
	odabir:
	
	//razne varijable da bi se krug i križ mogli prikazati odmah nakon upisanja	
	n = 0;
	loopdone == false;
	igra = true;
	
	//križiæ	
	cout << endl << "Choose a number from 1 to 9" << endl;
		cout << "Player 1: ";			//pita korisnika gdje æe x biti
		cin >> x;

	goto loop;
		
	//krug
	
	krug:
		
	cout << endl << "Choose a number from 1 to 9" << endl;	
		cout << "Player 2: ";			//pita korisnika gdje æe o biti
		cin >> o;
	
	if (loopdone == false){n=1; goto loop;}		//stvara loopdone-a jer želimo da se o prikaže na polju odmah nakon što damo input
	goto odabir; 
}

