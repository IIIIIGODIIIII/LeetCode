#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    vector<int> nums = {2,2,1,1,1,2,2};
    map<int, int> m;
    int result = 0;

    for(int i = 0; i<nums.size(); i++){
        m[nums[i]]++;
        if(m[nums[i]] > nums.size()/2){
            result = nums[i];
            break;
        }   
    }
    cout<<result;
   return 0;
}