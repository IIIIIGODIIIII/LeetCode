#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7};
    int l=0, r=nums.size()-1, k=3, temp;

    while(l<r){
        temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
        l++;r--;
    }

    k = k % nums.size();
    l=0, r=k-1;

    while(l<r){
        temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
        l++;r--;
    }

    l = k;
    r = nums.size()-1;

    while(l<r){
        temp = nums[l];
        nums[l] = nums[r];
        nums[r] = temp;
        l++;r--;
    }

    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }

    return 0;
}