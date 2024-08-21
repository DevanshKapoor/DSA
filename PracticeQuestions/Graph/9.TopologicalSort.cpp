#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//GFG PROBLEM LINK: https://www.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort
//intution: i stored the node whose dfs was completed in a stack


class Solution{
    private:
    void dfs(int node, int vis[], stack<int> &st, vector<int> adj[]){
        vis[node]=1;
        for(auto n: adj[node]){
            if(!vis[n]){
                dfs(n,vis,st,adj);
            }
        }
        st.push(node);
    }
    

    public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int vis[V]={0};
	    stack<int> st;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,vis,st,adj);
	        }
	    }
	    vector<int> ans;
	    while(!st.empty()){
	        int n=st.top();
	        ans.push_back(n);
	        st.pop();
	    }
	    
	   return ans;
	}
};