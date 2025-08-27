//problem: https://leetcode.com/problems/minimum-path-sum/

//TC: O(m*n)
//SC: O(m*n) + O(m+n) for recursion stack in memoization and O(m*n) for tabulation
#include <bits/stdc++.h>    
using namespace std;

// this is memoization code
class Solution {
    int minsum(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];

        int left=INT_MAX, right=INT_MAX;
        
        int rleft=minsum(i,j-1, grid, dp);
        int rright=minsum(i-1,j, grid, dp);

        if(rleft!=INT_MAX) left=rleft+grid[i][j];
        if(rright!=INT_MAX) right=rright+grid[i][j];
        
        dp[i][j]=min(left,right);
        return dp[i][j];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return minsum(m-1,n-1,grid, dp);
    }
};