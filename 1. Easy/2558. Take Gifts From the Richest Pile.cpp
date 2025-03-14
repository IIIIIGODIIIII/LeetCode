#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

long long pickGifts(vector<int>& gifts, int k) {
    long ans = 0;
    priority_queue<int> maxHeap;

    for (const int gift : gifts)
      maxHeap.push(gift);

    for (int i = 0; i < k; ++i) {
      const int squaredMax = sqrt(maxHeap.top());
      maxHeap.pop();
      maxHeap.push(squaredMax);
    }

    while (!maxHeap.empty())
      ans += maxHeap.top(), maxHeap.pop();

    return ans;
}

int main() {
    vector<int> gifts = {25,64,9,4,100};
    int k = 4;

    cout<<pickGifts(gifts, k);

    return 0;
}