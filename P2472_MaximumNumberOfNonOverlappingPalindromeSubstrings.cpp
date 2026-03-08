/* 
Problem ID : 2472 

Problem : Maximum Number of Non-overlapping Palindrome Substrings

Statement : You are given a string s and a positive integer k.

Select a set of non-overlapping substrings from the string s that satisfy the following conditions:

The length of each substring is at least k.
Each substring is a palindrome.
Return the maximum number of substrings in an optimal selection.

A substring is a contiguous sequence of characters within a string.
*/

/* Problem Link
https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/description/
*/

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n=s.length();
        int res=0, st=0;
        for(int i=0;i<2*n;i++){
            int l=i/2;
            int r=l+i%2;
            while(l>=st && r<n && s[l]==s[r]){
                if(r+1-l>=k){
                    res++;
                    st=r+1;
                    break;
                }
                l--;
                r++;
            }
        }
        return res;
    }
};