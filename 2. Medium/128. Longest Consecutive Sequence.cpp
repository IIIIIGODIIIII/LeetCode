#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int sum = 0, count_l = 0, count_r = 0;
    map<int, int> consec;

    for (int i = 0; i < nums.size(); i++){
        if (consec[nums[i]] == 0){
            count_l = 0;
            count_r = 0;

            if (consec.find(nums[i] - 1) != consec.end())
                count_l = consec[nums[i] - 1];

            if (consec.find(nums[i] + 1) != consec.end())
                count_r = consec[nums[i] + 1];

            int TotalCount = count_l + count_r + 1;
            consec[nums[i]] = TotalCount;
            sum = max(sum, TotalCount);

            consec[nums[i] - count_l] = TotalCount;
            consec[nums[i] + count_r] = TotalCount;
        }
    }

    cout << sum << endl;
    return 0;
}