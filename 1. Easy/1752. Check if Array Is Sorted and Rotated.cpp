#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

bool check(vector<int>& nums) {
    int inversions = 0;
    
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] > nums[(i+1) % nums.size()])
            inversions++;

        if(inversions > 1)
            return false;
    }

    return true;
}

int main()
{
    vector<int> nums = {3,4,5,1,2};
    bool result = check(nums);
    cout<<result;

    return 0;
}