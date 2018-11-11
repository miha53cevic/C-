#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<char> find_chars(vector<string> a, vector<string> b)
{
    int size = a.size();
    vector<char> c;

    for (int i=0;i<size;i++)
    {
        for (int j=0;j<a[i].length();j++)
        {
            if (char(a[i][j]) >= 32 && char(a[i][j]) < 47 || char(a[i][j]) >= 58 && char(a[i][j]) < 65 || char(a[i][j]) >= 91 && char(a[i][j]) < 97 || char(a[i][j]) >= 123)
            {
                c.push_back(char(a[i][j]));
            }
        }
    }
    return c;
}

int main()
{
    vector<string>a;
    vector<string>b;
    vector<char> c;

    cout << "Enter seperator: ";
    char sep;
    cin >> sep;

    while (1)
    {
        string input;
        char done;

        if (done == 'n')
        {
            break;
        }

        getline(cin, input, sep);
        a.push_back(input);

        getline(cin, input, '\n');
        b.push_back(input);

        cout << "Would you like to continue? y/n\n";
        cin >> done;
    }

    c = find_chars(a,b);

    for (int i=0;i<c.size();i++)
    {
        cout << c[i] << "\n";
    }
}
