// leetcode question link: https://leetcode.com/problems/longest-palindromic-substring/?envType=problem-list-v2&envId=dynamic-programming


// problem: Given a string s, return the longest palindromic substring in s.

// A substring is a contiguous sequence of characters within the string.
//solution
class Solution {
    // Helper function to find the length of the longest palindromic substring
    // centered at indices i and j.
    // It expands outwards from the center while the characters at i and j are equal.
    int palen(int i, int j, string s){
        int n=s.length();
        int length=0;
        while(i>=0 && j<n && s[i]==s[j]){
            if(i==j) length++;
            else{
                length+=2;
            }
            i--;
            j++;
        }

        return length;

    }
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n<2){
            return s;
        }

        int maxlen=0;  // Maximum length of the palindromic substring found so far
        int st=0; // Start index of the longest palindromic substring

        for(int i=0;i<n;i++){
            // Check for odd-length palindromes centered at i
            int odd = palen(i,i,s);
            if(odd>maxlen){
                maxlen=odd;
                st=i-maxlen/2;
            }
            // Check for even-length palindromes centered between i and i+1
            int even = palen(i,i+1,s);
            if(even>maxlen){
                maxlen=even;
                st=i-(maxlen-1)/2;
            }
        }

        return s.substr(st,maxlen);
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(1)
// where n is the length of the input string s.

// The algorithm iterates through each character in the string and checks for 
//palindromes centered at each character and between characters, leading to a 
//quadratic time complexity. The space complexity is constant since we are not 
//using any additional data structures that grow with the input size.