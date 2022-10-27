#include <bits/stdc++.h>
using namespace std;
 

void insert(int x, int y, vector<int> adjacency[])
{
    adjacency[x].push_back(y);
}
 

void dfs(int node, int leaf[], int vis[],
         vector<int> adjacency[])
{
    leaf[node] = 0;
    vis[node] = 1;
 
   
    for (auto it : adjacency[node]) {
 
       
        if (!vis[it]) {
            dfs(it, leaf, vis, adjacency);
            leaf[node] += leaf[it];
        }
    }
 
    if (!adjacency[node].size())
        leaf[node] = 1;
}
 

void printLeaf(int n, int leaf[])
{
   
    for (int i = 1; i <= n; i++) {
        cout <<"The node"<<i <<"has"
             <<leaf[i] <<"leaf nodes\n";
    }
}
 

int main()
{
    
 
    int N = 6; // no of nodes
    vector<int> adjacency[N + 1]; // adjacency list for tree
 
    insert(1, 2, adjacency);
    insert(1, 3, adjacency);
    insert(3, 4, adjacency);
    insert(3, 5, adjacency);
    insert(3, 6, adjacency);
 
    int leaf[N + 1]; // Store count of leaf in subtree of i
    int vis[N + 1] = { 0 }; // mark nodes visited
 
    dfs(1, leaf, vis, adjacency);
 
    printLeaf(N, leaf);
 
    return 0;
}