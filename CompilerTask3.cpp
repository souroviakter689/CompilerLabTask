#include<iostream>
using namespace std;

int main()
{
     string str;

    cout<<"Enter a line: ";
    getline(cin,str);


    if(str.length()>=2 && str[0]== '/'&& str[1]=='/')
    {
        cout<<"This is a single line comment"<<endl;

    }
    else if(str.length()>=4 && str[0]== '/'&& str[1]=='*'&& str[str.length()-2]=='*'&& str[str.length()-1]=='/')
    {
        cout<<"This is a multiple line comment"<<endl;
    }
    else
        cout<<"This is not a comment";
    return 0;
}
