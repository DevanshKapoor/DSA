//question:https://takeuforward.org/plus/dsa/problems/partition-a-set-into-two-subsets-with-minimum-absolute-sum-difference

// question: https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
//does not handle 0 elements in array or negative elements
//here all numbers are positive
//similar to subset sum problem
//just find all possible subset sums and then find the minimum absolute difference between totalSum-2*subsetSum
//use tabulation table's last row to find all possible subset sums


//leetcode problem has negative numbers also
//they applied something called meet in the middle concept
//given solution is only for non-negative numbers


class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n=nums.size();
        int tsum=0;
        for(int i:nums){
            tsum+=i;
        }
        vector<vector<bool>> dp(n,vector<bool>(tsum+1,false));

        for(int i=0;i<n;i++) dp[i][0]=true;

        if(nums[0]<=tsum) dp[0][nums[0]]=true;

        for(int i=1;i<n;i++){
            for(int target=1;target<=tsum;target++){
                bool ntake=dp[i-1][target];
                bool take= false;
                if(nums[i]<=target) take=dp[i-1][target-nums[i]];
                dp[i][target]=ntake || take;
            }
        }
        int minsum=INT_MAX;
        for(int target=0;target<=tsum/2;target++){
            if(dp[n-1][target]){
                int sum1=target;
                int sum2=tsum-target;
                int mini=abs(sum1-sum2);
                minsum=min(minsum,mini);
            }
        }

        return minsum;

    }
};