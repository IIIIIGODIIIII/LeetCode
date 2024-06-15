#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int word_select(vector<string>,int,int);
bool check_word(vector<string);

int main()
{
    vector<string> words = {"Kabhi","Kabhi","Aditi","Jindagi","mein","koi","apna","lagta","hai."}, result;
    int maxWidth = 16, len = 0;

    for(const string& word: words){
        len += word.length();
    }

    for(int i = 0; i < words.size(); i++){
        
    }   

    return 0;
}

int word_select(vector<string> words, int index, int maxWidth){
    int len = 0;
    for(const string& word: words){
        len += word.length();
    }
    return len;
}

bool check_word(vector<string> words){
    
    return true;
}