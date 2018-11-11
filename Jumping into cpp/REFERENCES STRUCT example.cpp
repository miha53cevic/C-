#include <iostream>
using namespace std;

struct myBigStruct
{
    string x[ 100 ]; // big struct with lots of memory!
};

void takeStruct (myBigStruct& my_struct)
{
    my_struct.x[ 0 ] = "foo";
}
//Since a reference refers to the original object at all times,
//you both avoid copying and can modify the original object passed in to the function.
//The above example demonstrates setting my_struct.x[ 0 ]
//so that the original structure that was passed in will contain “foo” once the function returns.

 int main()
 {
    myBigStruct yeet;

    takeStruct (yeet);
    cout << yeet.x[0];
 }
