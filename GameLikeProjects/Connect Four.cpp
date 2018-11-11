#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
//Connect 4 - Mihael Petrièeviæ

	
	//startup initialization
	string razmak = "					";		//razmak koji se kasnije koristi kod crtanja igre
	//polja koja se koriste za igru
	string a="-",a1="-",a2="-",a3="-",a4="-",a5="-",b="-",b1="-",b2="-",b3="-",b4="-",b5="-",c="-",c1="-",c2="-",c3="-",c4="-",c5="-",d="-",d1="-",d2="-",d3="-",d4="-",d5="-",e="-",e1="-",e2="-",e3="-",e4="-",e5="-",f="-",f1="-",f2="-",f3="-",f4="-",f5="-",g="-",g1="-",g2="-",g3="-",g4="-",g5="-";
	string player1, player2;		//uzima slovo igraca
	
	//je li neko polje vec zauzeto
	bool ua,ua1,ua2,ua3,ua4,ua5,ub,ub1,ub2,ub3,ub4,ub5,uc,uc1,uc2,uc3,uc4,uc5,ud,ud1,ud2,ud3,ud4,ud5,ue,ue1,ue2,ue3,ue4,ue5,uf,uf1,uf2,uf3,uf4,uf5,ug,ug1,ug2,ug3,ug4,ug5;
	int done=0,i=0;	     //je li igrac vec odabrao slovo i ako je nastavi i ponudi izbor igracu 2
	
	int checkwin();
	void win();
	void board();
	void reset();

