#include<iostream>
#include<vector>
#include <climits> 

using namespace std;

//problem link: https://www.naukri.com/code360/problems/implement-upper-bound_8165383?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries

//memoization solution

int f(int n, vector<int> &height, vector<int> &dp){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1) return dp[n];

    int left=f(n-1, height, dp)+abs(height[n]-height[n-1]);
    int right=INT_MAX;
    if(n>1){
        right=f(n-2, height, dp)+abs(height[n]-height[n-2]);
    }
    dp[n]=min(left,right);
    return dp[n];
}

int frogJump(int n, vector<int> &heights){
    // Write your code here.
    vector<int> dp(n+1,-1);
    return f(n-1, heights, dp);
}









int main(){
    return 0;
}