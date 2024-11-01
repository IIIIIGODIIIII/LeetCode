#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int missingNumber(vector<int>& nums) {
    int expected_sum = (nums.size() * (nums.size() + 1)) / 2; 
    int original_sum = 0;

    for(auto num : nums)
        original_sum += num;
    
    return expected_sum - original_sum;
}

int main() {
    vector<int> nums = {3,0,1};

    cout<<missingNumber(nums);

    return 0;
}