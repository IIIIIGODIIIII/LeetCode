#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

class UnionFind {
    public:
     // 2^17 - 1 is the minimum number in the form 2^x - 1 > 10^5.
     UnionFind(int n) : id(n), rank(n), weight(n, (1 << 17) - 1) {
       iota(id.begin(), id.end(), 0);
     }
   
     void unionByRank(int u, int v, int w) {
       const int i = find(u);
       const int j = find(v);
       const int newWeight = weight[i] & weight[j] & w;
       weight[i] = newWeight;
       weight[j] = newWeight;
       if (i == j)
         return;
       if (rank[i] < rank[j]) {
         id[i] = j;
       } else if (rank[i] > rank[j]) {
         id[j] = i;
       } else {
         id[i] = j;
         ++rank[j];
       }
     }
   
     int getMinCost(int u, int v) {
       if (u == v)
         return 0;
       const int i = find(u);
       const int j = find(v);
       return i == j ? weight[i] : -1;
     }
   
    private:
     vector<int> id;
     vector<int> rank;
     vector<int> weight;
   
     int find(int u) {
       return id[u] == u ? u : id[u] = find(id[u]);
     }
};

vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
    vector<int> ans;
    UnionFind uf(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      const int w = edge[2];
      uf.unionByRank(u, v, w);
    }

    for (const vector<int>& query : query) {
      const int u = query[0];
      const int v = query[1];
      ans.push_back(uf.getMinCost(u, v));
    }

    return ans;
}

int main() {
    int n = 5;
    vector<vector<int>> edges = {{0,1,7},{1,3,7},{1,2,1}}, query = {{0,3},{3,4}};

    vector<int> result = minimumCost(n, edges, query);
    for(auto res : result)
        cout<<res<<" ";

    return 0;
}