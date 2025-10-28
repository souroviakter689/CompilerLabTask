#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;

    cout << "Enter a string: ";
    cin >> input;


    if (input.empty())
        {
        cout << "The input is not a valid identifier." << endl;
    }
    else{

        char c = input[0];
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_'))
            {
            cout << "The input is not a valid identifier." << endl;
            }
        else
            {
            int count = 0;
            for (int i = 1; i < input.length(); ++i) {
                char cc = input[i];
                if (!((cc >= 'A' && cc <= 'Z') ||
                      (cc >= 'a' && cc <= 'z') ||
                      (cc >= '0' && cc <= '9') ||
                      cc == '_')) {
                    count++;
                    break;
                }
            }


            if (count==0) {
                cout << "The input is a valid identifier." << endl;
            } else {
                cout << "The input is not a valid identifier." << endl;
            }
        }
    }

    return 0;
}
