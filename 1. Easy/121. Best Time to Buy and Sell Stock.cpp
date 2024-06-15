#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    int maxP = 0, i = 0, j = 1, profit;

    while(j < prices.size()){
        if(prices[i] < prices[j]){
            profit = prices[j] - prices[i];
            maxP = max(maxP,profit);
            j++;
        }

        else{ 
            i = j;
            j = j + 1;
        }
    }  

    cout<<maxP;

    return 0;
}