int main (){
	
	//startup
	srand(time(0));
	
	//board
	board();
	
	//start of the game
	cout << "\n\n";
	cout << "Player 1 - Enter a charachter: ";		//ceka unos korisnika i sprema ga
	cin >> player1;
	
	//player1 logic && gravity
	/////////////////////////
	////////A STUPAC////////
	///////////////////////
	if (player1 == "a" && ua5 == false && done == 0)	//ako je igrac izabrao red a i ako je 5 polje to jest zadnje polje prazno i ako vec nije odigrao svoj potez stavi done u 1 i stavi njegovu oznaku na to polje
	{
		done=1;
		a5="X";
		ua5 = true;
	}
	if (player1 == "a" && ua5 == true && ua4 == false && done == 0) 
	{
		done=1;
		a4="X";
		ua4 = true;
	}
	if (player1 == "a" && ua4 == true && ua3 == false && done == 0) 
	{
		done=1;
		a3="X";
		ua3 = true;
	}
	if (player1 == "a" && ua3 == true && ua2 == false && done == 0) 
	{
		done=1;
		a2="X";
		ua2 = true;
	}
	if (player1 == "a" && ua2 == true && ua1 == false && done == 0) 
	{
		done=1;
		a1="X";
		ua1 = true;
	}
	if (player1 == "a" && ua1 == true && ua == false && done == 0) 
	{
		done=1;
		a="X";
		ua = true;
	}
	/////////////////////////
	///////B STUPAC//////////
	/////////////////////////
	if (player1 == "b" && ub5 == false && done == 0)
	{
		done=1;
		b5="X";
		ub5 = true;
	}
	if (player1 == "b" && ub5 == true && ub4 == false && done == 0) 
	{
		done=1;
		b4="X";
		ub4 = true;
	}
	if (player1 == "b" && ub4 == true && ub3 == false && done == 0) 
	{
		done=1;
		b3="X";
		ub3 = true;
	}
	if (player1 == "b" && ub3 == true && ub2 == false && done == 0) 
	{
		done=1;
		b2="X";
		ub2 = true;
	}
	if (player1 == "b" && ub2 == true && ub1 == false && done == 0) 
	{
		done=1;
		b1="X";
		ub1 = true;
	}
	if (player1 == "b" && ub1 == true && ub == false && done == 0) 
	{
		done=1;
		b="X";
		ub = true;
	}
	/////////////////////////
	///////C STUPAC//////////
	/////////////////////////
	if (player1 == "c" && uc5 == false && done == 0)
	{
		done=1;
		c5="X";
		uc5 = true;
	}
	if (player1 == "c" && uc5 == true && uc4 == false && done == 0) 
	{
		done=1;
		c4="X";
		uc4 = true;
	}
	if (player1 == "c" && uc4 == true && uc3 == false && done == 0) 
	{
		done=1;
		c3="X";
		uc3 = true;
	}
	if (player1 == "c" && uc3 == true && uc2 == false && done == 0) 
	{
		done=1;
		c2="X";
		uc2 = true;
	}
	if (player1 == "c" && uc2 == true && uc1 == false && done == 0) 
	{
		done=1;
		c1="X";
		uc1 = true;
	}
	if (player1 == "c" && uc1 == true && uc == false && done == 0) 
	{
		done=1;
		c="X";
		uc = true;
	}
	/////////////////////////
	///////D STUPAC//////////
	/////////////////////////
	if (player1 == "d" && ud5 == false && done == 0)
	{
		done=1;
		d5="X";
		ud5 = true;
	}
	if (player1 == "d" && ud5 == true && ud4 == false && done == 0) 
	{
		done=1;
		d4="X";
		ud4 = true;
	}
	if (player1 == "d" && ud4 == true && ud3 == false && done == 0) 
	{
		done=1;
		d3="X";
		ud3 = true;
	}
	if (player1 == "d" && ud3 == true && ud2 == false && done == 0) 
	{
		done=1;
		d2="X";
		ud2 = true;
	}
	if (player1 == "d" && ud2 == true && ud1 == false && done == 0) 
	{
		done=1;
		d1="X";
		ud1 = true;
	}
	if (player1 == "d" && ud1 == true && ud == false && done == 0) 
	{
		done=1;
		d="X";
		ud = true;
	}
	/////////////////////////
	///////E STUPAC//////////
	/////////////////////////
	if (player1 == "e" && ue5 == false && done == 0)
	{
		done=1;
		e5="X";
		ue5 = true;
	}
	if (player1 == "e" && ue5 == true && ue4 == false && done == 0) 
	{
		done=1;
		e4="X";
		ue4 = true;
	}
	if (player1 == "e" && ue4 == true && ue3 == false && done == 0) 
	{
		done=1;
		e3="X";
		ue3 = true;
	}
	if (player1 == "e" && ue3 == true && ue2 == false && done == 0) 
	{
		done=1;
		e2="X";
		ue2 = true;
	}
	if (player1 == "e" && ue2 == true && ue1 == false && done == 0) 
	{
		done=1;
		e1="X";
		ue1 = true;
	}
	if (player1 == "e" && ue1 == true && ue == false && done == 0) 
	{
		done=1;
		e="X";
		ue = true;
	}
	/////////////////////////
	///////F STUPAC//////////
	/////////////////////////
	if (player1 == "f" && uf5 == false && done == 0)
	{
		done=1;
		f5="X";
		uf5 = true;
	}
	if (player1 == "f" && uf5 == true && uf4 == false && done == 0) 
	{
		done=1;
		f4="X";
		uf4 = true;
	}
	if (player1 == "f" && uf4 == true && uf3 == false && done == 0) 
	{
		done=1;
		f3="X";
		uf3 = true;
	}
	if (player1 == "f" && uf3 == true && uf2 == false && done == 0) 
	{
		done=1;
		f2="X";
		uf2 = true;
	}
	if (player1 == "f" && uf2 == true && uf1 == false && done == 0) 
	{
		done=1;
		f1="X";
		uf1 = true;
	}
	if (player1 == "f" && uf1 == true && uf == false && done == 0) 
	{
		done=1;
		f="X";
		uf = true;
	}
	/////////////////////////
	///////G STUPAC//////////
	/////////////////////////
	if (player1 == "g" && ug5 == false && done == 0)
	{
		done=1;
		g5="X";
		ug5 = true;
	}
	if (player1 == "g" && ug5 == true && ug4 == false && done == 0) 
	{
		done=1;
		g4="X";
		ug4 = true;
	}
	if (player1 == "g" && ug4 == true && ug3 == false && done == 0) 
	{
		done=1;
		g3="X";
		ug3 = true;
	}
	if (player1 == "g" && ug3 == true && ug2 == false && done == 0) 
	{
		done=1;
		g2="X";
		ug2 = true;
	}
	if (player1 == "g" && ug2 == true && ug1 == false && done == 0) 
	{
		done=1;
		g1="X";
		ug1 = true;
	}
	if (player1 == "g" && ug1 == true && ug == false && done == 0) 
	{
		done=1;
		g="X";
		ug = true;
	}
	
	done = 0;
	checkwin();
	win();
	system("cls");
	//end of player 1 logic
	
	board();
	
	cout << "\n\n";
	cout << "Player 2 - Enter a charachter: ";
	cin >> player2;
	
	//player2 logic
	/////////////////////////
	////////A STUPAC////////
	///////////////////////
	if (player2 == "a" && ua5 == false && done == 0)
	{
		done=1;
		a5="O";
		ua5 = true;
	}
	if (player2 == "a" && ua5 == true && ua4 == false && done == 0) 
	{
		done=1;
		a4="O";
		ua4 = true;
	}
	if (player2 == "a" && ua4 == true && ua3 == false && done == 0) 
	{
		done=1;
		a3="O";
		ua3 = true;
	}
	if (player2 == "a" && ua3 == true && ua2 == false && done == 0) 
	{
		done=1;
		a2="O";
		ua2 = true;
	}
	if (player2 == "a" && ua2 == true && ua1 == false && done == 0) 
	{
		done=1;
		a1="O";
		ua1 = true;
	}
	if (player2 == "a" && ua1 == true && ua == false && done == 0) 
	{
		done=1;
		a="O";
		ua = true;
	}
	/////////////////////////
	///////B STUPAC//////////
	/////////////////////////
	if (player2 == "b" && ub5 == false && done == 0)
	{
		done=1;
		b5="O";
		ub5 = true;
	}
	if (player2 == "b" && ub5 == true && ub4 == false && done == 0) 
	{
		done=1;
		b4="O";
		ub4 = true;
	}
	if (player2 == "b" && ub4 == true && ub3 == false && done == 0) 
	{
		done=1;
		b3="O";
		ub3 = true;
	}
	if (player2 == "b" && ub3 == true && ub2 == false && done == 0) 
	{
		done=1;
		b2="O";
		ub2 = true;
	}
	if (player2 == "b" && ub2 == true && ub1 == false && done == 0) 
	{
		done=1;
		b1="O";
		ub1 = true;
	}
	if (player2 == "b" && ub1 == true && ub == false && done == 0) 
	{
		done=1;
		b="O";
		ub = true;
	}
	/////////////////////////
	///////C STUPAC//////////
	/////////////////////////
	if (player2 == "c" && uc5 == false && done == 0)
	{
		done=1;
		c5="O";
		uc5 = true;
	}
	if (player2 == "c" && uc5 == true && uc4 == false && done == 0) 
	{
		done=1;
		c4="O";
		uc4 = true;
	}
	if (player2 == "c" && uc4 == true && uc3 == false && done == 0) 
	{
		done=1;
		c3="O";
		uc3 = true;
	}
	if (player2 == "c" && uc3 == true && uc2 == false && done == 0) 
	{
		done=1;
		c2="O";
		uc2 = true;
	}
	if (player2 == "c" && uc2 == true && uc1 == false && done == 0) 
	{
		done=1;
		c1="O";
		uc1 = true;
	}
	if (player2 == "c" && uc1 == true && uc == false && done == 0) 
	{
		done=1;
		c="O";
		uc = true;
	}
	/////////////////////////
	///////D STUPAC//////////
	/////////////////////////
	if (player2 == "d" && ud5 == false && done == 0)
	{
		done=1;
		d5="O";
		ud5 = true;
	}
	if (player2 == "d" && ud5 == true && ud4 == false && done == 0) 
	{
		done=1;
		d4="O";
		ud4 = true;
	}
	if (player2 == "d" && ud4 == true && ud3 == false && done == 0) 
	{
		done=1;
		d3="O";
		ud3 = true;
	}
	if (player2 == "d" && ud3 == true && ud2 == false && done == 0) 
	{
		done=1;
		d2="O";
		ud2 = true;
	}
	if (player2 == "d" && ud2 == true && ud1 == false && done == 0) 
	{
		done=1;
		d1="O";
		ud1 = true;
	}
	if (player2 == "d" && ud1 == true && ud == false && done == 0) 
	{
		done=1;
		d="O";
		ud = true;
	}
	/////////////////////////
	///////E STUPAC//////////
	/////////////////////////
	if (player2 == "e" && ue5 == false && done == 0)
	{
		done=1;
		e5="O";
		ue5 = true;
	}
	if (player2 == "e" && ue5 == true && ue4 == false && done == 0) 
	{
		done=1;
		e4="O";
		ue4 = true;
	}
	if (player2 == "e" && ue4 == true && ue3 == false && done == 0) 
	{
		done=1;
		e3="O";
		ue3 = true;
	}
	if (player2 == "e" && ue3 == true && ue2 == false && done == 0) 
	{
		done=1;
		e2="O";
		ue2 = true;
	}
	if (player2 == "e" && ue2 == true && ue1 == false && done == 0) 
	{
		done=1;
		e1="O";
		ue1 = true;
	}
	if (player2 == "e" && ue1 == true && ue == false && done == 0) 
	{
		done=1;
		e="O";
		ue = true;
	}
	/////////////////////////
	///////F STUPAC//////////
	/////////////////////////
	if (player2 == "f" && uf5 == false && done == 0)
	{
		done=1;
		f5="O";
		uf5 = true;
	}
	if (player2 == "f" && uf5 == true && uf4 == false && done == 0) 
	{
		done=1;
		f4="O";
		uf4 = true;
	}
	if (player2 == "f" && uf4 == true && uf3 == false && done == 0) 
	{
		done=1;
		f3="O";
		uf3 = true;
	}
	if (player2 == "f" && uf3 == true && uf2 == false && done == 0) 
	{
		done=1;
		f2="O";
		uf2 = true;
	}
	if (player2 == "f" && uf2 == true && uf1 == false && done == 0) 
	{
		done=1;
		f1="O";
		uf1 = true;
	}
	if (player2 == "f" && uf1 == true && uf == false && done == 0) 
	{
		done=1;
		f="O";
		uf = true;
	}
	/////////////////////////
	///////G STUPAC//////////
	/////////////////////////
	if (player2 == "g" && ug5 == false && done == 0)
	{
		done=1;
		g5="O";
		ug5 = true;
	}
	if (player2 == "g" && ug5 == true && ug4 == false && done == 0) 
	{
		done=1;
		g4="O";
		ug4 = true;
	}
	if (player2 == "g" && ug4 == true && ug3 == false && done == 0) 
	{
		done=1;
		g3="O";
		ug3 = true;
	}
	if (player2 == "g" && ug3 == true && ug2 == false && done == 0) 
	{
		done=1;
		g2="O";
		ug2 = true;
	}
	if (player2 == "g" && ug2 == true && ug1 == false && done == 0) 
	{
		done=1;
		g1="O";
		ug1 = true;
	}
	if (player2 == "g" && ug1 == true && ug == false && done == 0) 
	{
		done=1;
		g="O";
		ug = true;
	}
	
	done = 0;
	
	checkwin();
	win();
	system("cls");
	//end of player2 logic
	
	main();		//resets the choice and runs the code again
	
}

	void board(){
	
	cout << "\n\n\n";	
	cout << razmak << "          Connect 4\n";
	cout << "\n\n\n";
	
	cout << razmak << "  a   b   c   d   e   f   g" << endl;
	cout << razmak << "|" << "[" << a << "]" << "|" << "[" << b << "]" << "|" << "[" << c << "]" << "|" << "[" << d << "]" << "|" << "[" << e << "]" << "|" << "[" << f << "]" << "|" << "[" << g << "]" << "|" << endl;
	cout << razmak << "|" << "[" << a1 << "]" << "|" << "[" << b1 << "]" << "|" << "[" << c1 << "]" << "|" << "[" << d1 << "]" << "|" << "[" << e1 << "]" << "|" << "[" << f1 << "]" << "|" << "[" << g1 << "]" << "|" << endl;
	cout << razmak << "|" << "[" << a2 << "]" << "|" << "[" << b2 << "]" << "|" << "[" << c2 << "]" << "|" << "[" << d2 << "]" << "|" << "[" << e2 << "]" << "|" << "[" << f2 << "]" << "|" << "[" << g2 << "]" << "|" << endl;
	cout << razmak << "|" << "[" << a3 << "]" << "|" << "[" << b3 << "]" << "|" << "[" << c3 << "]" << "|" << "[" << d3 << "]" << "|" << "[" << e3 << "]" << "|" << "[" << f3 << "]" << "|" << "[" << g3 << "]" << "|" << endl;
	cout << razmak << "|" << "[" << a4 << "]" << "|" << "[" << b4 << "]" << "|" << "[" << c4 << "]" << "|" << "[" << d4 << "]" << "|" << "[" << e4 << "]" << "|" << "[" << f4 << "]" << "|" << "[" << g4 << "]" << "|" << endl;
	cout << razmak << "|" << "[" << a5 << "]" << "|" << "[" << b5 << "]" << "|" << "[" << c5 << "]" << "|" << "[" << d5 << "]" << "|" << "[" << e5 << "]" << "|" << "[" << f5 << "]" << "|" << "[" << g5 << "]" << "|" << endl;

	}
	
	int checkwin(){
		
		//player1
		if (a5 == "X" && a4 == "X" && a3 == "X" && a2 == "X")
			return 1;
		else if (a4 == "X" && a3 == "X" && a2 == "X" && a1 == "X")
			return 1;
		else if (a3 == "X" && a2 == "X" && a1 == "X" && a == "X")
			return 1;
		else if (b5 == "X" && b4 == "X" && b3 == "X" && b2 == "X")
			return 1;
		else if (b4 == "X" && b3 == "X" && b2 == "X" && b1 == "X")
			return 1;
		else if (b3 == "X" && b2 == "X" && b1 == "X" && b == "X")
			return 1;
		else if (c5 == "X" && c4 == "X" && c3 == "X" && c2 == "X")
			return 1;
		else if (c4 == "X" && c3 == "X" && c2 == "X" && c1 == "X")
			return 1;
		else if (c3 == "X" && c2 == "X" && c1 == "X" && c == "X")
			return 1;
		else if (d5 == "X" && d4 == "X" && d3 == "X" && d2 == "X")
			return 1;
		else if (d4 == "X" && d3 == "X" && d2 == "X" && d1 == "X")
			return 1;
		else if (d3 == "X" && d2 == "X" && d1 == "X" && d == "X")
			return 1;
		else if (e5 == "X" && e4 == "X" && e3 == "X" && e2 == "X")
			return 1;
		else if (e4 == "X" && e3 == "X" && e2 == "X" && e1 == "X")
			return 1;
		else if (e3 == "X" && e2 == "X" && e1 == "X" && e  == "X")
			return 1;
		else if (f5 == "X" && f4 == "X" && f3 == "X" && f2 == "X")
			return 1;
		else if (f4 == "X" && f3 == "X" && f2 == "X" && f == "X")
			return 1;
		else if (g5 == "X" && g4 == "X" && g3 == "X" && g2 == "X")
			return 1;
		else if (g4 == "X" && g3 == "X" && g2 == "X" && g1 == "X")
			return 1;
		else if (g3 == "X" && g2 == "X" && g1 == "X" && g == "X")
			return 1;
		else if  (a5 == "X" && b5 == "X" && c5 == "X" && d5 == "X")
			return 1;
		else if (b5 == "X" && c5 == "X" && d5 == "X" && e5 == "X")
			return 1;
		else if (c5 == "X" && d5 == "X" && e5 == "X" && f5 == "X")
			return 1;
		else if (d5 == "X" && e5 == "X" && f5 == "X" && g5 == "X")
			return 1;
		else if  (a4 == "X" && b4 == "X" && c4 == "X" && d4 == "X")
			return 1;
		else if (b4 == "X" && c4 == "X" && d4 == "X" && e4 == "X")
			return 1;
		else if (c4 == "X" && d4 == "X" && e4 == "X" && f4 == "X")
			return 1;
		else if (d4 == "X" && e4 == "X" && f4 == "X" && g4 == "X")
			return 1;
		else if  (a3 == "X" && b3 == "X" && c3 == "X" && d3 == "X")
			return 1;
		else if (b3 == "X" && c3 == "X" && d3 == "X" && e3 == "X")
			return 1;
		else if (c3 == "X" && d3 == "X" && e3 == "X" && f3 == "X")
			return 1;
		else if (d3 == "X" && e3 == "X" && f3 == "X" && g3 == "X")
			return 1;
		else if  (a2 == "X" && b2 == "X" && c2 == "X" && d2 == "X")
			return 1;
		else if (b2 == "X" && c2 == "X" && d2 == "X" && e2 == "X")
			return 1;
		else if (c2 == "X" && d2 == "X" && e2 == "X" && f2 == "X")
			return 1;
		else if (d2 == "X" && e2 == "X" && f2 == "X" && g2 == "X")
			return 1;
		else if  (a1 == "X" && b1 == "X" && c1 == "X" && d1 == "X")
			return 1;
		else if (b1 == "X" && c1 == "X" && d1 == "X" && e1 == "X")
			return 1;
		else if (c1 == "X" && d1 == "X" && e1 == "X" && f1 == "X")
			return 1;
		else if (d1 == "X" && e1 == "X" && f1 == "X" && g1 == "X")
			return 1;	
		else if  (a == "X" && b == "X" && c == "X" && d == "X")
			return 1;
		else if (b == "X" && c == "X" && d == "X" && e == "X")
			return 1;
		else if (c == "X" && d == "X" && e == "X" && f == "X")
			return 1;
		else if (d == "X" && e == "X" && f == "X" && g == "X")
			return 1;
		else if (a5 == "X" && b4 == "X" && c3 == "X" && d2 == "X")
			return 1;
		else if (b4 == "X" && c3 == "X" && d2 == "X" && e1 == "X")
			return 1;
		else if (c3 == "X" && d2 == "X" && e1 == "X" && f == "X")
			return 1;
		else if (g5 == "X" && f4 == "X" && e3 == "X" && d2 == "X")
			return 1;
		else if (f4 == "X" && e3 == "X" && d2 == "X" && c1 == "X")
			return 1;
		else if (e3 == "X" && d2 == "X" && c1 == "X" && b == "X")
			return 1;
		else if (b5 == "X" && c4 == "X" && d3 == "X" && e2 == "X")
			return 1;
		else if (c4 == "X" && d3 == "X" && e2 == "X" && f1 == "X")
			return 1;
		else if (d3 == "X" && e2 == "X" && f1 == "X" && g == "X")
			return 1;
		else if (f5 == "X" && e4 == "X" && d3 == "X" && c2 == "X")
			return 1;
		else if (e4 == "X" && d3 == "X" && c2 == "X" && b1 == "X")
			return 1;
		else if (d3 == "X" && c2 == "X" && b1 == "X" && a == "X")
			return 1;
		else if (c5 == "X" && d4 == "X" && e3 == "X" && f2 == "X")
			return 1;
		else if (d4 == "X" && e3 == "X" && f2 == "X" && g1 == "X")
			return 1;
		else if (e5 == "X" && d4 == "X" && c3 == "X" && b2 == "X")
			return 1;
		else if (d4 == "X" && c3 == "X" && b2 == "X" && a1 == "X")
			return 1;
		else if (d5 == "X" && e4 == "X" && f3 == "X" && g2 == "X")
			return 1;
		else if (d5 == "X" && c4 == "X" && b3 == "X" && a2 == "X")
			return 1;
		else if (a4 == "X" && b3 == "X" && c2 == "X" && d1 == "X")
			return 1;
		else if (b3 == "X" && c2 == "X" && d1 == "X" && e == "X")
			return 1;
		else if (g4 == "X" && f3 == "X" && e2 == "X" && d1 == "X")
			return 1;
		else if (f3 == "X" && e2 == "X" && d1 == "X" && c == "X")
			return 1;
		else if (a3 == "X" && b2 == "X" && c1 == "X" && d == "X")
			return 1;
		else if (g3 == "X" && f2 == "X" && e1 == "X" && d == "X")
			return 1;
		/////////////////////////////////////////////////////////////	
		
		//player2
		if (a5 == "O" && a4 == "O" && a3 == "O" && a2 == "O")
			return 2;
		else if (a4 == "O" && a3 == "O" && a2 == "O" && a1 == "O")
			return 2;
		else if (a3 == "O" && a2 == "O" && a1 == "O" && a == "O")
			return 2;
		else if (b5 == "O" && b4 == "O" && b3 == "O" && b2 == "O")
			return 2;
		else if (b4 == "O" && b3 == "O" && b2 == "O" && b1 == "O")
			return 2;
		else if (b3 == "O" && b2 == "O" && b1 == "O" && b == "O")
			return 2;
		else if (c5 == "O" && c4 == "O" && c3 == "O" && c2 == "O")
			return 2;
		else if (c4 == "O" && c3 == "O" && c2 == "O" && c1 == "O")
			return 2;
		else if (c3 == "O" && c2 == "O" && c1 == "O" && c == "O")
			return 2;
		else if (d5 == "O" && d4 == "O" && d3 == "O" && d2 == "O")
			return 2;
		else if (d4 == "O" && d3 == "O" && d2 == "O" && d1 == "O")
			return 2;
		else if (d3 == "O" && d2 == "O" && d1 == "O" && d == "O")
			return 2;
		else if (e5 == "O" && e4 == "O" && e3 == "O" && e2 == "O")
			return 2;
		else if (e4 == "O" && e3 == "O" && e2 == "O" && e1 == "O")
			return 2;
		else if (e3 == "O" && e2 == "O" && e1 == "O" && e  == "O")
			return 2;
		else if (f5 == "O" && f4 == "O" && f3 == "O" && f2 == "O")
			return 2;
		else if (f4 == "O" && f3 == "O" && f2 == "O" && f == "O")
			return 2;
		else if (g5 == "O" && g4 == "O" && g3 == "O" && g2 == "O")
			return 2;
		else if (g4 == "O" && g3 == "O" && g2 == "O" && g1 == "O")
			return 2;
		else if (g3 == "O" && g2 == "O" && g1 == "O" && g == "O")
			return 2;
		else if  (a5 == "O" && b5 == "O" && c5 == "O" && d5 == "O")
			return 2;
		else if (b5 == "O" && c5 == "O" && d5 == "O" && e5 == "O")
			return 2;
		else if (c5 == "O" && d5 == "O" && e5 == "O" && f5 == "O")
			return 2;
		else if (d5 == "O" && e5 == "O" && f5 == "O" && g5 == "O")
			return 2;
		else if  (a4 == "O" && b4 == "O" && c4 == "O" && d4 == "O")
			return 2;
		else if (b4 == "O" && c4 == "O" && d4 == "O" && e4 == "O")
			return 2;
		else if (c4 == "O" && d4 == "O" && e4 == "O" && f4 == "O")
			return 2;
		else if (d4 == "O" && e4 == "O" && f4 == "O" && g4 == "O")
			return 2;
		else if  (a3 == "O" && b3 == "O" && c3 == "O" && d3 == "O")
			return 2;
		else if (b3 == "O" && c3 == "O" && d3 == "O" && e3 == "O")
			return 2;
		else if (c3 == "O" && d3 == "O" && e3 == "O" && f3 == "O")
			return 2;
		else if (d3 == "O" && e3 == "O" && f3 == "O" && g3 == "O")
			return 2;
		else if  (a2 == "O" && b2 == "O" && c2 == "O" && d2 == "O")
			return 2;
		else if (b2 == "O" && c2 == "O" && d2 == "O" && e2 == "O")
			return 2;
		else if (c2 == "O" && d2 == "O" && e2 == "O" && f2 == "O")
			return 2;
		else if (d2 == "O" && e2 == "O" && f2 == "O" && g2 == "O")
			return 2;
		else if  (a1 == "O" && b1 == "O" && c1 == "O" && d1 == "O")
			return 2;
		else if (b1 == "O" && c1 == "O" && d1 == "O" && e1 == "O")
			return 2;
		else if (c1 == "O" && d1 == "O" && e1 == "O" && f1 == "O")
			return 2;
		else if (d1 == "O" && e1 == "O" && f1 == "O" && g1 == "O")
			return 2;	
		else if  (a == "O" && b == "O" && c == "O" && d == "O")
			return 2;
		else if (b == "O" && c == "O" && d == "O" && e == "O")
			return 2;
		else if (c == "O" && d == "O" && e == "O" && f == "O")
			return 2;
		else if (d == "O" && e == "O" && f == "O" && g == "O")
			return 2;
		else if (a5 == "O" && b4 == "O" && c3 == "O" && d2 == "O")
			return 2;
		else if (b4 == "O" && c3 == "O" && d2 == "O" && e1 == "O")
			return 2;
		else if (c3 == "O" && d2 == "O" && e1 == "O" && f == "O")
			return 2;
		else if (g5 == "O" && f4 == "O" && e3 == "O" && d2 == "O")
			return 2;
		else if (f4 == "O" && e3 == "O" && d2 == "O" && c1 == "O")
			return 2;
		else if (e3 == "O" && d2 == "O" && c1 == "O" && b == "O")
			return 2;
		else if (b5 == "O" && c4 == "O" && d3 == "O" && e2 == "O")
			return 2;
		else if (c4 == "O" && d3 == "O" && e2 == "O" && f1 == "O")
			return 2;
		else if (d3 == "O" && e2 == "O" && f1 == "O" && g == "O")
			return 2;
		else if (f5 == "O" && e4 == "O" && d3 == "O" && c2 == "O")
			return 2;
		else if (e4 == "O" && d3 == "O" && c2 == "O" && b1 == "O")
			return 2;
		else if (d3 == "O" && c2 == "O" && b1 == "O" && a == "O")
			return 2;
		else if (c5 == "O" && d4 == "O" && e3 == "O" && f2 == "O")
			return 2;
		else if (d4 == "O" && e3 == "O" && f2 == "O" && g1 == "O")
			return 2;
		else if (e5 == "O" && d4 == "O" && c3 == "O" && b2 == "O")
			return 2;
		else if (d4 == "O" && c3 == "O" && b2 == "O" && a1 == "O")
			return 2;
		else if (d5 == "O" && e4 == "O" && f3 == "O" && g2 == "O")
			return 2;
		else if (d5 == "O" && c4 == "O" && b3 == "O" && a2 == "O")
			return 2;
		else if (a4 == "O" && b3 == "O" && c2 == "O" && d1 == "O")
			return 2;
		else if (b3 == "O" && c2 == "O" && d1 == "O" && e == "O")
			return 2;
		else if (g4 == "O" && f3 == "O" && e2 == "O" && d1 == "O")
			return 2;
		else if (f3 == "O" && e2 == "O" && d1 == "O" && c == "O")
			return 2;
		else if (a3 == "O" && b2 == "O" && c1 == "O" && d == "O")
			return 2;
		else if (g3 == "O" && f2 == "O" && e1 == "O" && d == "O")
			return 2;
		/////////////////////////////////////////////////////////////
	}
	
	void win(){		//ako je checkwin vratio 1 onda je prvi igrac pobijedio inace je drugi igrac pobijedio
		
	i = checkwin();		//i prima iznos koji daje checkwin i moze iznositi samo 1 ili 2
	
	if (i == 1)
	{
		system("cls");
		cout << "Player 1 Wins!!!" << endl;
		board();
		system("pause");
		system("cls");
		reset();
		main();
	}
	else if (i == 2)
	{
		system("cls");
		cout << "Player 2 Wins!!!" << endl;
		board();
		system("pause");
		system("cls");
		reset();
		main();
	}
}

	void reset(){		//resetira sve varijable
		
		i = 0;
		done = 0;
		a = "-";a1 = "-";a2 = "-";a3 = "-";a4 = "-";a5 = "-";
		b = "-";b1 = "-";b2 = "-";b3 = "-";b4 = "-";b5 = "-";
		c = "-";c1 = "-";c2 = "-";c3 = "-";c4 = "-";c5 = "-";
		d = "-";d1 = "-";d2 = "-";d3 = "-";d4 = "-";d5 = "-";
		e = "-";e1 = "-";e2 = "-";e3 = "-";e4 = "-";e5 = "-";
		f = "-";f1 = "-";f2 = "-";f3 = "-";f4 = "-";f5 = "-";
		g = "-";g1 = "-";g2 = "-";g3 = "-";g4 = "-";g5 = "-";
		
		ua = false;ua1 = false;ua2 = false;ua3 = false;ua4 = false;ua5 = false;
		ub = false;ub1 = false;ub2 = false;ub3 = false;ub4 = false;ub5 = false;
		uc = false;uc1 = false;uc2 = false;uc3 = false;uc4 = false;uc5 = false;
		ud = false;ud1 = false;ud2 = false;ud3 = false;ud4 = false;ud5 = false;
		ue = false;ue1 = false;ue2 = false;ue3 = false;ue4 = false;ue5 = false;
		uf = false;uf1 = false;uf2 = false;uf3 = false;uf4 = false;uf5 = false;
		ug = false;ug1 = false;ug2 = false;ug3 = false;ug4 = false;ug5 = false;
	}
