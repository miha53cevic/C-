#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
//sum of 2 numbers

int main() {
	
	begining:
		
	//startup
	float n;
	float a,b;
	float sum;
	vector<float>x;
	
	//unos korisnika
	cout << "Unesi koliko ce parova brojeva biti: ";
	cin >> n;
	cout << endl << "Parovi:" << endl;
	
	//vector
	for (int i=0;i!=n;i++)
	{
		cin >> a >> b;
		sum = a + b;
		x.push_back(sum);
	}
	
	//sum
	ostream_iterator<float> out_it(cout,", ");
    copy(x.begin(), x.end(), out_it);
    
    //reset
    cout << endl;
    system("pause");
    system("cls");
    
    goto begining;
}
