//question: https://leetcode.com/problems/contains-duplicate-ii/submissions/1757563461/?envType=problem-list-v2&envId=sliding-window

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //using map (good but not optimal)
        // unordered_map<int, int> mpp;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     int ele=nums[i];
        //     if(mpp.count(ele)){
        //         int j=mpp.at(ele);
        //         if(abs(i-j)<=k) return true;
        //     }
        //     mpp[ele]=i;
        // }
        // return false;


        
        //sliding window + set 

        unordered_set<int> st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(st.count(nums[i])) return true;
            st.insert(nums[i]);
            if(i>=k){
                st.erase(nums[i-k]);
            }

        }
        return false;

    }
};