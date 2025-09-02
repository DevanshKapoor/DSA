//question: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

//naive approach
//This code properly backtracks when a mismatch occurs, ensuring it doesn't miss overlapping 
//potential matches. While this naive approach works, more advanced algorithms like KMP (Knuth-Morris-Pratt) 
//can solve this without backtracking (j), offering better performance.
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0; // Handle the empty needle edge case.
        }

        int n = haystack.size();
        int m = needle.size();
        int i = 0; // Pointer for needle
        
        for (int j = 0; j < n; j++) {
            if (haystack[j] == needle[i]) {
                i++; // Match found, advance needle pointer.
            } else {
                // Mismatch occurred.
                // Reset j to the character after the start of the last attempt.
                j = j - i; 
                // Reset the needle pointer.
                i = 0;
            }

            // Check if the entire needle has been found.
            if (i == m) {
                // The match started at the current position minus the length of the needle.
                return j - m + 1;
            }
        }

        return -1; // No match found after iterating through haystack.
    }
};