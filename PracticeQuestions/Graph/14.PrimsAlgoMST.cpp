#include <bits/stdc++.h>

//problem link:https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree

class Solution
{
public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int spanningTree(int V, vector<vector<int>> adj[]){
		
		set<pair<int,int>> st;  // {wt, node}, If we wish to store the mst of the graph, 
                                //the set(or priority queue) should instead store the triplets 
                                //(edge weight, adjacent node, parent node)
								
		vector<int> vis(V, 0);
		
		st.insert({0, 0});
		int sum = 0;
		while (!st.empty()) {
			auto it = *(st.begin());
			st.erase(it);
			int node = it.second;
			int wt = it.first;

			if (vis[node] == 1) continue;
			// add it to the mst
			vis[node] = 1;
			sum += wt;
			for (auto it : adj[node]) {
				int adjNode = it[0];
				int edW = it[1];
				if (!vis[adjNode]) {
					st.insert({edW, adjNode});
				}
			}
		}
		return sum;
	}
};