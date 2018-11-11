#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
//Potapljanje brodova - Mihael Petrièeviæ

	
	//startup
	void startup(){
	srand(time(0));
	bool player1,player2;
	bool br3potopljen1,br2potopljen1,br1potopljen1;
	bool br3potopljen2,br2potopljen2,br1potopljen2;
	int l3ife2,l2ife2,l1ife2,l3ife1,l2ife1,l1ife1;
	string napad1,napad2;
	string b3rod1,b2rod1,b1rod1;	//brodovi prvog igraèa
	string b3rod2,b2rod2,b1rod2;	//brodovi drugog igraèa
	string A1,B1,C1,D1,E1,F1,G1,H1,I1,A2,B2,C2,D2,E2,F2,G2,H2,I2,A3,B3,C3,D3,E3,F3,G3,H3,I3,A4,B4,C4,D4,E4,F4,G4,H4,I4;
	string A5,B5,C5,D5,E5,F5,G5,H5,I5,A6,B6,C6,D6,E6,F6,G6,H6,I6,A7,B7,C7,D7,E7,F7,G7,H7,I7;
	string razmak = "					";
	string a1,b1,c1,d1,e1,f1,g1,h1,i1,a2,b2,c2,d2,e2,f2,g2,h2,i2,a3,b3,c3,d3,e3,f3,g3,h3,i3,a4,b4,c4,d4,e4,f4,g4,h4,i4;
	string a5,b5,c5,d5,e5,f5,g5,h5,i5,a6,b6,c6,d6,e6,f6,g6,h6,i6,a7,b7,c7,d7,e7,f7,g7,h7,i7;
}

	//draw board1
	void board1(){
	cout << "\n\n\n";	
	cout << razmak << "# A" << " B" << " C" << " D" << " E" << " F" << " G" << " H" << " I" << endl;
	cout << razmak << "1 " << A1 << B1 << C1 << D1 << E1 << F1 << G1 << H1 << I1 << endl;
	cout << razmak << "2 " << A2 << B2 << C2 << D2 << E2 << F2 << G2 << H2 << I2 << endl;
	cout << razmak << "3 " << A3 << B3 << C3 << D3 << E3 << F3 << G3 << H3 << I3 << endl;
	cout << razmak << "4 " << A4 << B4 << C4 << D4 << E4 << F4 << G4 << H4 << I4 << endl;
	cout << razmak << "5 " << A5 << B5 << C5 << D5 << E5 << F5 << G5 << H5 << I5 << endl;
	cout << razmak << "6 " << A6 << B6 << C6 << D6 << E6 << F6 << G6 << H6 << I6 << endl;
	cout << razmak << "7 " << A7 << B7 << C7 << D7 << E7 << F7 << G7 << H7 << I7 << endl;
	}

	//draw board2
	void board2(){
	cout << "\n\n\n";	
	cout << razmak << "# A" << " B" << " C" << " D" << " E" << " F" << " G" << " H" << " I" << endl;
	cout << razmak << "1 " << a1 << b1 << c1 << d1 << e1 << f1 << g1 << h1 << i1 << endl;
	cout << razmak << "2 " << a2 << b2 << c2 << d2 << e2 << f2 << g2 << h2 << i2 << endl;
	cout << razmak << "3 " << a3 << b3 << c3 << d3 << e3 << f3 << g3 << h3 << i3 << endl;
	cout << razmak << "4 " << a4 << b4 << c4 << d4 << e4 << f4 << g4 << h4 << i4 << endl;
	cout << razmak << "5 " << a5 << b5 << c5 << d5 << e5 << f5 << g5 << h5 << i5 << endl;
	cout << razmak << "6 " << a6 << b6 << c6 << d6 << e6 << f6 << g6 << h6 << i6 << endl;
	cout << razmak << "7 " << a7 << b7 << c7 << d7 << e7 << f7 << g7 << h7 << i7 << endl;
	}
	
	//default board layout
	void board(){
	cout << "\n\n\n";	
	cout << razmak << "# A" << " B" << " C" << " D" << " E" << " F" << " G" << " H" << " I" << endl;
	cout << razmak << "1 " << A1 << B1 << C1 << D1 << E1 << F1 << G1 << H1 << I1 << endl;
	cout << razmak << "2 " << A2 << B2 << C2 << D2 << E2 << F2 << G2 << H2 << I2 << endl;
	cout << razmak << "3 " << A3 << B3 << C3 << D3 << E3 << F3 << G3 << H3 << I3 << endl;
	cout << razmak << "4 " << A4 << B4 << C4 << D4 << E4 << F4 << G4 << H4 << I4 << endl;
	cout << razmak << "5 " << A5 << B5 << C5 << D5 << E5 << F5 << G5 << H5 << I5 << endl;
	cout << razmak << "6 " << A6 << B6 << C6 << D6 << E6 << F6 << G6 << H6 << I6 << endl;
	cout << razmak << "7 " << A7 << B7 << C7 << D7 << E7 << F7 << G7 << H7 << I7 << endl;
}



