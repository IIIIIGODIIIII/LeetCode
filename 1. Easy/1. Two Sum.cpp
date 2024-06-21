#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int nums[] = {1,1,1,1,1,4,1,1,1,1,1,7,1,1,1,1,1};
    int target = 11;
    vector<int> result;
    map<int, int> m;

    int n = sizeof(nums) / sizeof(nums[0]);

    for (int i = 0; i < n; i++) {
        int diff = target - nums[i];

        if (m.find(diff) != m.end()) {
            result.push_back(m[diff]);
            result.push_back(i);
            break; 
        }
        m[nums[i]] = i;
    }

    for(int i = 0; i < result.size(); i++)
        cout << result[i] << endl;

    return 0;
}