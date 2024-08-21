#include <iostream>
#include<bits/stdc++.h>
#include<climits>

using namespace std;
//Dijkstras algorithm using set
//GFG PROBLEM LINK: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-dijkstra-set-1-adjacency-matrix

//set stores unique values in ascending order

// } Driver Code Ends


class Solution{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.

    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        // Code here
        set<pair<int,int>> st; // stores(distance,node)
        vector<int> dist(V, 1e9);
        st.insert({0,S});//node S(source node) with 0 distance

        dist[S]=0;
    
        while(!st.empty()){
            auto it=*(st.begin());
            int node=it.second;
            int dis=it.first;
            
            st.erase(it);
            
            for(auto it: adj[node]){
                int adjNode=it[0];
                int edgeW=it[1];
                
                if(dis  + edgeW < dist[adjNode]){
                    dist[adjNode]=dis  + edgeW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
        
    }
};

