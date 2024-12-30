#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int countGoodStrings(int low, int high, int zero, int one) {
    constexpr int kMod = 1'000'000'007;
    int ans = 0;
    // dp[i] := the number of good strings with length i
    vector<int> dp(high + 1);
    dp[0] = 1;

    for (int i = 1; i <= high; ++i) {
        if (i >= zero)
            dp[i] = (dp[i] + dp[i - zero]) % kMod;
        if (i >= one)
            dp[i] = (dp[i] + dp[i - one]) % kMod;
        if (i >= low)
            ans = (ans + dp[i]) % kMod;
    }

    return ans;  
}

int main() {
    int low = 3, high = 3, zero = 1, one = 1;

    cout<<countGoodStrings(low, high, zero, one);

    return 0;
}