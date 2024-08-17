#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//GFG PROBLEM LINK: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
//intution: i came form 2 differnt direction bredth wise and collide at same node means a cycle
//i need to store (node,parent) in queue as i dont want to go back to node i just came from
class Solution{
  private:
    bool detectCycle(int node, int vis[], vector<int> adj[]){
      queue<pair<int,int>> q; //(node,parent)
        vis[node]=1;
        q.push({node,-1});
        while(!q.empty()){
            int cnode=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto n:adj[cnode]){
                if(!vis[n]){
                    vis[n]=1;
                    q.push({n,cnode});
                }
                
                else if(parent!=n) return true;
            }
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
                if(detectCycle(i,vis,adj)) return true;
            }
        }
        
        return false;
    }
};
int main(){

    return 0;
}