#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

long factorial(int n) {
    long res = 1;

    for (int i = 2; i <= n; ++i)
      res *= i;

    return res;
}

long long countGoodIntegers(int n, int k) {
    const int halfLength = (n + 1) / 2;
    const int minHalf = pow(10, halfLength - 1);
    const int maxHalf = pow(10, halfLength);
    long ans = 0;
    unordered_set<string> seen;

    for (int num = minHalf; num < maxHalf; ++num) {
      const string firstHalf = to_string(num);
      const string secondHalf = {firstHalf.rbegin(), firstHalf.rend()};
      const string palindrome = firstHalf + secondHalf.substr(n % 2);

      if (stol(palindrome) % k != 0)
        continue;

      string sortedDigits = palindrome;
      std::sort(sortedDigits.begin(), sortedDigits.end());

      if (seen.find(sortedDigits) != seen.end())
        continue;

      seen.insert(sortedDigits);
      vector<int> digitCount(10);

      for (const char c : palindrome)
        ++digitCount[c - '0'];
      // Leading zeros are not allowed, so the first digit is special.
      const int firstDigitChoices = n - digitCount[0];
      long permutations = firstDigitChoices * factorial(n - 1);
      // For each repeated digit, divide by the factorial of the frequency since
      // permutations that swap identical digits don't create a new number.
      for (const int freq : digitCount)
        if (freq > 1)
          permutations /= factorial(freq);

      ans += permutations;
    }

    return ans;
}

int main() {
    
    return 0;
}