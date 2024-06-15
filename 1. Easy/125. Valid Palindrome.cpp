#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
string concatenate(string);

int main()
{
    string s = "A man, a plan, a canal: Panama", input;
    int i = 0, j;
    input = concatenate(s);
    j = input.length()-1;

    cout<<j<<endl;
    cout<<input<<endl;

    if(input.length() == 1 && isalnum(input[0])){
        cout<<"TRUE"<<endl;
        return true;
    }

    while(i<j){
        if(input[i] != input[j]){
            cout<<"NOT PALINDROME"<<endl;
            return false;
        }
        i++;
        j--;
    }

    cout<<"PALINDROME"<<endl;
    return 0;
}

string concatenate(string s){
    string result;
    for(int i = 0; i<s.size(); i++){
        if(isalpha(s[i]) || isalnum(s[i])){
            result.push_back(tolower(s[i]));
        }
    }
    return result;
}