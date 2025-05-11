#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int maxProfit(vector<int>& prices) {
    int min = INT_MAX, max = 0;

    for(int i = 0; i < prices.size(); i++) {
        if(prices[i] < min)
            min = prices[i];
        else 
            max = std::max(max, prices[i] - min);
    }

    return max;
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};

    cout<<maxProfit(prices);

    return 0;
}