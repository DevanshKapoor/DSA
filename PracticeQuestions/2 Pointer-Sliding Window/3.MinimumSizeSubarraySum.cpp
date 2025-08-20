// question: https://leetcode.com/problems/minimum-size-subarray-sum/description/?envType=problem-list-v2&envId=binary-search
// Minimum Size Subarray Sum



//2 pointer/sliding window technique
//using a for loop and a while loop
// time complexity: O(n)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        int minlen=n+1;
        int i=0;
        if(n==0) return 0;
        for(int j=0;j<n;j++){
            sum+=nums[j];
            while(sum>=target){
                int len=j-i+1;
                minlen=min(minlen,len);
                sum-=nums[i];
                i++;
            }
        }
        if(minlen==n+1) return 0;

        return minlen;
    }
};