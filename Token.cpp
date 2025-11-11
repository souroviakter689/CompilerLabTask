#include <iostream>
#include <sstream>
#include <string>
using namespace std;


bool isKeyword(string token) {
    string keywords[] = {"int", "float", "char", "double", "if", "else", "for", "while", "return", "void", "cout", "cin"};
    int size = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < size; i++) {
        if (token == keywords[i])
            return true;
    }
    return false;
}


bool isNumber(string token) {
    for (int i = 0; i < token.length(); i++) {
        if (!isdigit(token[i]))
            return false;
    }
    return true;
}


bool isOperator(string token) {
    string ops[] = {"+", "-", "*", "/", "=", "==", "<", ">", "++", "--"};
    int size = sizeof(ops) / sizeof(ops[0]);
    for (int i = 0; i < size; i++) {
        if (token == ops[i])
            return true;
    }
    return false;
}


bool isPunctuation(string token) {
    string punct[] = {";", ",", "(", ")", "{", "}"};
    int size = sizeof(punct) / sizeof(punct[0]);
    for (int i = 0; i < size; i++) {
        if (token == punct[i])
            return true;
    }
    return false;
}


void identifyTokens(string lines[], int totalLines) {
    for (int i = 0; i < totalLines; i++) {
        cout << "\nLine " << i + 1 << ": " << lines[i] << endl;

        stringstream ss(lines[i]);
        string token;
        int count = 0;

        while (ss >> token) {
            count++;
            cout << "  Token " << count << ": " << token << " -> ";

            if (isKeyword(token))
                cout << "Keyword";
            else if (isNumber(token))
                cout << "Number";
            else if (isOperator(token))
                cout << "Operator";
            else if (isPunctuation(token))
                cout << "Punctuation";
            else
                cout << "Identifier";

            cout << endl;
        }

        cout << "Total tokens in line " << i + 1 << ": " << count << endl;
    }
}

int main() {

    string codeLines[] = {
        "int a = 5 ;",
        "float b = a + 10 ;",
        "cout << b ;"
    };

    int totalLines = 3;
    identifyTokens(codeLines, totalLines);

    return 0;
}
