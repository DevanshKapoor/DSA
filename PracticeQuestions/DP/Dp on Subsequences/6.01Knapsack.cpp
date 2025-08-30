//question : https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1


//memoization solution
//tabulation khud soch lena
//similar to subset sum problem
class Solution {
    int knap(int i, int w, const vector<int> &val, const vector<int> &wt, vector<vector<int>> & dp){
        
        if(w==0) return 0;
        if(i==0){
            if(wt[i]<=w) return val[i];
            else return 0;
        }
        if(dp[i][w]!=-1) return dp[i][w];
        
        int ntake= 0+knap(i-1,w, val, wt, dp);
        int take=-1;
        if(w>=wt[i]) take=val[i]+knap(i-1,w-wt[i], val, wt, dp);
        dp[i][w]=max(ntake,take);
        return dp[i][w];
    }
    
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n= val.size();
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        return knap(n-1,W, val, wt, dp);
        
    }
};