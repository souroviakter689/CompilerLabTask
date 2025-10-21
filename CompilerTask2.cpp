#include<iostream>
using namespace std;

int main()
{
    string str;

    cout<<"Enter an input";
    cin>> str;

    int count =0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i] == '+'|| str[i] == '-'|| str[i] == '*'|| str[i] == '/'|| str[i] == '%'|| str[i] == '=')
        {
            count++;
            cout<<"operator"<<count<<":"<<str[i]<<endl;
        }
    }
    if(count==0){
        cout<<"Not operators found"<<endl;
    }
    return 0;
}
