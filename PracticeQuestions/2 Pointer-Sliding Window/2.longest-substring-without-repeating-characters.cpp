//question: https://leetcode.com/problems/longest-substring-without-repeating-characters/




//SLIDING WINDOW with hashmap
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;
        int n=s.length();
        int maxlen=0;
        int len=0;
        int i=0;

        for(int j=0;j<n;j++){
            char c=s[j];
            if(mpp.count(c) && mpp[c]>=i){
                i=mpp[c]+1;   
            }
            mpp[c]=j;
            len=j-i+1;
            maxlen=max(maxlen,len);
        }

        return maxlen;
    }
};

// The algorithm uses a sliding window approach to find the length of the longest substring without repeating characters.
// It maintains a map to store the last occurrence of each character and two pointers (i and j) to represent the current window.
// As it iterates through the string, it checks if the current character has been seen before within the current window.
// If it has, it updates the start pointer (i) to the position after the last occurrence of that character.
// It then updates the last occurrence of the character and calculates the length of the current substring.
// The maximum length found during the iteration is returned as the result.
// The time complexity is O(n), where n is the length of the input string s,
// and the space complexity is O(min(n, m)), where m is the size of the character set (e.g., 26 for lowercase English letters).
// This is because we store the last occurrence of each character in the map.

