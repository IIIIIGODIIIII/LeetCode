#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int getDivisibleSum(int n, int m) {
    const int last = n / m * m;
    
    if (last == 0)
      return 0;

    const int first = m;
    const int count = (last - first) / m + 1;

    return (first + last) * count / 2;
}

int differenceOfSums(int n, int m) {
    const int sum = (1 + n) * n / 2;
    const int num2 = getDivisibleSum(n, m);
    const int num1 = sum - num2;
    
    return num1 - num2;
}

int main() {
    int n = 10, m = 3;
    
    cout<<differenceOfSums(n, m);

    return 0;
}