#include<iostream>
using namespace std;
//adjaceny matrix
//comment other parts to run a specific portion
int main(){

    int n, m;

    //1 based indexing
    int adj[n+1][n+1];

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }

    return 0;
}

int 