int main() {
	
	//startup
	startup();
	
	//initialization
	A1 = "  ";B1 = "  ";C1 = "  ";D1 = "  ";E1 = "  ";F1 = "  ";G1 = "  ";H1 = "  ";I1 = "  ";
	A2 = "  ";B2 = "  ";C2 = "  ";D2 = "  ";E2 = "  ";F2 = "  ";G2 = "  ";H2 = "  ";I2 = "  ";
	A3 = "  ";B3 = "  ";C3 = "  ";D3 = "  ";E3 = "  ";F3 = "  ";G3 = "  ";H3 = "  ";I3 = "  ";
	A4 = "  ";B4 = "  ";C4 = "  ";D4 = "  ";E4 = "  ";F4 = "  ";G4 = "  ";H4 = "  ";I4 = "  ";
	A5 = "  ";B5 = "  ";C5 = "  ";D5 = "  ";E5 = "  ";F5 = "  ";G5 = "  ";H5 = "  ";I5 = "  ";
	A6 = "  ";B6 = "  ";C6 = "  ";D6 = "  ";E6 = "  ";F6 = "  ";G6 = "  ";H6 = "  ";I6 = "  ";
	A7 = "  ";B7 = "  ";C7 = "  ";D7 = "  ";E7 = "  ";F7 = "  ";G7 = "  ";H7 = "  ";I7 = "  ";
	
	a1 = " ";b1 = " ";c1 = " ";d1 = " ";e1 = " ";f1 = " ";g1 = " ";h1 = " ";i1 = " ";
	a2 = " ";b2 = " ";c2 = " ";d2 = " ";e2 = " ";f2 = " ";g2 = " ";h2 = " ";i2 = " ";
	a3 = " ";b3 = " ";c3 = " ";d3 = " ";e3 = " ";f3 = " ";g3 = " ";h3 = " ";i3 = " ";
	a4 = " ";b4 = " ";c4 = " ";d4 = " ";e4 = " ";f4 = " ";g4 = " ";h4 = " ";i4 = " ";
	a5 = " ";b5 = " ";c5 = " ";d5 = " ";e5 = " ";f5 = " ";g5 = " ";h5 = " ";i5 = " ";
	a6 = " ";b6 = " ";c6 = " ";d6 = " ";e6 = " ";f6 = " ";g6 = " ";h6 = " ";i6 = " ";
	a7 = " ";b7 = " ";c7 = " ";d7 = " ";e7 = " ";f7 = " ";g7 = " ";h7 = " ";i7 = " ";
	
	br3potopljen1 = 3;
	br2potopljen1 = 2;
	br1potopljen1 = 1;
	
	br3potopljen2 = 3;
	br2potopljen2 = 2;
	br1potopljen2 = 1;

	//start of the game
	board(;)
	cout << "\n\n" << "Neka polja budu napisana ovako npr. A1" << endl << "Player1: " << "Unesi gdje zelis da ti bude brod 3 polja duzine: ";
	cin >> b3rod1;
	cout << "\n" << "Unesi gdje zelis da ti bude broj 2 polja duzine: ";
	cin >> b2rod1; 
	cout << "\n" << "Unesi gdje zelis da ti bude broj 1 polja duzine: ";
	cin >> b1rod1; 
	
	system("cls");
	board();
	
	cout << "\n\n" << "Neka polja budu napisana ovako npr. A1" << endl << "Player2: " << "Unesi gdje zelis da ti bude brod 3 polja duzine: ";
	cin >> b3rod2;
	cout << "\n" << "Unesi gdje zelis da ti bude broj 2 polja duzine: ";
	cin >> b2rod2; 
	cout << "\n" << "Unesi gdje zelis da ti bude broj 1 polja duzine: ";
	cin >> b1rod2; 
	
	system("cls");
	cout << "Player1 turn!" << endl;
	system("pause");
	
	//Location of the boats	
	//PLAYER 1
	//brod od 3 polja
	if (b3rod1 == "B1"){A1 = "<o";B1 = "o";C1 = "o>"; start=1;}
	if (b3rod1 == "C1"){B1 = "<o";C1 = "o";D1 = "o>"; start=1;}
	if (b3rod1 == "D1"){C1 = "<o";D1 = "o";E1 = "o>"; start=1;}
	if (b3rod1 == "E1"){D1 = "<o";E1 = "o";F1 = "o>"; start=1;}
	if (b3rod1 == "F1"){E1 = "<o";F1 = "o";G1 = "o>"; start=1;}
	if (b3rod1 == "G1"){F1 = "<o";G1 = "o";H1 = "o>"; start=1;}
	if (b3rod1 == "H1"){G1 = "<o";H1 = "o";I1 = "o>"; start=1;}
	
	if (b3rod1 == "B2"){A2 = "<o";B2 = "o";C2 = "o>"; start=1;}
	if (b3rod1 == "C2"){B2 = "<o";C2 = "o";D2 = "o>"; start=1;}
	if (b3rod1 == "D2"){C2 = "<o";D2 = "o";E2 = "o>"; start=1;}
	if (b3rod1 == "E2"){D2 = "<o";E2 = "o";F2 = "o>"; start=1;}
	if (b3rod1 == "F2"){E2 = "<o";F2 = "o";G2 = "o>"; start=1;}
	if (b3rod1 == "G2"){F2 = "<o";G2 = "o";H2 = "o>"; start=1;}
	if (b3rod1 == "H2"){G2 = "<o";H2 = "o";I2 = "o>"; start=1;}
	
	if (b3rod1 == "B3"){A3 = "<o";B3 = "o";C3 = "o>"; start=1;}
	if (b3rod1 == "C3"){B3 = "<o";C3 = "o";D3 = "o>"; start=1;}
	if (b3rod1 == "D3"){C3 = "<o";D3 = "o";E3 = "o>"; start=1;}
	if (b3rod1 == "E3"){D3 = "<o";E3 = "o";F3 = "o>"; start=1;}
	if (b3rod1 == "F3"){E3 = "<o";F3 = "o";G3 = "o>"; start=1;}
	if (b3rod1 == "G3"){F3 = "<o";G3 = "o";H3 = "o>"; start=1;}
	if (b3rod1 == "H3"){G3 = "<o";H3 = "o";I3 = "o>"; start=1;}
	
	if (b3rod1 == "B4"){A4 = "<o";B4 = "o";C4 = "o>"; start=1;}
	if (b3rod1 == "C4"){B4 = "<o";C4 = "o";D4 = "o>"; start=1;}
	if (b3rod1 == "D4"){C4 = "<o";D4 = "o";E4 = "o>"; start=1;}
	if (b3rod1 == "E4"){D4 = "<o";E4 = "o";F4 = "o>"; start=1;}
	if (b3rod1 == "F4"){E4 = "<o";F4 = "o";G4 = "o>"; start=1;}
	if (b3rod1 == "G4"){F4 = "<o";G4 = "o";H4 = "o>"; start=1;}
	if (b3rod1 == "H4"){G4 = "<o";H4 = "o";I4 = "o>"; start=1;}
	
	if (b3rod1 == "B5"){A5 = "<o";B5 = "o";C5 = "o>"; start=1;}
	if (b3rod1 == "C5"){B5 = "<o";C5 = "o";D5 = "o>"; start=1;}
	if (b3rod1 == "D5"){C5 = "<o";D5 = "o";E5 = "o>"; start=1;}
	if (b3rod1 == "E5"){D5 = "<o";E5 = "o";F5 = "o>"; start=1;}
	if (b3rod1 == "F5"){E5 = "<o";F5 = "o";G5 = "o>"; start=1;}
	if (b3rod1 == "G5"){F5 = "<o";G5 = "o";H5 = "o>"; start=1;}
	if (b3rod1 == "H5"){G5 = "<o";H5 = "o";I5 = "o>"; start=1;}
	
	if (b3rod1 == "B6"){A6 = "<o";B6 = "o";C6 = "o>"; start=1;}
	if (b3rod1 == "C6"){B6 = "<o";C6 = "o";D6 = "o>"; start=1;}
	if (b3rod1 == "D6"){C6 = "<o";D6 = "o";E6 = "o>"; start=1;}
	if (b3rod1 == "E6"){D6 = "<o";E6 = "o";F6 = "o>"; start=1;}
	if (b3rod1 == "F6"){E6 = "<o";F6 = "o";G6 = "o>"; start=1;}
	if (b3rod1 == "G6"){F6 = "<o";G6 = "o";H6 = "o>"; start=1;}
	if (b3rod1 == "H6"){G6 = "<o";H6 = "o";I6 = "o>"; start=1;}
	
	if (b3rod1 == "B7"){A7 = "<o";B7 = "o";C7 = "o>"; start=1;}
	if (b3rod1 == "C7"){B7 = "<o";C7 = "o";D7 = "o>"; start=1;}
	if (b3rod1 == "D7"){C7 = "<o";D7 = "o";E7 = "o>"; start=1;}
	if (b3rod1 == "E7"){D7 = "<o";E7 = "o";F7 = "o>"; start=1;}
	if (b3rod1 == "F7"){E7 = "<o";F7 = "o";G7 = "o>"; start=1;}
	if (b3rod1 == "G7"){F7 = "<o";G7 = "o";H7 = "o>"; start=1;}
	if (b3rod1 == "H7"){G7 = "<o";H7 = "o";I7 = "o>"; start=1;}
	
	//brod od 2 polja
	if (b2rod1 == "A1"){A1 = "<o";B1 = "o>"; start=1;}
	if (b2rod1 == "B1"){B1 = "<o";C1 = "o>"; start=1;}
	if (b2rod1 == "C1"){C1 = "<o";D1 = "o>"; start=1;}
	if (b2rod1 == "D1"){D1 = "<o";E1 = "o>"; start=1;}
	if (b2rod1 == "E1"){E1 = "<o";F1 = "o>"; start=1;}
	if (b2rod1 == "F1"){F1 = "<o";G1 = "o>"; start=1;}
	if (b2rod1 == "G1"){G1 = "<o";H1 = "o>"; start=1;}
	if (b2rod1 == "H1"){H1 = "<o";I1 = "o>"; start=1;}
	
	if (b2rod1 == "A2"){A2 = "<o";B2 = "o>"; start=1;}
	if (b2rod1 == "B2"){B2 = "<o";C2 = "o>"; start=1;}
	if (b2rod1 == "C2"){C2 = "<o";D2 = "o>"; start=1;}
	if (b2rod1 == "D2"){D2 = "<o";E2 = "o>"; start=1;}
	if (b2rod1 == "E2"){E2 = "<o";F2 = "o>"; start=1;}
	if (b2rod1 == "F2"){F2 = "<o";G2 = "o>"; start=1;}
	if (b2rod1 == "G2"){G2 = "<o";H2 = "o>"; start=1;}
	if (b2rod1 == "H2"){H2 = "<o";I2 = "o>"; start=1;}
	
	if (b2rod1 == "A3"){A3 = "<o";B3 = "o>"; start=1;}
	if (b2rod1 == "B3"){B3 = "<o";C3 = "o>"; start=1;}
	if (b2rod1 == "C3"){C3 = "<o";D3 = "o>"; start=1;}
	if (b2rod1 == "D3"){D3 = "<o";E3 = "o>"; start=1;}
	if (b2rod1 == "E3"){E3 = "<o";F3 = "o>"; start=1;}
	if (b2rod1 == "F3"){F3 = "<o";G3 = "o>"; start=1;}
	if (b2rod1 == "G3"){G3 = "<o";H3 = "o>"; start=1;}
	if (b2rod1 == "H3"){H3 = "<o";I3 = "o>"; start=1;}
	
	if (b2rod1 == "A4"){A4 = "<o";B4 = "o>"; start=1;}
	if (b2rod1 == "B4"){B4 = "<o";C4 = "o>"; start=1;}
	if (b2rod1 == "C4"){C4 = "<o";D4 = "o>"; start=1;}
	if (b2rod1 == "D4"){D4 = "<o";E4 = "o>"; start=1;}
	if (b2rod1 == "E4"){E4 = "<o";F4 = "o>"; start=1;}
	if (b2rod1 == "F4"){F4 = "<o";G4 = "o>"; start=1;}
	if (b2rod1 == "G4"){G4 = "<o";H4 = "o>"; start=1;}
	if (b2rod1 == "H4"){H4 = "<o";I4 = "o>"; start=1;}

	if (b2rod1 == "A5"){A5 = "<o";B5 = "o>"; start=1;}
	if (b2rod1 == "B5"){B5 = "<o";C5 = "o>"; start=1;}
	if (b2rod1 == "C5"){C5 = "<o";D5 = "o>"; start=1;}
	if (b2rod1 == "D5"){D5 = "<o";E5 = "o>"; start=1;}
	if (b2rod1 == "E5"){E5 = "<o";F5 = "o>"; start=1;}
	if (b2rod1 == "F5"){F5 = "<o";G5 = "o>"; start=1;}
	if (b2rod1 == "G5"){G5 = "<o";H5 = "o>"; start=1;}
	if (b2rod1 == "H5"){H5 = "<o";I5 = "o>"; start=1;}
	
	if (b2rod1 == "A6"){A6 = "<o";B6 = "o>"; start=1;}
	if (b2rod1 == "B6"){B6 = "<o";C6 = "o>"; start=1;}
	if (b2rod1 == "C6"){C6 = "<o";D6 = "o>"; start=1;}
	if (b2rod1 == "D6"){D6 = "<o";E6 = "o>"; start=1;}
	if (b2rod1 == "E6"){E6 = "<o";F6 = "o>"; start=1;}
	if (b2rod1 == "F6"){F6 = "<o";G6 = "o>"; start=1;}
	if (b2rod1 == "G6"){G6 = "<o";H6 = "o>"; start=1;}
	if (b2rod1 == "H6"){H6 = "<o";I6 = "o>"; start=1;}
	
	if (b2rod1 == "A7"){A7 = "<o";B7 = "o>"; start=1;}
	if (b2rod1 == "B7"){B7 = "<o";C7 = "o>"; start=1;}
	if (b2rod1 == "C7"){C7 = "<o";D7 = "o>"; start=1;}
	if (b2rod1 == "D7"){D7 = "<o";E7 = "o>"; start=1;}
	if (b2rod1 == "E7"){E7 = "<o";F7 = "o>"; start=1;}
	if (b2rod1 == "F7"){F7 = "<o";G7 = "o>"; start=1;}
	if (b2rod1 == "G7"){G7 = "<o";H7 = "o>"; start=1;}
	if (b2rod1 == "H7"){H7 = "<o";I7 = "o>"; start=1;}

	//brod od 1 polja
	if (b1rod1 == "A1"){A1 = "<o>"; start=1;}
	if (b1rod1 == "B1"){B1 = "<o>"; start=1;}
	if (b1rod1 == "C1"){C1 = "<o>"; start=1;}
	if (b1rod1 == "D1"){D1 = "<o>"; start=1;}
	if (b1rod1 == "E1"){E1 = "<o>"; start=1;}
	if (b1rod1 == "F1"){F1 = "<o>"; start=1;}
	if (b1rod1 == "G1"){G1 = "<o>"; start=1;}
	if (b1rod1 == "H1"){H1 = "<o>"; start=1;}
	if (b1rod1 == "I1"){I1 = "<o>"; start=1;}
	
	if (b1rod1 == "A2"){A2 = "<o>"; start=1;}
	if (b1rod1 == "B2"){B2 = "<o>"; start=1;}
	if (b1rod1 == "C2"){C2 = "<o>"; start=1;}
	if (b1rod1 == "D2"){D2 = "<o>"; start=1;}
	if (b1rod1 == "E2"){E2 = "<o>"; start=1;}
	if (b1rod1 == "F2"){F2 = "<o>"; start=1;}
	if (b1rod1 == "G2"){G2 = "<o>"; start=1;}
	if (b1rod1 == "H2"){H2 = "<o>"; start=1;}
	if (b1rod1 == "I2"){I2 = "<o>"; start=1;}
	
	if (b1rod1 == "A3"){A3 = "<o>"; start=1;}
	if (b1rod1 == "B3"){B3 = "<o>"; start=1;}
	if (b1rod1 == "C3"){C3 = "<o>"; start=1;}
	if (b1rod1 == "D3"){D3 = "<o>"; start=1;}
	if (b1rod1 == "E3"){E3 = "<o>"; start=1;}
	if (b1rod1 == "F3"){F3 = "<o>"; start=1;}
	if (b1rod1 == "G3"){G3 = "<o>"; start=1;}
	if (b1rod1 == "H3"){H3 = "<o>"; start=1;}
	if (b1rod1 == "I3"){I3 = "<o>"; start=1;}
	
	if (b1rod1 == "A4"){A4 = "<o>"; start=1;}
	if (b1rod1 == "B4"){B4 = "<o>"; start=1;}
	if (b1rod1 == "C4"){C4 = "<o>"; start=1;}
	if (b1rod1 == "D4"){D4 = "<o>"; start=1;}
	if (b1rod1 == "E4"){E4 = "<o>"; start=1;}
	if (b1rod1 == "F4"){F4 = "<o>"; start=1;}
	if (b1rod1 == "G4"){G4 = "<o>"; start=1;}
	if (b1rod1 == "H4"){H4 = "<o>"; start=1;}
	if (b1rod1 == "I4"){I4 = "<o>"; start=1;}
	
	if (b1rod1 == "A5"){A5 = "<o>"; start=1;}
	if (b1rod1 == "B5"){B5 = "<o>"; start=1;}
	if (b1rod1 == "C5"){C5 = "<o>"; start=1;}
	if (b1rod1 == "D5"){D5 = "<o>"; start=1;}
	if (b1rod1 == "E5"){E5 = "<o>"; start=1;}
	if (b1rod1 == "F5"){F5 = "<o>"; start=1;}
	if (b1rod1 == "G5"){G5 = "<o>"; start=1;}
	if (b1rod1 == "H5"){H5 = "<o>"; start=1;}
	if (b1rod1 == "I5"){I5 = "<o>"; start=1;}
	
	if (b1rod1 == "A6"){A6 = "<o>"; start=1;}
	if (b1rod1 == "B6"){B6 = "<o>"; start=1;}
	if (b1rod1 == "C6"){C6 = "<o>"; start=1;}
	if (b1rod1 == "D6"){D6 = "<o>"; start=1;}
	if (b1rod1 == "E6"){E6 = "<o>"; start=1;}
	if (b1rod1 == "F6"){F6 = "<o>"; start=1;}
	if (b1rod1 == "G6"){G6 = "<o>"; start=1;}
	if (b1rod1 == "H6"){H6 = "<o>"; start=1;}
	if (b1rod1 == "I6"){I6 = "<o>"; start=1;}
	
	if (b1rod1 == "A7"){A7 = "<o>"; start=1;}
	if (b1rod1 == "B7"){B7 = "<o>"; start=1;}
	if (b1rod1 == "C7"){C7 = "<o>"; start=1;}
	if (b1rod1 == "D7"){D7 = "<o>"; start=1;}
	if (b1rod1 == "E7"){E7 = "<o>"; start=1;}
	if (b1rod1 == "F7"){F7 = "<o>"; start=1;}
	if (b1rod1 == "G7"){G7 = "<o>"; start=1;}
	if (b1rod1 == "H7"){H7 = "<o>"; start=1;}
	if (b1rod1 == "I7"){I7 = "<o>"; start=1;}
	
	
	
	
	//PLAYER 2
	//brod od 3 polja
	if (b3rod2 == "b1"){a1 = "<o";b1 = "o";c1 = "o>"; start=1;}
	if (b3rod2 == "c1"){b1 = "<o";c1 = "o";d1 = "o>"; start=1;}
	if (b3rod2 == "d1"){c1 = "<o";d1 = "o";e1 = "o>"; start=1;}
	if (b3rod2 == "e1"){d1 = "<o";e1 = "o";f1 = "o>"; start=1;}
	if (b3rod2 == "f1"){e1 = "<o";f1 = "o";g1 = "o>"; start=1;}
	if (b3rod2 == "g1"){f1 = "<o";g1 = "o";h1 = "o>"; start=1;}
	if (b3rod2 == "h1"){g1 = "<o";h1 = "o";i1 = "o>"; start=1;}
	
	if (b3rod2 == "b2"){a2 = "<o";b2 = "o";c2 = "o>"; start=1;}
	if (b3rod2 == "c2"){b2 = "<o";c2 = "o";d2 = "o>"; start=1;}
	if (b3rod2 == "d2"){c2 = "<o";d2 = "o";e2 = "o>"; start=1;}
	if (b3rod2 == "e2"){d2 = "<o";e2 = "o";f2 = "o>"; start=1;}
	if (b3rod2 == "f2"){e2 = "<o";f2 = "o";g2 = "o>"; start=1;}
	if (b3rod2 == "g2"){f2 = "<o";g2 = "o";h2 = "o>"; start=1;}
	if (b3rod2 == "h2"){g2 = "<o";h2 = "o";i2 = "o>"; start=1;}
	
	if (b3rod2 == "b3"){a3 = "<o";b3 = "o";c3 = "o>"; start=1;}
	if (b3rod2 == "c3"){b3 = "<o";c3 = "o";d3 = "o>"; start=1;}
	if (b3rod2 == "d3"){c3 = "<o";d3 = "o";e3 = "o>"; start=1;}
	if (b3rod2 == "e3"){d3 = "<o";e3 = "o";f3 = "o>"; start=1;}
	if (b3rod2 == "f3"){e3 = "<o";f3 = "o";g3 = "o>"; start=1;}
	if (b3rod2 == "g3"){f3 = "<o";g3 = "o";h3 = "o>"; start=1;}
	if (b3rod2 == "h3"){g3 = "<o";h3 = "o";i3 = "o>"; start=1;}
	
	if (b3rod2 == "b4"){a4 = "<o";b4 = "o";c4 = "o>"; start=1;}
	if (b3rod2 == "c4"){b4 = "<o";c4 = "o";d4 = "o>"; start=1;}
	if (b3rod2 == "d4"){c4 = "<o";d4 = "o";e4 = "o>"; start=1;}
	if (b3rod2 == "e4"){d4 = "<o";e4 = "o";f4 = "o>"; start=1;}
	if (b3rod2 == "f4"){e4 = "<o";f4 = "o";g4 = "o>"; start=1;}
	if (b3rod2 == "g4"){f4 = "<o";g4 = "o";h4 = "o>"; start=1;}
	if (b3rod2 == "h4"){g4 = "<o";h4 = "o";i4 = "o>"; start=1;}
	
	if (b3rod2 == "b5"){a5 = "<o";b5 = "o";c5 = "o>"; start=1;}
	if (b3rod2 == "c5"){b5 = "<o";c5 = "o";d5 = "o>"; start=1;}
	if (b3rod2 == "d5"){c5 = "<o";d5 = "o";e5 = "o>"; start=1;}
	if (b3rod2 == "e5"){d5 = "<o";e5 = "o";f5 = "o>"; start=1;}
	if (b3rod2 == "f5"){e5 = "<o";f5 = "o";g5 = "o>"; start=1;}
	if (b3rod2 == "g5"){f5 = "<o";g5 = "o";h5 = "o>"; start=1;}
	if (b3rod2 == "h5"){g5 = "<o";h5 = "o";i5 = "o>"; start=1;}
	
	if (b3rod2 == "b6"){a6 = "<o";b6 = "o";c6 = "o>"; start=1;}
	if (b3rod2 == "c6"){b6 = "<o";c6 = "o";d6 = "o>"; start=1;}
	if (b3rod2 == "d6"){c6 = "<o";d6 = "o";e6 = "o>"; start=1;}
	if (b3rod2 == "e6"){d6 = "<o";e6 = "o";f6 = "o>"; start=1;}
	if (b3rod2 == "f6"){e6 = "<o";f6 = "o";g6 = "o>"; start=1;}
	if (b3rod2 == "g6"){f6 = "<o";g6 = "o";h6 = "o>"; start=1;}
	if (b3rod2 == "h6"){g6 = "<o";h6 = "o";i6 = "o>"; start=1;}
	
	if (b3rod2 == "b7"){a7 = "<o";b7 = "o";c7 = "o>"; start=1;}
	if (b3rod2 == "c7"){b7 = "<o";c7 = "o";d7 = "o>"; start=1;}
	if (b3rod2 == "d7"){c7 = "<o";d7 = "o";e7 = "o>"; start=1;}
	if (b3rod2 == "e7"){d7 = "<o";e7 = "o";f7 = "o>"; start=1;}
	if (b3rod2 == "f7"){e7 = "<o";f7 = "o";g7 = "o>"; start=1;}
	if (b3rod2 == "g7"){f7 = "<o";g7 = "o";h7 = "o>"; start=1;}
	if (b3rod2 == "h7"){g7 = "<o";h7 = "o";i7 = "o>"; start=1;}
	
	//brod od 2 polja
	if (b2rod2 == "a1"){a1 = "<o";b1 = "o>"; start=1;}
	if (b2rod2 == "b1"){b1 = "<o";c1 = "o>"; start=1;}
	if (b2rod2 == "c1"){c1 = "<o";d1 = "o>"; start=1;}
	if (b2rod2 == "d1"){d1 = "<o";e1 = "o>"; start=1;}
	if (b2rod2 == "e1"){e1 = "<o";f1 = "o>"; start=1;}
	if (b2rod2 == "f1"){f1 = "<o";g1 = "o>"; start=1;}
	if (b2rod2 == "g1"){g1 = "<o";h1 = "o>"; start=1;}
	if (b2rod2 == "h1"){h1 = "<o";i1 = "o>"; start=1;}
	
	if (b2rod2 == "a2"){a2 = "<o";b2 = "o>"; start=1;}
	if (b2rod2 == "b2"){b2 = "<o";c2 = "o>"; start=1;}
	if (b2rod2 == "c2"){c2 = "<o";d2 = "o>"; start=1;}
	if (b2rod2 == "d2"){d2 = "<o";e2 = "o>"; start=1;}
	if (b2rod2 == "e2"){e2 = "<o";f2 = "o>"; start=1;}
	if (b2rod2 == "f2"){f2 = "<o";g2 = "o>"; start=1;}
	if (b2rod2 == "g2"){g2 = "<o";h2 = "o>"; start=1;}
	if (b2rod2 == "h2"){h2 = "<o";i2 = "o>"; start=1;}
	
	if (b2rod2 == "a3"){a3 = "<o";b3 = "o>"; start=1;}
	if (b2rod2 == "b3"){b3 = "<o";c3 = "o>"; start=1;}
	if (b2rod2 == "c3"){c3 = "<o";d3 = "o>"; start=1;}
	if (b2rod2 == "d3"){d3 = "<o";e3 = "o>"; start=1;}
	if (b2rod2 == "e3"){e3 = "<o";f3 = "o>"; start=1;}
	if (b2rod2 == "f3"){f3 = "<o";g3 = "o>"; start=1;}
	if (b2rod2 == "g3"){g3 = "<o";h3 = "o>"; start=1;}
	if (b2rod2 == "h3"){h3 = "<o";i3 = "o>"; start=1;}
	
	if (b2rod2 == "a4"){a4 = "<o";b4 = "o>"; start=1;}
	if (b2rod2 == "b4"){b4 = "<o";c4 = "o>"; start=1;}
	if (b2rod2 == "c4"){c4 = "<o";d4 = "o>"; start=1;}
	if (b2rod2 == "d4"){d4 = "<o";e4 = "o>"; start=1;}
	if (b2rod2 == "e4"){e4 = "<o";f4 = "o>"; start=1;}
	if (b2rod2 == "f4"){f4 = "<o";g4 = "o>"; start=1;}
	if (b2rod2 == "g4"){g4 = "<o";h4 = "o>"; start=1;}
	if (b2rod2 == "h4"){h4 = "<o";i4 = "o>"; start=1;}

	if (b2rod2 == "a5"){a5 = "<o";b5 = "o>"; start=1;}
	if (b2rod2 == "b5"){b5 = "<o";c5 = "o>"; start=1;}
	if (b2rod2 == "c5"){c5 = "<o";d5 = "o>"; start=1;}
	if (b2rod2 == "d5"){d5 = "<o";e5 = "o>"; start=1;}
	if (b2rod2 == "e5"){e5 = "<o";f5 = "o>"; start=1;}
	if (b2rod2 == "f5"){f5 = "<o";g5 = "o>"; start=1;}
	if (b2rod2 == "g5"){g5 = "<o";h5 = "o>"; start=1;}
	if (b2rod2 == "h5"){h5 = "<o";i5 = "o>"; start=1;}
	
	if (b2rod2 == "a6"){a6 = "<o";b6 = "o>"; start=1;}
	if (b2rod2 == "b6"){b6 = "<o";c6 = "o>"; start=1;}
	if (b2rod2 == "c6"){c6 = "<o";d6 = "o>"; start=1;}
	if (b2rod2 == "d6"){d6 = "<o";e6 = "o>"; start=1;}
	if (b2rod2 == "e6"){e6 = "<o";f6 = "o>"; start=1;}
	if (b2rod2 == "f6"){f6 = "<o";g6 = "o>"; start=1;}
	if (b2rod2 == "g6"){g6 = "<o";h6 = "o>"; start=1;}
	if (b2rod2 == "h6"){h6 = "<o";i6 = "o>"; start=1;}
	
	if (b2rod2 == "a7"){a7 = "<o";b7 = "o>"; start=1;}
	if (b2rod2 == "b7"){b7 = "<o";c7 = "o>"; start=1;}
	if (b2rod2 == "c7"){c7 = "<o";d7 = "o>"; start=1;}
	if (b2rod2 == "d7"){d7 = "<o";e7 = "o>"; start=1;}
	if (b2rod2 == "e7"){e7 = "<o";f7 = "o>"; start=1;}
	if (b2rod2 == "f7"){f7 = "<o";g7 = "o>"; start=1;}
	if (b2rod2 == "g7"){g7 = "<o";h7 = "o>"; start=1;}
	if (b2rod2 == "h7"){h7 = "<o";i7 = "o>"; start=1;}

	//brod od 1 polja
	if (b1rod2 == "a1"){a1 = "<o>"; start=1;}
	if (b1rod2 == "b1"){b1 = "<o>"; start=1;}
	if (b1rod2 == "c1"){c1 = "<o>"; start=1;}
	if (b1rod2 == "d1"){d1 = "<o>"; start=1;}
	if (b1rod2 == "e1"){e1 = "<o>"; start=1;}
	if (b1rod2 == "f1"){f1 = "<o>"; start=1;}
	if (b1rod2 == "g1"){g1 = "<o>"; start=1;}
	if (b1rod2 == "h1"){h1 = "<o>"; start=1;}
	if (b1rod2 == "i1"){i1 = "<o>"; start=1;}
	
	if (b1rod2 == "a2"){a2 = "<o>"; start=1;}
	if (b1rod2 == "b2"){b2 = "<o>"; start=1;}
	if (b1rod2 == "c2"){c2 = "<o>"; start=1;}
	if (b1rod2 == "d2"){d2 = "<o>"; start=1;}
	if (b1rod2 == "e2"){e2 = "<o>"; start=1;}
	if (b1rod2 == "f2"){f2 = "<o>"; start=1;}
	if (b1rod2 == "g2"){g2 = "<o>"; start=1;}
	if (b1rod2 == "h2"){h2 = "<o>"; start=1;}
	if (b1rod2 == "i2"){i2 = "<o>"; start=1;}
	
	if (b1rod2 == "a3"){a3 = "<o>"; start=1;}
	if (b1rod2 == "b3"){b3 = "<o>"; start=1;}
	if (b1rod2 == "c3"){c3 = "<o>"; start=1;}
	if (b1rod2 == "d3"){d3 = "<o>"; start=1;}
	if (b1rod2 == "e3"){e3 = "<o>"; start=1;}
	if (b1rod2 == "f3"){f3 = "<o>"; start=1;}
	if (b1rod2 == "g3"){g3 = "<o>"; start=1;}
	if (b1rod2 == "h3"){h3 = "<o>"; start=1;}
	if (b1rod2 == "i3"){i3 = "<o>"; start=1;}
	
	if (b1rod2 == "a4"){a4 = "<o>"; start=1;}
	if (b1rod2 == "b4"){b4 = "<o>"; start=1;}
	if (b1rod2 == "c4"){c4 = "<o>"; start=1;}
	if (b1rod2 == "d4"){d4 = "<o>"; start=1;}
	if (b1rod2 == "e4"){e4 = "<o>"; start=1;}
	if (b1rod2 == "f4"){f4 = "<o>"; start=1;}
	if (b1rod2 == "g4"){g4 = "<o>"; start=1;}
	if (b1rod2 == "h4"){h4 = "<o>"; start=1;}
	if (b1rod2 == "i4"){i4 = "<o>"; start=1;}
	
	if (b1rod2 == "a5"){a5 = "<o>"; start=1;}
	if (b1rod2 == "b5"){b5 = "<o>"; start=1;}
	if (b1rod2 == "c5"){c5 = "<o>"; start=1;}
	if (b1rod2 == "d5"){d5 = "<o>"; start=1;}
	if (b1rod2 == "e5"){e5 = "<o>"; start=1;}
	if (b1rod2 == "f5"){f5 = "<o>"; start=1;}
	if (b1rod2 == "g5"){g5 = "<o>"; start=1;}
	if (b1rod2 == "h5"){h5 = "<o>"; start=1;}
	if (b1rod2 == "i5"){i5 = "<o>"; start=1;}
	
	if (b1rod2 == "a6"){a6 = "<o>"; start=1;}
	if (b1rod2 == "b6"){b6 = "<o>"; start=1;}
	if (b1rod2 == "c6"){c6 = "<o>"; start=1;}
	if (b1rod2 == "d6"){d6 = "<o>"; start=1;}
	if (b1rod2 == "e6"){e6 = "<o>"; start=1;}
	if (b1rod2 == "f6"){f6 = "<o>"; start=1;}
	if (b1rod2 == "g6"){g6 = "<o>"; start=1;}
	if (b1rod2 == "h6"){h6 = "<o>"; start=1;}
	if (b1rod2 == "i6"){i6 = "<o>"; start=1;}
	
	if (b1rod2 == "a7"){a7 = "<o>"; start=1;}
	if (b1rod2 == "b7"){b7 = "<o>"; start=1;}
	if (b1rod2 == "c7"){c7 = "<o>"; start=1;}
	if (b1rod2 == "d7"){d7 = "<o>"; start=1;}
	if (b1rod2 == "e7"){e7 = "<o>"; start=1;}
	if (b1rod2 == "f7"){f7 = "<o>"; start=1;}
	if (b1rod2 == "g7"){g7 = "<o>"; start=1;}
	if (b1rod2 == "h7"){h7 = "<o>"; start=1;}
	if (b1rod2 == "i7"){i7 = "<o>"; start=1;}
	
	player1 = 1;

	//nastavak
	nastavak:
	napad1 = "";
	napad2 = "";
	if(player1 == 1){
	board1();
	cout << "\nPlayer1: Unesi na koje ces polje baciti raketu: ";
	cin >> napad1;
	player1 = 0;
	player2 = 1;
	goto loop;
}
	dalje:
	napad1 = "";
	napad2 = "";
	if(player2 == 1){
	board2();
	cout << "\nPlayer2: Unesi na koje ces polje baciti raketu: ";
	cin >> napad2;
	player2 = 0;
	
	goto loop;
	
}
	//loop
	loop:
		
	//boat lives
	//PLAYER 2 lives
	if(napad1 == b3rod2) l3ife2--;
	if(napad1 == b3rod2) l2ife2--;
	if(napad1 == b3rod2) l1ife2--;
	
	//PLAYER 1 lives
	if(napad2 == b3rod2) l3ife1--;
	if(napad2 == b3rod2) l2ife1--;
	if(napad2 == b3rod2) l1ife1--;
	
	//Has the ship sunk
	if(l3ife1 == 0) br3potopljen1=1;
	if(l2ife1 == 0) br2potopljen1=1;
	if(l1ife1 == 0) br1potopljen1=1;
	
	if(l3ife2 == 0) br3potopljen2=1;
	if(l2ife2 == 0) br2potopljen2=1;
	if(l1ife1 == 0) br2potopljen2=1;	
		
	//PLAYER1
	if(napad1 == b3rod2 || napad1 == b2rod2 || napad1 == b1rod2){cout << endl << "Pogodio si jedan brod!" << endl;}
	cout << "Player2 turn!";
	system("pause");
	
	//PLAYER2
	if(napad2 == b3rod1 || napad2 == b2rod1 || napad2 == b1rod1){cout << endl << "Pogodio si jedan brod!"<< endl;}
	if (player1 == 0){cout << "Player1 turn!"; system("pause");}
	
	goto dalje;
	
}
