#include <iostream>
#include <vector>
using namespace std;
//zadatak pomnoži dva broja

int main() {
	
	int n;						//n je broj skupa brojeva
	int a,b,r; 					//a,b su brojevi koji se pomnože, r je pomnoženi broj
	vector<int>x;				//glavni vektor u koji se spremaju brojevi
	cin >> n;
	
	for (int i=0; i!=n; i++)
	{
		cin >> a >> b;
		r = a * b;
		x.push_back(r);
	}
	for (vector<int>::iterator it = x.begin() ; it != x.end(); ++it) //iscita vektora x i sva rjesenja koja su tamo spremljena ispise
	  cout << *it << endl;
}
