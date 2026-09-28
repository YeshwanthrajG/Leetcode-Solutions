/* 
Problem ID : 1614 

Problem : Maximum Nesting Depth of the Parentheses

Statement : Given a valid parentheses string s, return the nesting depth of s. The nesting depth is 
the maximum number of nested parentheses.
*/

/* Problem Link
https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/?envType=daily-question&envId=2026-09-28
*/

class Solution {
public:
    int maxDepth(string s) {
        int count=0;
        int maxLength=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(') count++;
            else if(s[i]==')') {
                maxLength=max(maxLength, count);
                count--;
            }
        }
        maxLength=max(maxLength, count);
        return maxLength;
    }
};