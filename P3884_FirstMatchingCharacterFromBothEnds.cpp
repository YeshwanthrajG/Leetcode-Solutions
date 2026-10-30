/* 
Problem ID : 3884 

Problem : First Matching Character From Both Ends

Statement : You are given a string s of length n consisting of lowercase English letters.

Return the smallest index i such that s[i] == s[n - i - 1].

If no such index exists, return -1.
*/

/* Problem Link
https://leetcode.com/problems/first-matching-character-from-both-ends/description/
*/

class Solution {
public:
    int firstMatchingIndex(string s) {
        int left=0, right=s.length()-1;
        while(left<=right){
            if(s[left]==s[right]) return left;
            left++;
            right--;
        }
        return -1;
    }
};