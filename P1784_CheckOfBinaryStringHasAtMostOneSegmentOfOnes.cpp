/* 
Problem ID : 1784 

Problem : Check if Binary String Has at Most One Segment of Ones

Statement : Given a binary string s ​​​​​without leading zeros, 
return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.
*/

/* Problem Link
https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/?envType=daily-question&envId=2026-03-06
*/

class Solution {
public:
    bool checkOnesSegment(string s) {
        for(int i=1;i<s.length();i++){
            if(s[i-1]=='0' && s[i]=='1') return false;
        }
        return true;
    }
};