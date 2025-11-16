/* 
Problem ID : 1513 

Problem : Number of Substrings With Only 1s

Statement : Given a binary string s, return the number of substrings with all characters 1's. 
Since the answer may be too large, return it modulo 109 + 7.
*/

/* Problem Link
https://leetcode.com/problems/number-of-substrings-with-only-1s/description/?envType=daily-question&envId=2025-11-16
*/

class Solution {
public:
    int numSub(string s) {
        int count=0, total=0, mod=1e9+7;
        for(char a:s){
            if(a=='1') count++;
            else count=0;
            total=(total+count)%mod;
        }
        return total;
    }
};