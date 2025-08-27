//question: https://leetcode.com/problems/triangle/



// ending point is opposite than previous two questions because 0,0 is fixed whereas last row can be any column, hence variable

//memoization
//question is gving tle in memoization solution!
class Solution {
   int minsum(int i, int j, int m, vector<vector<int>>& triangle, vector<vector<int>>& dp){
    if(i==m-1) return triangle[m-1][j];

    if(dp[i][j]!=-1) return dp[i][j];

    int down= minsum(i+1,j,m, triangle, dp)+ triangle[i][j];
    int diag= minsum(i+1,j+1,m, triangle, dp)+ triangle[i][j];

    dp[i][j]=min(down,diag);

    return dp[i][j];

   }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return minsum(0,0,m,triangle, dp);
        
    }
};

//tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        for(int j=0;j<m;j++){
            dp[m-1][j]=triangle[m-1][j];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=dp[i+1][j]+ triangle[i][j];
                int diag=dp[i+1][j+1]+ triangle[i][j];
                dp[i][j]=min(down,diag);
            }
        }

        return dp[0][0];
        
    }
};