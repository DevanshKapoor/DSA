#include <iostream>
#include<vector>
#include<queue>
using namespace std;

//0 based indexing

vector<int> bfsTraversal(int n, vector<int> adj[]){
    // n can be int n = sizeof(adj)/sizeof(adj[0])
    vector<int> bfs;
    queue<int> q;
    vector<int> vis(n,0);
    // OR  int vis[n]={0};
    vis[0]=1;// starting node is 0
    q.push(0);

    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);

        for(int i: adj[node]){
            if(!vis[i]){
                vis[i]=1;
                q.push(i);
            }
        }
    }

    return bfs;

}

int main(){

    return 0;
}