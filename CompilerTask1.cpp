#include<iostream>
using namespace std;

int main()
{
    string str;
    cout << "Enter an input: ";
    cin >> str;

    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] < '0' || str[i] > '9')
        {
            count = 1;
            break;
        }
    }

    if (count == 0)
        cout << "This is a numerical constant" << endl;
    else
        cout << "This is not a numerical constant" << endl;

    return 0;
}
