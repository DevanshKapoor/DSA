// question: https://leetcode.com/problems/partition-equal-subset-sum/description/



// similar to subset sum problem
// just check if we can find a subset with sum equal to totalSum/2


class Solution {

    // bool check(int i, int target, const vector<int>& nums, vector<vector<int>> & dp){
    //     if(target==0) return true;
    //     if(i==0) return(nums[0]==target);
    //     if(dp[i][target]!=-1) return dp[i][target];
    //     bool ntake=check(i-1, target, nums,dp);
    //     bool take=false;
    //     if(nums[i]<=target){
    //         take= check(i-1,target-nums[i],nums,dp);
    //     }
    //     return dp[i][target]=take||ntake;

    // }

public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i: nums){
            sum+=i;
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        vector<vector<bool>> dp(n,vector<bool>(target+1,false));

        for(int i=0;i<n;i++) dp[i][0]= true;
        if(nums[0] <= target) dp[0][nums[0]] =true;

        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool ntake=dp[i-1][j];
                bool take =false;
                if(nums[i]<=j) take=dp[i-1][j-nums[i]];

                dp[i][j]= take|| ntake;

            }
        }

        return dp[n-1][target];


    }
};