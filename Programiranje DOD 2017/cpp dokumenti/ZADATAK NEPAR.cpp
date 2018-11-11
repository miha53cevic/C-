#include <iostream>
using namespace std;

int main (){
	
	int br1,br2,br3,br4;
	bool crv, plav;
	cin >> br1 >> br2 >> br3 >> br4;
	if (((br1 + br2) % 2) != 1 ) crv == true;
	else if (((br1 + br2) % 2) == 1 ) crv == false;
	if (((br3 + br4) % 2) == 1 ) plav == true;
	else if (((br3 + br4) % 2) != 1 ) plav == true;
	
	if (plav == false && crv == false){
		 cout << "NE";
		 plav == false;
		 crv == false;
}
	return 0;
}
