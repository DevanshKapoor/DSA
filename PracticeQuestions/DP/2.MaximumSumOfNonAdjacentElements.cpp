#include<iostream>
#include<vector>
#include <climits> 

using namespace std;

//problem link: https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
//Striver Video: https://www.youtube.com/watch?v=GrMBfJNk_NY&list=PLbgVysG3YYf1vPn2OO1pNrJfHGQXydxX7&index=5

//memoization
int rec(int n, vector<int> &nums, vector<int> &dp){
    if(n==0){
        return nums[0];
    }
    if(n<0){
        return 0;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    int pick=nums[n]+rec(n-2, nums, dp);
    int notPick=0+rec(n-1, nums, dp);

    dp[n]=max(pick,notPick);
    return dp[n];
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int> dp(n,-1);
    
    return rec(n-1, nums, dp);
    
}


//tabulation 
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    if (n==0) return 0;
    vector<int> dp(n,-1);

    dp[0]=nums[0];
    int notPick=0;
    int pick=0;

    for(int i=0;i<n;i++){
        pick=nums[i]; 
        if(i>1){
            pick+=dp[i-2];
        }
        notPick=0+dp[i-1];
        dp[i]=max(pick,notPick);
    }

    return dp[n-1];
   
}