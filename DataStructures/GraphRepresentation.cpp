//comment other parts to run a specific portion

#include<iostream>
using namespace std;

//* UNDIRECTED GRAPH*//

//adjaceny matrix
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

//adjacency list
int main(){
    int n,m;
    cin>>n>>m;
    //1 based indexing
    vector<int> adj[n+1];

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}


//*DIRECTED GRAPH*//

//adjaceny matrix
int main(){

    int n, m;

    //1 based indexing
    int adj[n+1][n+1];

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
    }

    return 0;
}

//adjacency list
int main(){
    int n,m;
    cin>>n>>m;
    //1 based indexing
    vector<int> adj[n+1];

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        //no edge from v to u
    }
    return 0;
}


//WEIGHTED GRAPH
//adjacency list
int main(){
    int n,m;
    cin>>n>>m;
    //1 based indexing
    vector<pair<int,int>> adj[n+1];

    for(int i=0;i<m;i++){
        int u,v,weight;
        cin>>u>>v>>weight;
        adj[u].push_back({u,weight});
        //no edge from v to u
    }
    return 0;
}


