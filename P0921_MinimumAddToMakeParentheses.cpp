/* 
Problem ID : 921 

Problem : Minimum Add to Make Parentheses Valid

Statement : A parentheses string is valid if and only if:

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing 
parenthesis to be "())))".
Return the minimum number of moves required to make s valid.
*/

/* Problem Link
https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/?envType=daily-question&envId=2026-10-06
*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open=0, need=0;
        for(char c:s){
            if(c=='(') open++;
            else{
                if(open>0) open--;
                else need++;
            }
        }
        return (open+need);
    }
};