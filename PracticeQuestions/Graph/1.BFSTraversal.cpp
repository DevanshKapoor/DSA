#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//0 based indexing

vector<int> bfsTraversal(int n, vector<int> adj[]){
    vector<int> bfs;
    queue<int> q;
    int vis[n]={0};
    vis[0]=1;// starting node is 0
    q.push(0);

    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }

    return bfs;

}

int main(){

    return 0;
}