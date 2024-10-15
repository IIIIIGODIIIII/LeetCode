#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();

    for(int i = 0; i < n; i++){
        while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]){
            swap(nums[nums[i] - 1], nums[i]);
        }
    }

    for(int i = 0; i < n; i++){
        if(nums[i] != i + 1)
            return i + 1;
    }

    return n + 1;
}

int main() {
    vector<int> nums = {7,8,9,11,12};

    cout<<firstMissingPositive(nums);

    return 0;
}