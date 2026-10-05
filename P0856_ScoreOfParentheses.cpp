/* 
Problem ID : 856 

Problem : Score of Parentheses

Statement : Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.
*/

/* Problem Link
https://leetcode.com/problems/score-of-parentheses/description/?envType=daily-question&envId=2026-10-05
*/

class Solution {
public:
    int func(string& s, int x, int y){
        int res=0, bal=0;
        for(int i=x;i<y;i++){
            bal+=(s[i]=='('?1:-1);
            if(bal==0){
                if(i-x==1) res++;
                else res+=2*func(s, x+1, i);
                x=i+1;
            }
        }
        return res;
    }
    int scoreOfParentheses(string s) {
        return func(s, 0, s.length());
    }
};