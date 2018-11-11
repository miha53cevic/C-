#include <iostream>
using namespace std;

int main()
  {
  cout << "Press the ENTER key";
  if (cin.get() == '\n')
    cout << "Good job.\n";
  else
    cout << "I meant ONLY the ENTER key... Oh well.\n";
  return 0;
  }
