/* 
Problem ID : 3228 

Problem : Maximum Number of Operations to Move Ones to the End

Statement : You are given a binary string s.

You can perform the following operation on the string any number of times:

Choose any index i from the string where i + 1 < s.length such that s[i] == '1' and s[i + 1] == '0'.
Move the character s[i] to the right until it reaches the end of the string or another '1'. 
For example, for s = "010010", if we choose i = 1, the resulting string will be s = "000110".
Return the maximum number of operations that you can perform.
*/

/* Problem Link
https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/description/?envType=daily-question&envId=2025-11-13
*/

class Solution {
public:
    int maxOperations(string s) {
        int ones=0, res=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') ones++;
            else if((i>0) && s[i-1]=='1') res+=ones;
        }
        return res;
    }
};