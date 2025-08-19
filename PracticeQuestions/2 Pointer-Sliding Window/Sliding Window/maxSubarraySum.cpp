//question: https://leetcode.com/problems/maximum-subarray/submissions/1740841104/?envType=problem-list-v2&envId=dynamic-programming
// problem: Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
// A subarray is a contiguous part of an array.


//solution
class Solution {

    
// The algorithm uses a sliding window approach to find the maximum subarray sum.
// It maintains a current sum and updates the maximum sum found so far.
// If the current sum becomes negative, it resets to zero, as a negative sum would not
// contribute positively to any future subarray sums.
// It iterates through the array, adding each element to the current sum and updating the maximum
// sum accordingly. If the current sum drops below zero, it resets to zero to start a new subarray.
// The time complexity is O(n), where n is the length of the input array nums.


public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxsum=INT_MIN;
        int currsum=0;
        for(int j=0;j<n;j++){
            currsum+=nums[j];
            maxsum=max(maxsum,currsum);
            if(currsum<0){
                currsum=0;
            }

        }

        return maxsum;
    }
};