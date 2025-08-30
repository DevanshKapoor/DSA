// question: https://leetcode.com/problems/coin-change/description/


//infinite supply pattern

//greedy fails for this problem
//example where greedy fails: coins={1,3,4} target=6
//greedy will give 3 coins(4+1+1) but optimal is 2 coins(3+3)

//similar to previous problems, just in take case we do not reduce the index as we have infinite supply of coins
//also in base case if we are at index 0 we can take the target/coins[0] if target is multiple of coins[0]

//memoization
class Solution {
    int numcoin(int i, int target, const vector<int>& coins, vector<vector<int>> & dp ){
        if(target==0) return 0;
        if(i==0){
            if(target%coins[i]==0) return target/coins[i];
            return 1e9;
        }
        if(dp[i][target]!=-1) return dp[i][target];

        int ntake=0+numcoin(i-1,target,coins,dp);
        int take=1e9;
        if(coins[i]<=target) take=1+numcoin(i,target-coins[i],coins,dp);

        return dp[i][target]= min(take,ntake);

    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        int num=numcoin(n-1, amount, coins, dp);
        if(num>=1e9) return -1;
        return num;
        
    }
};