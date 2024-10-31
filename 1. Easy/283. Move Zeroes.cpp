#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

void moveZeroes(vector<int>& nums) {
    int l = 0;

    for(int r = 0; r < nums.size(); r++){
        if(nums[r] != 0){
            swap(nums[l],nums[r]);
            l++;
        }
    }
}

int main(){
    vector<int> nums = {0,1,0,3,12};

    moveZeroes(nums);
    for(auto num : nums)
        cout<<num;

    return 0;
}