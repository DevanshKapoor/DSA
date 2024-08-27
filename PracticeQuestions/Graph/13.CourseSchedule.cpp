#include <iostream>
#include<queue>
#include<vector>
using namespace std;
// leetcode link:https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adj(numCourses); // adjacency list
        
        // Build the graph
        for (const auto& requirement : prerequisites) {
            int course = requirement[0];
            int prerequisite = requirement[1];
            adj[prerequisite].push_back(course);
            inDegree[course]++;
        }
        
        queue<int> q;
        vector<int> order;
        
        // Find all courses with no prerequisites
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Process the courses
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);
            
            // Reduce inDegree of adjacent nodes (courses that depend on this course)
            for (int neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // Check if the order contains all courses
        if (order.size() == numCourses) {
            return order;
        } else {
            return {}; // return an empty vector if it's not possible to complete all courses
        }
    }
};
