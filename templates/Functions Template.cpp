#include <iostream>
using namespace std;
	
	int a,b,sum; //ako zelis da funkcije rade moras declarati ih ovako prije nego ih koristis
	int math();
	void end();
	
	int main () {
		
		cout << "Enter your 2 numbers: ";
		cin >> a >> b;
		math();
		
	}
	
	int math(){
		
		sum = a + b;
		end();
		
	}

	void end() {
		cout << sum;
	}
