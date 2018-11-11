#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
//Vješala igra - Mihael Petrièeviæ

int main() {
	
	begining:
	//startup
	srand(time(0));
	
	string a,b,c,d,e,f,g,h,i,j;		//varijable koje služe za prazna polja od slova
	char x=0;						//varijabla u kojoj se nalazi unos korisnika i ono je slovo te je zato char = charachter
	string glava="", tijelo="", lruka="", druka="", lnoga="", dnoga="";		//sadrže dijelove hangman-a
	int rijec;		//odluèuje koja æe od 8 rijeèi biti rijeè koju æe igraè morati pogaðati
	int wrong=0;	//sprema se u njoj brojevi pokušaja tj. koliko je puta igraè pogriješio slovo
	int n;			//služi samo da bi se spremio odgovor od igraæa te da se pomoæu njega može upisati rješenje
	int guess=0;		//služi da bi korisniku ponudio nakon nekoliko pogaðanja moguænost da upiše rješenje
	string word[9];		//sprema 8 rijeèi koje su veæ prije odreðene
	string pogodi;		//u toj varijabli se nalazi rijeè koju æe korisnik morati pogoditi isto služi za slova jer pogodi[0] = prvo slovo rijeèi i tako dalje
	string y;		//sprema rješenje koje je korisnik upisao i kasnije usporeðuje je li toèno
	string razmak = "                ";		//sprema razmak koji je odreðen, služi zbog lakšeg korištenja
	
	rijec = 1 + rand() % 8;  //odabire broj od 1 do 8 te ga onda sprema u rijeè
	
	//words that are gonna be used in the game
	word[1] = "vjesala";
	word[2] = "zora";
	word[3] = "charlie";
	word[4] = "doma";					//prije odreðene rijeèi služe za igru
	word[5] = "televizor";
	word[6] = "minecraft";
	word[7] = "pewdiepie";
	word[8] = "rock";
	
	//decides which word is gonna be used in the game
	if (rijec == 1){pogodi = word[1];} 
	else if (rijec == 2){pogodi = word[2];} 
	else if (rijec == 3){pogodi = word[3];} 
	else if (rijec == 4){pogodi = word[4];} 		//pomoæu nasumiènog broja napravljenog gore odreðuje rijeè
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
	cout << endl << razmak << "|" << "    " << lruka << tijelo << druka;				//crta vješala i sve ostalo
	cout << endl << razmak << "|" << "    " << lnoga << " " << dnoga;			//crta dijelove èovjeka kasnije po defaultu su "" ili ništa
	cout << endl << razmak << "|" << endl << endl;
	goto loop;

	//game mechanics
	unesi:
	
	//unos korisnika
	//cout << pogodi << endl; 
	cout << razmak << a << b << c << d << e << f << g << h << i << j << endl << endl;		//stvara prazna polja za rijeè
	
	if(guess == 4){	//ako je guess veæ prošao 4 puta izvedi ovaj kod koji uglavnom služi da ponudi da se napiše rješenje i igra završi
	guess = 0;	
	cout << "Odaberi: 1 - Unesi slovo:" << endl << "         2 - Napisi rjesenje (ako si rjesio izaberi ovu opciju)" << endl;
	cin >> n;
}	
	if (n == 2){
	
	//pobijeda	
	cout << "Rjesenje: ";	
	cin >> y;	
	if (y == pogodi) {cout << "Pobijedio si!";}		//ako je rješenje toèno završi igru, probao sam složiti da se resetira, ali ima èudnih problema
	else {system("cls");goto draw;}} 
	
	
	//unos slova tj. pogaðanje slova	
	cout << "Unesi slovo: ";
	cin >> x;
	system ("cls");
	goto draw;
	
	//loop - provjera da li je korisnik pogodio bilo koje slovo rijeèi i da li je pogriješio
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
	
	//ako slovo ne pripada niti jednom slovu rijeèi
	if (x != pogodi[0] && x != pogodi[1] && x != pogodi[2] && x != pogodi[3] && x != pogodi[4] && x != pogodi[5] && x != pogodi[6] && x != pogodi[7] && x != pogodi[8] && x != pogodi[9])
	{wrong++;}
	
	//ako je korisnik pogriješio napravi ovo (isto crta hangman-a)
	if (wrong == 1) glava = "O"; 
	if (wrong == 2) tijelo = "|";
	if (wrong == 3) lruka = "-";
	if (wrong == 4) druka = "-";
	if (wrong == 5) lnoga = "l";
	if (wrong == 6) dnoga = "l";	
	
	//je li igra završila
	if (wrong == 8) {system("cls");cout << "Izgubio si!" << endl;system("pause");goto begining;}
	

	goto unesi;
}

	
	
	

	
	
