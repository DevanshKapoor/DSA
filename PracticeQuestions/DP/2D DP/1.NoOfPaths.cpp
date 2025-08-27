//problem link: https://leetcode.com/problems/unique-paths/description/

//TC: O(m*n)
//SC: O(m*n) + O(m+n) for recursion stack in memoization and O(m*n) for tabulation
#include <bits/stdc++.h>
using namespace std;
class Solution {
    // int countpaths(int i, int j, vector<vector<int>> & dp){
    //     if(i==0 && j==0) return 1;
    //     if(i<0 || j<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];


    //     int left=countpaths(i,j-1, dp);
    //     int up=countpaths(i-1,j, dp);
    //     dp[i][j]=left+up;
    //     return dp[i][j];
    // }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        // return countpaths(m-1, n-1, dp);

        //tabulation
        int left=0, up=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j]=1;
                else{
                    if(j>0){
                        left=dp[i][j-1];
                    }else left=0;
                    if(i>0){
                        up= dp[i-1][j];
                        }else up=0;
                    
                    dp[i][j]=left+up;

                }
                
            }
        }
        return dp[m-1][n-1];
    }
};