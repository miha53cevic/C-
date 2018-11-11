#include <iostream>
#include <cstdlib>
using namespace std;
//Krizic kruzic 2.0 - Mihael Petricevic


//startup initialization
char square[9] = {'1','2','3','4','5','6','7','8','9'};		//polja koja su na pocetku brojke
int player1=0,player2=0,i=0,turn=1;		//player1 i player2 su input igraca, turn je varijabla koja prati ciji je red, i varijabla sluzi da bi se odredilo tko je pobijednik
string razmak = "				";		//razmak napravljen da se lakse ponavlja ista udaljenost

void checkwin();
void loop();			//svi su void jer nista ne vracaju
void board();
void reset();

int main (){

	board();		//stvara igrace polje

	if (turn == 1)		//turn je po defaultu 1 sto znaci da je prvi igrac uvijek prvi na redu
	{
	cout << "Player1, enter a number: ";
	cin >> player1;

	turn = 2;		//nakon sto prvi igrac zavrsi red je drugog ali prije toga unos igraca odlazi u loop

	loop();		//mjenja polja prema igracevom unosu
	}

	cout << "Player2, enter a number: ";
	cin >> player2;

	turn = 1;		//nakon sto je drugi igrac gotov vraca turn u 1

	loop();
}

void loop(){		//prema unosu korisinika mjenja polja

	if (player1 == 1 && square[0] == '1') square[0] = 'X';
	else if (player1 == 2 && square[1] == '2') square[1] = 'X';
	else if (player1 == 3 && square[2] == '3') square[2] = 'X';
	else if (player1 == 4 && square[3] == '4') square[3] = 'X';
	else if (player1 == 5 && square[4] == '5') square[4] = 'X';
	else if (player1 == 6 && square[5] == '6') square[5] = 'X';
	else if (player1 == 7 && square[6] == '7') square[6] = 'X';
	else if (player1 == 8 && square[7] == '8') square[7] = 'X';
	else if (player1 == 9 && square[8] == '9') square[8] = 'X';

	else if (player2 == 1 && square[0] == '1') square[0] = 'O';
	else if (player2 == 2 && square[1] == '2') square[1] = 'O';
	else if (player2 == 3 && square[2] == '3') square[2] = 'O';
	else if (player2 == 4 && square[3] == '4') square[3] = 'O';
	else if (player2 == 5 && square[4] == '5') square[4] = 'O';
	else if (player2 == 6 && square[5] == '6') square[5] = 'O';
	else if (player2 == 7 && square[6] == '7') square[6] = 'O';
	else if (player2 == 8 && square[7] == '8') square[7] = 'O';
	else if (player2 == 9 && square[8] == '9') square[8] = 'O';

	else {		//ako je broj veci od 9 program ispise krivi input
	cout << "Wrong input!\n";
	system("pause");
	}

	board();	//opet crta plocu da bi se vidjela promjena odmah nakon unosa
	checkwin();		//checkwin provjerava ako je neki igrac pobijedio

}


void checkwin(){		//provjerava sve mogucnosti

	if(square[0] == 'X' && square[1] == 'X' && square[2] == 'X')
		i = 1;
	else if(square[0] == 'X' && square[3] == 'X' && square[6] == 'X')
		i = 1;
	else if(square[6] == 'X' && square[7] == 'X' && square[8] == 'X')
		i = 1;
	else if(square[2] == 'X' && square[5] == 'X' && square[8] == 'X')
		i = 1;
	else if(square[0] == 'X' && square[4] == 'X' && square[8] == 'X')
		i = 1;
	else if(square[2] == 'X' && square[4] == 'X' && square[6] == 'X')
		i = 1;

	else if(square[0] == 'O' && square[1] == 'O' && square[2] == 'O')
		i = 2;
	else if(square[0] == 'O' && square[3] == 'O' && square[6] == 'O')
		i = 2;
	else if(square[6] == 'O' && square[7] == 'O' && square[8] == 'O')
		i = 2;
	else if(square[2] == 'O' && square[5] == 'O' && square[8] == 'O')
		i = 2;
	else if(square[0] == 'O' && square[4] == 'O' && square[8] == 'O')
		i = 2;
	else if(square[2] == 'O' && square[4] == 'O' && square[6] == 'O')
		i = 2;

	else if (square[0] != '1' && square[1] != '2' &&square[2] != '3' && square[3] != '4' && square[4] != '5' && square[5] != '6' && square[6] != '7' && square[7] != '8' && square[8] != '9')
		i = 3;		//ako su sva polja puna ali nitko nije pobijedio onda je nerjeseno (DRAW)


	if (i == 1){system("cls");board();cout << "Player 1 Wins!!!\n";system("pause");reset();}	//ako je igrac pobijedio izbrisi sve opet nacrtaj polje i napisi da je pobijedio
	else if (i == 2){system("cls");board();cout << "Player 2 Wins!!!\n";system("pause");reset();}	//te nakon toga resetiraj sve varijable na default vrijednosti
	else if (i == 3){system("cls");board();cout << "Its a DRAW!!!\n";system("pause");reset();}

	main();	//salje natrag na pocetak
}

void board(){		//crta cijelo igrace polje i azurira ga

	system("cls");

	cout << "\n\n\n\n\n";
	cout << razmak << "Krizic Kruzic\n\n\n";
	cout << "                          " << "Player1 = X | Player2 = O\n\n";

	cout << razmak << "   |   |   " << endl;
	cout << razmak << " " << square[0] << " | " << square[1] << " | " << square[2] << endl;
	cout << razmak << "___|___|___" << endl;
	cout << razmak << "   |   |   " << endl;
	cout << razmak << " " << square[3] << " | " << square[4] << " | " << square[5] << endl;
	cout << razmak << "___|___|___" << endl;
	cout << razmak << "   |   |   " << endl;
	cout << razmak << " " << square[6] << " | " << square[7] << " | " << square[8] << endl;
	cout << razmak << "   |   |   " << endl << endl;

}

void reset(){		//resetira sve varijable na default vrijednosti
	//startup values for squares (used for reset)
	square[0] = '1';
	square[1] = '2';
	square[2] = '3';
	square[3] = '4';
	square[4] = '5';
	square[5] = '6';
	square[6] = '7';
	square[7] = '8';
	square[8] = '9';
	i = 0;
	turn = 1;
}
