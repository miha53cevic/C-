#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;
//Hangman v2

string word0,word1,word2,word3,word4;
string guess_word;
string backup_word;
char input;

bool started = false;
int man=0;
int size_of_word;
char hangman[7];
int choice=0;

int game_name[5][52] = {
	1,0,0,0,1,0,0,0,0,1,1,0,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,1,0,0,0,1,
	1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,1,1,0,0,1,0,0,1,0,0,0,0,1,0,0,1,1,0,0,0,1,1,0,0,0,1,0,0,1,0,0,0,1,1,0,0,1,
	1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,0,1,0,1,0,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,0,1,1,1,1,1,1,0,0,1,0,1,0,1,
	1,0,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,1,1,0,0,1,0,0,1,1,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,1,1,
	1,0,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,0,0,1,1,1,1,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1
};

void draw();
int checkwin();
void logic();
void hangman_draw();

int main(){
	
	srand(time(0));
	
	draw();
	cout << "1. Play" << endl << "2. Add your own words" << endl << "3. Quit\nAnswer: ";
	cin >> choice;
	
	//use your own words
	if (choice == 2)
	{
		system("cls");
		cout << "Enter your words one by one!\n";
		cin >> word0;
		cin >> word1;
		cin >> word2;
		cin >> word3;
		cin >> word4;
	}
	
	//default words
	if (choice != 2)
	{
		word0 = "mihael";
		word1 = "table";
		word2 = "hangman";
		word3 = "programming";
		word4 = "school";
	}
	
	//exit the game
	if (choice == 3)
	{
		exit(0);
	}
	
	//startup initialization
	int broj = rand() % 4;
	
	if (broj == 0)
	{
		guess_word = word0;
		backup_word = word0;
	} 
	if (broj == 1)
	{
		 guess_word = word1;
		 backup_word = word1;
	}
	if (broj == 2)
	{
		guess_word = word2;
		backup_word = word2;
	}
	if (broj == 3) 
	{
		guess_word = word3;
		backup_word = word3;
	}
	if (broj == 4) 
	{
		guess_word = word4;
		backup_word = word4;
	}
	
	size_of_word = guess_word.length();
	
	//makes all chars in the word blank spaces
	for (int i=0; i < size_of_word; i++)
	{
		guess_word[i] = '_';
	}
	
	//start of the game
	system("cls");
	
	while (1){
		
		//functions
		draw();
		logic();
		checkwin();
		hangman_draw();
		
		//ends loop
		int i=0;
		i = checkwin();
		
		if (i == 1 || man == 7)
		{
			system("cls");
			
			draw();
			if (i == 1)
			{
				cout << "You guessed: " << guess_word;
			}
			else
			{
				cout << "You lost!" << endl << "The word was: " << backup_word;	
			}
			
			
			return 0;
		}
		
		//creating blank spaces
		cout << "Word: ";
		for (int i=0; i < size_of_word; i++)
		{
			cout << guess_word[i];
		}
		
		//wait for user input
		cout << "\n\nGuess: ";
		cin >> input;
		
		started = true;
	}
}

/////////////////////////////////////////////////////////////////////

void draw(){
	
	//sets the cursor on the begining of the screen
	COORD cur = {0, 0};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
	
	//drawing the game_name
	for (int i=0; i < 5; i++)
	{
		for (int j=0; j < 52; j++)
		{
			if (game_name[i][j] == 1)
			{
				cout << "#";
			}
			if (game_name[i][j] == 0)
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	
	//drawing the hangman himself
	cout << "\n\n\n";
	
	cout << " __________" << endl;
	cout << " |/       |" << endl;
	cout << " |        " << hangman[0] << endl;
	cout << " |       " << hangman[3] << hangman[1] << hangman[4] << "			" << endl;
	cout << " |        " << hangman[2] << endl;
	cout << " |       " << hangman[5] << " " << hangman[6] << endl;
	cout << " |" << endl << " |" << endl << endl;
	
}

/////////////////////////////////////////////////////////////////////

void logic(){
	
	bool guessed=false;
	
	for (int i=0; i < size_of_word; i++)
	{
		if (backup_word[i] == input)
		{
			guess_word[i] = input;
			guessed = true;
		}
	}
	
	if (guessed == false && started == true)
	{
		man = man + 1;
	}
	
	guessed = false;
}

/////////////////////////////////////////////////////////////////////

int checkwin(){
	
	int correct=0;
	
	for (int i=0; i < size_of_word; i++)
	{
		if (guess_word[i] == backup_word[i])
		{
			correct++;
		}
	}
	
	if (correct == size_of_word)
	{
		return 1;
	}
}

/////////////////////////////////////////////////////////////////////

void hangman_draw() {
	
	if (man == 1)
	{
		hangman[0] = '@';
	}
	
	if (man == 2)
	{
		hangman[1] = '|';
	}
	
	if (man == 3)
	{
		hangman[2] = '|';
	}
	
	if (man == 4)
	{
		hangman[3] = '/';
	}
	
	if (man == 5)
	{
		hangman[4] = '\\';
	}
	
	if (man == 6)
	{
		hangman[5] = '/';
	}
	
	if (man == 7)
	{
		hangman[6] = '\\';
	}
	
	draw();
}
/////////////////////////////////////////////////////////////////////
