#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

string clearStars(string s) {
    string ans = s;
    vector<vector<int>> buckets(26);

    for (int i = 0; i < s.length(); ++i)
      if (s[i] == '*') {
        ans[i] = ' ';
        int j = 0;
        while (buckets[j].empty())
          ++j;
        ans[buckets[j].back()] = ' ', buckets[j].pop_back();
      } else {
        buckets[s[i] - 'a'].push_back(i);
      }

    ans.erase(std::remove(ans.begin(), ans.end(), ' '), ans.end());
    return ans;
}

int main() {
    string s = "aaba*";
    
    cout<<clearStars(s);

    return 0;
}