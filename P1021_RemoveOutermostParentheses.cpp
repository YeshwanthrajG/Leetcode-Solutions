/* 
Problem ID : 1021 

Problem : Remove Outermost Parentheses

Statement : A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid 
parentheses strings, and + represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split 
it into s = A + B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, 
where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive 
decomposition of s.
*/

/* Problem Link
https://leetcode.com/problems/remove-outermost-parentheses/description/?envType=daily-question&envId=2026-10-08
*/

class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length(), bal=0, x=0;
        for(int i=0;i<n;i++){
            bal+=(s[i]=='(')-(s[i]==')');
            if((bal==1 && s[i]=='(') || (bal==0 && s[i]==')')) continue;
            s[x++]=s[i];
        }
        s.resize(x);
        return s;
    }
};