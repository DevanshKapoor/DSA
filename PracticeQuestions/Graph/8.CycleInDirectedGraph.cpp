#include <iostream>
#include<queue>
#include<vector>
using namespace std;
//GFG PROBLEM LINK: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph
// for cycle to occur in directed graph , the node has to be visited again on the "same path"
//(undirected mai toh kahi aur se bhi visit ho jaati tab bhi cycle hi hoti)
class Solution{
    private:    
    bool dfsCycle(int node, int vis[], int pathVis[], vector<int> adj[]){
        vis[node]=1;
        pathVis[node]=1;
        //traverse for adjacent nodes
        for(auto n: adj[node]){
            //when node not visited
            if(!vis[n]){
                if(dfsCycle(n, vis, pathVis, adj) == true) return true;
            }
            // if node is visted on the same path
            else if(pathVis[n]){
                return true;
            }
        }
        
        pathVis[node]=0;
        return false;
    }
    
  public:
   // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        int pathVis[V]={0};
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfsCycle(i,vis,pathVis,adj)==true) return true;
            }
        }
        
        return false;
    }
};

int main(){
    return 0;
}