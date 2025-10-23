/* 
Problem ID : 3461 

Problem : Check If Digits Are Equal in String After Operations I

Statement : You are given a string s consisting of digits. 
Perform the following operation repeatedly until the string has exactly two digits:

For each pair of consecutive digits in s, starting from the first digit, calculate a new digit as the 
sum of the two digits modulo 10.
Replace s with the sequence of newly calculated digits, maintaining the order in which they are computed.
Return true if the final two digits in s are the same; otherwise, return false.
*/

/* Problem Link
https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/description/?envType=daily-question&envId=2025-10-23
*/

class Solution {
public:
    bool hasSameDigits(string s) {
        int i=0;
        string res="";
        while(s.size()>2 && i<s.size()-1){
            res+=(s[i]+s[i+1])%10;
            i++;
            if(i==s.size()-1){
                s=res;
                i=0;
                res="";
            }
        }
        return s.size()==2 && s[0]==s[1];
    }
};