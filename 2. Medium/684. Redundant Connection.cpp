#include<iostream>
#include<bits/stdc++.h>
 
using namespace std;

class UnionFind {
 public:
  UnionFind(int n) : id(n), rank(n) {
    iota(id.begin(), id.end(), 0);
  }

  bool unionByRank(int u, int v) {
    const int i = find(u);
    const int j = find(v);
    if (i == j)
    return false;

    if (rank[i] < rank[j]) {
        id[i] = j;
    } 

    else if (rank[i] > rank[j]) {
        id[j] = i;
    } 

    else {
        id[i] = j;
        ++rank[j];
    }
    
    return true;
  }

 private:
  vector<int> id;
  vector<int> rank;

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }

};

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    UnionFind uf(edges.size() + 1);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      if (!uf.unionByRank(u, v))
        return edge;
    }

    throw;
}

int main() {
    vector<vector<int>> edges = {{1,2}, {1,3}, {2,3}};

    vector<int> result = findRedundantConnection(edges);
    for(auto res : result)
        cout<<res<<" ";
        
    return 0;
}