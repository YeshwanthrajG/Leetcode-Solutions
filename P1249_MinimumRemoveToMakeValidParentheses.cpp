/* 
Problem ID : 1249 

Problem : Minimum Remove to Make Valid Parentheses

Statement : Given a string s of '(' , ')' and lowercase English characters.

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) 
so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
*/

/* Problem Link
https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/
*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        int count=0;
        int i=0;
        while(i<n){
            if(s[i]=='('){
                count++;
                i++;
            }
            else if(s[i]==')'){
                if(count){
                    count--;
                    i++;
                }
                else s.erase(i, 1);
            }
            else i++;
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='(' && count){
                s.erase(i, 1);
                count--;
            }
            if(count==0) break;
        }
        return s;
    }
};