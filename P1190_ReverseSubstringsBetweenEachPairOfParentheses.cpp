/* 
Problem ID : 1190 

Problem : Reverse Substrings Between Each Pair of Parentheses

Statement : You are given a string s that consists of lower case English letters and brackets.

Reverse the strings in each pair of matching parentheses, starting from the innermost one.

Your result should not contain any brackets.
*/

/* Problem Link
https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/?envType=daily-question&envId=2026-09-27
*/

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string curr = "";
        for (char c : s) {
            if (c == '(') {
                st.push(curr);
                curr = "";
            }
            else if (c == ')') {
                reverse(curr.begin(), curr.end());
                curr = st.top() + curr;
                st.pop();
            }
            else {
                curr += c;
            }
        }
        return curr;
    }
};