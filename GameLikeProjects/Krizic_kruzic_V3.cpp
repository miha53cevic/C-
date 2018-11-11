#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//Tic - Tac - Toe V3

char square[9] = {'1','2','3','4','5','6','7','8','9'};
int x,o;
int win=0;
int used[10];

void logic();
void draw();
void check_win();

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
	
	srand(time(0));
	
	draw();
	
	while(win == 0)
	{
		cout << "PlayerX: ";
		cin >> x;
		//stavlja da je mjesto koje je korisnik odabrao sada iskoristeno
		used[x] = 1;
		
		logic();
		
		if (win == 0)
		{
			
			//Computer AI
			o = 1 + rand() % 9;
			
			//Ako je broj koji je racunalo odabrao vec iskoristen zamijeni ga tako dugo dok ne dobijes mjesto koje nije iskoristeno
			while(used[o] == 1)
			{
				o = 1 + rand() % 9;
			}
	
			//stavlja da je mjesto koje je racunalo odabralo sada iskoristeno
			used[o] = 1;
			
			logic();
		}
	} 
	
	if (win == 1) cout << "PlayerX wins!";
	if (win == 2) cout << "Computer wins!";
	if (win == 3) cout << "It's a TIE!";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void draw(){
	
	string razmak = "				";
	
	cout << "\n\n\n\n\n";
	cout << razmak << "Krizic Kruzic\n\n\n";
	cout << "                          " << "Player1 = X | Computer = O\n\n";
	
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void logic(){
	
	if (x == 1 && square[0] == '1') square[0] = 'X';
	else if (x == 2 && square[1] == '2') square[1] = 'X';
	else if (x == 3 && square[2] == '3') square[2] = 'X';
	else if (x == 4 && square[3] == '4') square[3] = 'X';
	else if (x == 5 && square[4] == '5') square[4] = 'X';
	else if (x == 6 && square[5] == '6') square[5] = 'X';
	else if (x == 7 && square[6] == '7') square[6] = 'X';
	else if (x == 8 && square[7] == '8') square[7] = 'X';
	else if (x == 9 && square[8] == '9') square[8] = 'X';
	
	if (o == 1 && square[0] == '1') square[0] = 'O';
	else if (o == 2 && square[1] == '2') square[1] = 'O';
	else if (o == 3 && square[2] == '3') square[2] = 'O';
	else if (o == 4 && square[3] == '4') square[3] = 'O';
	else if (o == 5 && square[4] == '5') square[4] = 'O';
	else if (o == 6 && square[5] == '6') square[5] = 'O';
	else if (o == 7 && square[6] == '7') square[6] = 'O';
	else if (o == 8 && square[7] == '8') square[7] = 'O';
	else if (o == 9 && square[8] == '9') square[8] = 'O';
	
	check_win();
	system("cls");
	draw();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void check_win(){
	
	if(square[0] == 'X' && square[1] == 'X' && square[2] == 'X')
		win = 1;
	else if(square[0] == 'X' && square[3] == 'X' && square[6] == 'X')
		win = 1;
	else if(square[3] == 'X' && square[4] == 'X' && square[5] == 'X')
		win = 1;
	else if(square[6] == 'X' && square[7] == 'X' && square[8] == 'X')
		win = 1;
	else if(square[2] == 'X' && square[5] == 'X' && square[8] == 'X')
		win = 1;
	else if(square[0] == 'X' && square[4] == 'X' && square[8] == 'X')
		win = 1;
	else if(square[2] == 'X' && square[4] == 'X' && square[6] == 'X')
		win = 1;
	
	if(square[0] == 'O' && square[1] == 'O' && square[2] == 'O')
		win = 2;
	else if(square[0] == 'O' && square[3] == 'O' && square[6] == 'O')
		win = 2;
	else if(square[3] == 'O' && square[4] == 'O' && square[5] == 'O')
		win = 2;
	else if(square[6] == 'O' && square[7] == 'O' && square[8] == 'O')
		win = 2;
	else if(square[2] == 'O' && square[5] == 'O' && square[8] == 'O')
		win = 2;
	else if(square[0] == 'O' && square[4] == 'O' && square[8] == 'O')
		win = 2;
	else if(square[2] == 'O' && square[4] == 'O' && square[6] == 'O')
		win = 2;
	
	if (square[0] != '1' && square[1] != '2' &&square[2] != '3' && square[3] != '4' && square[4] != '5' && square[5] != '6' && square[6] != '7' && square[7] != '8' && square[8] != '9')
		win = 3;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

