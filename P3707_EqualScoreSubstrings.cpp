/* 
Problem ID : 3707 

Problem : Equal Score Substrings

Statement : You are given a string s consisting of lowercase English letters.

The score of a string is the sum of the positions of its characters in the alphabet, 
where 'a' = 1, 'b' = 2, ..., 'z' = 26.

Determine whether there exists an index i such that the string can be split into two non-empty 
substrings s[0..i] and s[(i + 1)..(n - 1)] that have equal scores.

Return true if such a split exists, otherwise return false.
*/

/* Problem Link
https://leetcode.com/problems/equal-score-substrings/description/
*/

class Solution {
public:
    bool scoreBalance(string s) {
        int total=0;
        for(char c:s){
            total+=(c-'a'+1);
        }
        int ls=0;
        for(int i=0;i<s.length()-1;i++){
            ls+=(s[i]-'a'+1);
            int rs=total-ls;
            if(ls==rs) return true;
        }
        return false;
    }
};