#include <fstream>
#include <iostream>
#include <string>
using namespace std;

bool isKeyword(string word) {
    string keywords[20] = {
        "int", "float", "double", "char", "if", "else", "for", "while", "do",
        "return", "void", "break", "continue", "switch", "namespace", "using",
        "true", "false", "bool", "main"};
    for (int i = 0; i < 20; i++) {
        if (word == keywords[i])
            return true;
    }
    return false;
}

bool isOperator(char c) {
    string ops = "+-*/=%<>!";
    for (int i = 0; i < ops.length(); i++) {
        if (c == ops[i])
            return true;
    }
    return false;
}

bool isValidId(string s) {
    if (!((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z') || s[0] == '_'))
        return false;

    for (int i = 1; i < s.length(); i++) {
        if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') ||
              (s[i] >= '0' && s[i] <= '9') || s[i] == '_'))
            return false;
    }
    return true;
}

int main() {
    string fname;
    cout << "Enter file name (with .txt): ";
    cin >> fname;

    ifstream file(fname);
    if (!file.is_open()) {
        cout << "Error: file not found!" << endl;
        return 0;
    }

    char ch;
    string word = "";

    string kw = "";
    string id = "";
    string op = "";
    string num = "";

    while (!file.eof()) {
        file.get(ch);

        if (isOperator(ch)) {
            op = op + ch + " ";
        } else if (isalpha(ch) || ch == '_') {
            word = "";
            while (isalpha(ch) || isdigit(ch) || ch == '_') {
                word = word + ch;
                file.get(ch);
                if (file.eof())
                    break;
            }

            if (isKeyword(word))
                kw = kw + word + " ";
            else if (isValidId(word))
                id = id + word + " ";
        } else if (isdigit(ch)) {
            word = "";
            while (isdigit(ch)) {
                word = word + ch;
                file.get(ch);
                if (file.eof())
                    break;
            }
            num = num + word + " ";
        }
    }

    file.close();

    cout << "\n--- Lexical Analysis ---\n";

    if (kw == "")
        cout << "Keywords: None\n";
    else
        cout << "Keywords: " << kw << endl;

    if (id == "")
        cout << "Identifiers: None\n";
    else
        cout << "Identifiers: " << id << endl;

    if (op == "")
        cout << "Operators: None\n";
    else
        cout << "Operators: " << op << endl;

    if (num == "")
        cout << "Numbers: None\n";
    else
        cout << "Numbers: " << num << endl;

    return 0;
}
