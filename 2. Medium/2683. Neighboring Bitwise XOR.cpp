#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool doesValidArrayExist(vector<int>& derived) {
    //      original = [O[0], O[1], ..., O[n - 1]]
    //       derived = [O[0]^O[1], O[1]^O[2], ..., O[n - 1]^O[0]]
    // XOR(derivedd) = 0
    return accumulate(derived.begin(), derived.end(), 0, bit_xor<>()) == 0;
}

int main() {
    vector<int> derived = {1,1,0};

    doesValidArrayExist(derived) ? cout<<"True" : cout<<"False";

    return 0;
}