#include <iostream>
#include<queue>
#include<vector>
using namespace std;
//GFG PROBLEM LINK: https://www.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph
// in vis array -1 means no color. We try to color nodes either 0 or 1 
class Solution{
    bool bipartite(int startNode, vector<int> adj[], int vis[]){
        //bfs traversal to navigate
        queue<int> q;
        vis[startNode]=0;
        q.push(startNode);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(int n: adj[node]){
                if(vis[n]==-1){
                    vis[n]= !vis[node];
                    q.push(n);
                }
                
                else if(vis[n]==vis[node]){
                    return false;
                }
            }
        }
        
        return true;
    }

    public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int visited[V];
	    for(int i=0;i<V;i++) visited[i]=-1;

	    for(int i=0;i<V; i++){
	        if(visited[i]==-1){
	            if(!bipartite(i/*this is node index, not its value in vis, so for each loop was failing*/, adj, visited)) return false;
	            
	        }
	    }
	   
	   return true; 
	}
};

int main(){
    return 0;
}