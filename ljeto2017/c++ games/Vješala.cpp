#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
//Vje�ala igra - Mihael Petri�evi�

int main() {
	
	begining:
	//startup
	srand(time(0));
	
	string a,b,c,d,e,f,g,h,i,j;		//varijable koje slu�e za prazna polja od slova
	char x=0;						//varijabla u kojoj se nalazi unos korisnika i ono je slovo te je zato char = charachter
	string glava="", tijelo="", lruka="", druka="", lnoga="", dnoga="";		//sadr�e dijelove hangman-a
	int rijec;		//odlu�uje koja �e od 8 rije�i biti rije� koju �e igra� morati poga�ati
	int wrong=0;	//sprema se u njoj brojevi poku�aja tj. koliko je puta igra� pogrije�io slovo
	int n;			//slu�i samo da bi se spremio odgovor od igra�a te da se pomo�u njega mo�e upisati rje�enje
	int guess=0;		//slu�i da bi korisniku ponudio nakon nekoliko poga�anja mogu�nost da upi�e rje�enje
	string word[9];		//sprema 8 rije�i koje su ve� prije odre�ene
	string pogodi;		//u toj varijabli se nalazi rije� koju �e korisnik morati pogoditi isto slu�i za slova jer pogodi[0] = prvo slovo rije�i i tako dalje
	string y;		//sprema rje�enje koje je korisnik upisao i kasnije uspore�uje je li to�no
	string razmak = "                ";		//sprema razmak koji je odre�en, slu�i zbog lak�eg kori�tenja
	
	rijec = 1 + rand() % 8;  //odabire broj od 1 do 8 te ga onda sprema u rije�
	
	//words that are gonna be used in the game
	word[1] = "vjesala";
	word[2] = "zora";
	word[3] = "charlie";
	word[4] = "doma";					//prije odre�ene rije�i slu�e za igru
	word[5] = "televizor";
	word[6] = "minecraft";
	word[7] = "pewdiepie";
	word[8] = "rock";
	
	//decides which word is gonna be used in the game
	if (rijec == 1){pogodi = word[1];} 
	else if (rijec == 2){pogodi = word[2];} 
	else if (rijec == 3){pogodi = word[3];} 
	else if (rijec == 4){pogodi = word[4];} 		//pomo�u nasumi�nog broja napravljenog gore odre�uje rije�
	else if (rijec == 5){pogodi = word[5];} 
	else if (rijec == 6){pogodi = word[6];} 
	else if (rijec == 7){pogodi = word[7];} 
	else if (rijec == 8){pogodi = word[8];} 
	
	//broj mjesta za slova
	if (pogodi == word[1]){a = "-";b = "-";c = "-";d = "-";e = "-";f = "-";g = "-";h = "";i = "";j = "";}
	if (pogodi == word[2]){a = "-";b = "-";c = "-";d = "-";e = "";f = "";g = "";h = "";i = "";js = "";}
	if (pogodi == word[3]){a = "-";b = "-";c = "-";d = "-";e = "-";f = "-";g = "-";h = "";i = "";j = "";}
	if (pogodi == word[4]){a = "-";b = "-";c = "-";d = "-";e = "";f = "";g = "";h = "";i = "";j = "";}
	if (pogodi == word[5]){a = "-";b = "-";c = "-";d = "-";e = "-";f = "-";g = "-";h = "-";i = "-";j = "-";}
	if (pogodi == word[6]){a = "-";b = "-";c = "-";d = "-";e = "-";f = "-";g = "-";h = "-";i = "-";j = "-";}
	if (pogodi == word[7]){a = "-";b = "-";c = "-";d = "-";e = "-";f = "-";g = "-";h = "-";i = "-";j = "-";}
	if (pogodi == word[8]){a = "-";b = "-";c = "-";d = "-";e = "";f = "";g = "";h = "";i = "";j = "";}
	
	//clear screen
	system("cls"); 
		
	//drawing on the screen
	draw:
		
	cout << endl << endl;
	cout << razmak << "_______" << endl << razmak << "|" << "/" << "    " << glava;
	cout << endl << razmak << "|" << "    " << lruka << tijelo << druka;				//crta vje�ala i sve ostalo
	cout << endl << razmak << "|" << "    " << lnoga << " " << dnoga;			//crta dijelove �ovjeka kasnije po defaultu su "" ili ni�ta
	cout << endl << razmak << "|" << endl << endl;
	goto loop;

	//game mechanics
	unesi:
	
	//unos korisnika
	//cout << pogodi << endl; 
	cout << razmak << a << b << c << d << e << f << g << h << i << j << endl << endl;		//stvara prazna polja za rije�
	
	if(guess == 4){	//ako je guess ve� pro�ao 4 puta izvedi ovaj kod koji uglavnom slu�i da ponudi da se napi�e rje�enje i igra zavr�i
	guess = 0;	
	cout << "Odaberi: 1 - Unesi slovo:" << endl << "         2 - Napisi rjesenje (ako si rjesio izaberi ovu opciju)" << endl;
	cin >> n;
}	
	if (n == 2){
	
	//pobijeda	
	cout << "Rjesenje: ";	
	cin >> y;	
	if (y == pogodi) {cout << "Pobijedio si!";}		//ako je rje�enje to�no zavr�i igru, probao sam slo�iti da se resetira, ali ima �udnih problema
	else {system("cls");goto draw;}} 
	
	
	//unos slova tj. poga�anje slova	
	cout << "Unesi slovo: ";
	cin >> x;
	system ("cls");
	goto draw;
	
	//loop - provjera da li je korisnik pogodio bilo koje slovo rije�i i da li je pogrije�io
	loop:
	
	//je li korisnik pogodio slovo	
	if (x == pogodi[0]){a = pogodi[0];}
	if (x == pogodi[1]){b = pogodi[1];}
	if (x == pogodi[2]){c = pogodi[2];}
	if (x == pogodi[3]){d = pogodi[3];}
	if (x == pogodi[4]){e = pogodi[4];}
	if (x == pogodi[5]){f = pogodi[5];}
	if (x == pogodi[6]){g = pogodi[6];}
	if (x == pogodi[7]){h = pogodi[7];}
	if (x == pogodi[8]){i = pogodi[8];}
	if (x == pogodi[9]){j = pogodi[9];}
	
	guess++;
	
	//ako slovo ne pripada niti jednom slovu rije�i
	if (x != pogodi[0] && x != pogodi[1] && x != pogodi[2] && x != pogodi[3] && x != pogodi[4] && x != pogodi[5] && x != pogodi[6] && x != pogodi[7] && x != pogodi[8] && x != pogodi[9])
	{wrong++;}
	
	//ako je korisnik pogrije�io napravi ovo (isto crta hangman-a)
	if (wrong == 1) glava = "O"; 
	if (wrong == 2) tijelo = "|";
	if (wrong == 3) lruka = "-";
	if (wrong == 4) druka = "-";
	if (wrong == 5) lnoga = "l";
	if (wrong == 6) dnoga = "l";	
	
	//je li igra zavr�ila
	if (wrong == 8) {system("cls");cout << "Izgubio si!" << endl;system("pause");goto begining;}
	

	goto unesi;
}

	
	
	

	
	
