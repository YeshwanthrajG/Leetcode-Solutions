/* 
Problem ID : 678 

Problem : Valid Parenthesis String

Statement : Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".
*/

/* Problem Link
https://leetcode.com/problems/valid-parenthesis-string/description/?envType=daily-question&envId=2026-10-04
*/

class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();
        int left=0, right=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                left++;
                right++;
            }
            else if(s[i]==')'){
                if(left>0) left--;
                right--;
            }
            else{
                if(left>0)left--;
                right++;
            }
            if(right<0) return false;
        }
        return (left==0);
    }
};