#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

vector<int> sieveEratosthenes(int n) {
    vector<int> primes;
    vector<bool> isPrime(n, true);

    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i < n; ++i)
        if (isPrime[i])

        for (int j = i * i; j < n; j += i)
            isPrime[j] = false;

    for (int i = 2; i < n; ++i)
        if (isPrime[i])
            primes.push_back(i);

    return primes;
}

bool primeSubOperation(vector<int>& nums) {
    constexpr int kMax = 1000;
    const vector<int> primes = sieveEratosthenes(kMax);

    int prevNum = 0;
    for (int num : nums) {
        // Make nums[i] the smallest as possible and still > nums[i - 1].
        auto it = lower_bound(primes.begin(), primes.end(), num - prevNum);

        if (it != primes.begin())
            num -= *prev(it);

        if (num <= prevNum)
            return false;

        prevNum = num;
    }

    return true;
}

int main() {
    vector<int> nums = {4,9,6,10};

    primeSubOperation(nums) ? cout<<"True" : cout<<"False";

    return 0;
}