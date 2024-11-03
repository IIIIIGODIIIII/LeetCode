#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> mpp;

    for(int i = 0; i < nums.size(); i++)
        mpp[nums[i]] = i;
    
    for(int i = 0; i < nums.size(); i++){
        int complement = target - nums[i];

        if(mpp.find(complement) != mpp.end() && mpp[complement] != i)
            return {i, mpp[complement]};
    }

    return {};
}

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    
    vector<int> result = twoSum(nums, target);

    for(int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}