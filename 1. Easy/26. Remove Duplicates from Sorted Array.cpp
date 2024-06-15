#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> nums = {1,1,2,2,3,4,4,5};
    int j = 1;

    for(int i = 1; i<nums.size(); i++){
        if(nums[i]!=nums[i-1]){
            nums[j] = nums[i];
            j++;
        }
    }
    
    for(int i = 0; i<j; i++){
        cout<<nums[i]<<" ";
    }
    
    return 0;
}