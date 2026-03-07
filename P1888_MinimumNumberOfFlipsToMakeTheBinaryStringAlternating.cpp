/* 
Problem ID : 1888 

Problem : Minimum Number of Flips to Make the Binary String Alternating

Statement : You are given a binary string s. You are allowed to perform two types of operations 
on the string in any sequence:

Type-1: Remove the character at the start of the string s and append it to the end of the string.
Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and 
vice-versa.
Return the minimum number of type-2 operations you need to perform such that s becomes alternating.

The string is called alternating if no two adjacent characters are equal.

For example, the strings "010" and "1010" are alternating, while the string "0100" is not.
*/

/* Problem Link
https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/?envType=daily-question&envId=2026-03-07
*/

class Solution {
public:
    int minFlips(string s) {
        int n=s.length();
        vector<int> res(2,0);
        for(int i=0;i<n;i++){
            res[(s[i]^i)&1]++;
        }
        int ans=min(res[0], res[1]);
        for(int i=0;i<n;i++){
            res[(s[i]^i)&1]--;
            res[(s[i]^(n+i))&1]++;
            ans=min(ans, min(res[0], res[1]));
        }
        return ans;
    }
};