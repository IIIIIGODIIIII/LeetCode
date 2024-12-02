#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

int findChampion(int n, vector<vector<int>>& edges) {
    int ans = -1;
    int count = 0;
    vector<int> inDegrees(n);

    for (const vector<int>& edge : edges) {
        const int v = edge[1];
        ++inDegrees[v];
    }

    for (int i = 0; i < n; ++i)
        if (inDegrees[i] == 0) {
            ++count;
            ans = i;
        }

    return count > 1 ? -1 : ans;
}

int main() {
    int n = 3;
    vector<vector<int>> edges = {{0,1},{1,2}};

    cout<<findChampion(n, edges);

    return 0;
}