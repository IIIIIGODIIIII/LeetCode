class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v1;
        vector<int>::iterator i1,i2,i3; 
        i3 = nums.begin();
        for(i1=nums.begin();i1!=nums.end();i1++)
        {
            for(i2=nums.begin();i2!=nums.end();i2++)
                if(*i1+*i2==target && i1!=i2)
                {
                    goto PUSH;
                }
        }
        
        PUSH:
                v1.push_back(i2-i3);
                v1.push_back(i1-i3);
        
        return v1;
    }
};