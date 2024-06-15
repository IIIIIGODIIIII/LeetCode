#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    vector<int> ratings = {1,0,2,7,7,6,2,8}, candy(ratings.size(), 1);
    int sum;

    //Left to Right  
    for(int i = 1; i < ratings.size(); i++){
        if(ratings[i-1] < ratings[i])
            candy[i] = candy[i-1] + 1;
    }

    //Right to Left
    for(int i = ratings.size()-2; i>=0; i--){
        if(ratings[i] > ratings[i+1])
            candy[i] = max(candy[i],candy[i+1] + 1);        //Jo last element pe tha uspe 1 se jada value bhi ho sakti hai isilye max lena padega
    }

    sum = accumulate(candy.begin(), candy.end(), 0);
    cout<<sum;

    return 0;
}