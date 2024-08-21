#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//GFG PROBLEM LINK: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
//intution: i search depth wise and at some point collide with already visited node which is not parent 


class Solution{
  private:
    bool dfs(int start, int parent, vector<int> adj[], int vis[]){
        vis[start]=1;
        for(int node: adj[start]){
            if(vis[node]!=1){
                if(dfs(node, start, adj, vis)==true) return true;
                     
            }
            else if(parent!=node) return true;
            
        }
        return false;
        
        
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0;i<V;i++){// iterate over visited array to check over all connected components
            if(!vis[i]){
                if(dfs(i,-1,adj,vis)==true) return true;
            }
        }
        
        return false;
    }
};

int main(){

    return 0;
}