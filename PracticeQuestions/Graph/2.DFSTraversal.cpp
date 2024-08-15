#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//0 based indexing
//starting node is assumed to be 0
void dfs(int node, vector<int> adj[], int vis[], vector<int> & ls /*ls is to store traversal*/){
    vis[node]=1;
    ls.push_back(node);
    for(auto n: adj[node]){
        if(!vis[n]){
            dfs(n, adj, vis, ls);
        }
   }

}

vector<int> dfsTraversal(int n/*n is number of nodes*/, vector<int> adj[]){
    int vis[n]={0};
    int start=0;
    vector<int> traversal;
    dfs(start, adj, vis, traversal);

    return traversal;

}

int main(){

    return 0;
}