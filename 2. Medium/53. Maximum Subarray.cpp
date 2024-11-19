#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int maxSubArray(vector<int>& nums) {
    int sum = 0, maxSum = 0;

    for(auto num : nums){
        if(sum < 0)
            sum = 0;

        sum += num;
        maxSum = max(maxSum, sum);       
    }

    return maxSum;
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    cout<<maxSubArray(nums);

    return 0;
}