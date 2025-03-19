#include <iostream>
#include<bits/stdc++.h>

using namespace std;
//Kahns algorithm
//GFG PROBLEM LINK: https://www.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort

//intution: matain an indegree list. insert all nodes with indegree 0 into it. 
//          Take them out of queue and reduce indegree of adjacent nodes.


class Solution{
    public:
    vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   int inDegree[V]={0};
	   for(int i=0;i<V;i++){
	       for(auto n: adj[i]){
	           inDegree[n]++;
	       }
	   }
	   queue<int> q;
	   for(int i=0;i<V;i++){
	       if(inDegree[i]==0){
	           q.push(i);
	       }
	   }
	   vector<int> topo;
	   
	   while(!q.empty()){
	       int node=q.front();
	       topo.push_back(node);
	       q.pop();
	       
	       for(auto n:adj[node]){
	           inDegree[n]--;
	           if(inDegree[n]==0){
	               q.push(n);
	           }
	       }
	   }
	   
	   return topo;
	}
};