#include <iostream>
using namespace std;

int main (){
	
	int n;
	cout << "Enter your score: ";
	cin >> n;
	
	if (n >= 50 && n < 80) cout << "\nPass!";
	else if (n >=80) cout << "\nGreat Job";
	else if (n <= 20) cout << "\nFail";
	
}
