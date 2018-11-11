#include <iostream>
using namespace std;

int main() {

string user;
string pass;

string tempuser;
string temppass;

bool correctuser;
bool correctpass;

cout << "Please create a username" << endl;
cout << "Username: ";

cin >> user;

cout << "Enter a password" << endl;
cout << "Password: ";

cin >> pass;

cout << "Please login now!" << endl;
cout << "Username: ";

cin >> tempuser;

if (tempuser == user)
{
	correctuser = true;
}
else
{
	correctuser = false;
}

if (correctuser == true)
{
	cout << "Enter your password " << tempuser << endl;
	cout << "Password: ";
}
else
{
	cout << "User is incorrect";
}

cin >> temppass;

if (temppass == pass)
{
	correctpass = true;
}
else
{
	correctpass = false;
}

if (correctuser == true)
{
	cout << "Thank you for logging in.";
}
}
