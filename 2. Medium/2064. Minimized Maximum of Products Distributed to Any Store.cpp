#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int numStores(const vector<int>& quantities, int m) {
    // ceil(q / m)
    return accumulate(
        quantities.begin(), quantities.end(), 0,
        [&](int subtotal, int q) { return subtotal + (q - 1) / m + 1; });     
}

int minimizedMaximum(int n, vector<int>& quantities) {
    int l = 1;
    int r = *max_element(quantities.begin(), quantities.end());

    while (l < r) {
        const int m = (l + r) / 2;
        if (numStores(quantities, m) <= n)
        r = m;
        else
        l = m + 1;
    }

    return l;
}

int main() {
    int n = 6;
    vector<int> quantities = {11,6};

    cout<<minimizedMaximum(n, quantities);

    return 0;
}