//question: https://leetcode.com/problems/two-sum/
// problem: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// use unodered map to store the elements and their indices.
// The algorithm iterates through the array, calculating the complement of each element with respect to the target.
// If the complement is found in the map, it returns the current index and the index of the complement.
// If not found, it adds the current element and its index to the map for future reference.
// The time complexity is O(n), where n is the length of the input array nums,
// and the space complexity is O(n) due to the storage of elements in the unordered map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int> mpp;
       int n=nums.size();
       for(int i=0;i<n;i++){
            int num=nums[i];
            int compliment=target-num;
            if(mpp.count(compliment)){
                return {i,mpp.at(compliment)};
            }
            mpp[num]=i;
       }
       return {};
    }
};