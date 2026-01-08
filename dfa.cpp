#include <iostream>
#include <string>
using namespace std;

bool isAccepting(int state)
{

    if (state == 4 || state == 6 || state == 10 || state == 11 || state == 12)
        return true;
    return false;
}

int moveState(int current, char input)
{
    if (current == 0) {
        if (input == 'a') return 1;
        else return 2;
    }
    if (current == 1) {
        if (input == 'a') return 3;
        else return 2;
    }
    if (current == 2) {
        if (input == 'a') return 3;
        else return 2;
    }
    if (current == 3) {
        if (input == 'a') return 4;
        else return 5;
    }
    if (current == 4) {
        if (input == 'a') return 6;
        else return 7;
    }
    if (current == 5) {
        if (input == 'a') return 6;
        else return 5;
    }
    if (current == 6) {
        if (input == 'a') return 10;
        else return 7;
    }
    if (current == 7) {
        if (input == 'a') return 10;
        else return 8;
    }
    if (current == 8) {
        if (input == 'a') return 9;
        else return 8;
    }
    if (current == 9) {
        if (input == 'a') return 11;
        else return 9;
    }
    if (current == 10) {
        if (input == 'a') return 12;
        else return 13;
    }
    if (current == 11) {
        if (input == 'a') return 12;
        else return 13;
    }
    if (current == 12) {
        if (input == 'a') return 12;
        else return 13;
    }
    if (current == 13) {
        if (input == 'a') return 10;
        else return 13;
    }

    return -1;
}

int main()
{
    string input;
    cout << "Enter string (a and b only): ";
    cin >> input;

    int currentState = 0;

    for (int i = 0; i < input.length(); i++) {
        currentState = moveState(currentState, input[i]);
    }

    if (isAccepting(currentState))
        cout << "String ACCEPTED\n";
    else
        cout << "String REJECTED\n";

    return 0;
}

