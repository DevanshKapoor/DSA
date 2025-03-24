#include <bits/stdc++.h>
using namespace std;
//problem link: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-from-the-source-bellman-ford-algorithm

class Solution {
public:
	/*  Function to implement Bellman Ford
	*   edges: vector of vectors which represents the graph in the form:- (u,w,wt)
	*   S: source vertex to start traversing graph with
	*   V: number of vertices
	*/
	//Relax all the edges N-1 times sequentially
	vector<int> bellman_ford(int N, vector<vector<int>>& edges, int S) {
		vector<int> dist(N, 1e8);
		dist[S] = 0;
		for (int i = 0; i < N - 1; i++) {
			for (auto it : edges) {
				int u = it[0];
				int v = it[1];
				int wt = it[2];
				if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
					dist[v] = dist[u] + wt;
				}
			}
		}
		// Nth relaxation to check negative cycle
		for (auto it : edges) {
			int u = it[0];
			int v = it[1];
			int wt = it[2];
			if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
				return { -1};
			}
		}

		return dist;
	}
};