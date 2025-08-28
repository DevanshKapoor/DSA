//question: https://leetcode.com/problems/minimum-falling-path-sum/description/





//similar to triangle problem but here we can start from any column in first row and end at any column in last row

//memoization
//question is giving tle in memoization solution!
class Solution {
    int mindp(int i, int j,int m,int n, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        
        if(j<0 || j>=n || i<0 ||i>=m) return 1e6;
        if(i==0) return matrix[0][j];

        if(dp[i][j]!=-1) return dp[i][j];

        int mini=INT_MAX;
        
        vector<int>del={-1,0,1};
        
        for(int k=0;k<3;k++){
            int d=del[k];
            int minim=mindp(i-1,j-d,m,n , matrix,dp)+ matrix[i][j];
            mini=min(mini,minim);
        }

        dp[i][j]=mini;

        return mini;
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<vector<int>> dp(m,vector<int>(n,-1));
        int minsum=INT_MAX;
        for(int j=0;j<n;j++){
            int mini=mindp(m-1,j,m, n,matrix,dp);
            minsum=min(mini,minsum);
        }

        return minsum;
    }
};



//tabulation (optimized)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<vector<int>> dp(m,vector<int>(n,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0) dp[0][j]=matrix[0][j];
                else{
                    int mini=1e7;
                    for(int k=-1;k<=1;k++){

                        if(i-1>=0 && j+k>=0 && j+k<n) mini=min(dp[i-1][j+k]+matrix[i][j],mini);
                    }
                    dp[i][j]=mini;
                }

            }
        }
        int mini=1e7;
        for(int j=0;j<m;j++){
            mini=min(mini,dp[m-1][j]);
        }
        return mini;
    }
};