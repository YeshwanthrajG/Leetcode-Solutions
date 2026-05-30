/* 
Problem ID : 32 

Problem : Longest Valid Parentheses

Statement : Given a string containing just the characters '(' and ')', return the length of the 
longest valid (well-formed) parentheses substring.
*/

/* Problem Link
https://leetcode.com/problems/longest-valid-parentheses/description/
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxVal=0;
        stack<int> st;
        st.push(-1);
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    maxVal=max(maxVal, (i-st.top()));
                }
            }
        }
        return maxVal;
    }
};