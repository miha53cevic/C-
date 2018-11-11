#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	
	srand(time(0)); 
	cout << 1 + rand() % 3 << endl;
		
}
