/* 
Problem ID : 3750 

Problem : Minimum Number of Flips to Reverse Binary String

Statement : You are given a positive integer n.

Let s be the binary representation of n without leading zeros.

The reverse of a binary string s is obtained by writing the characters of s in the opposite order.

You may flip any bit in s (change 0 → 1 or 1 → 0). Each flip affects exactly one bit.

Return the minimum number of flips required to make s equal to the reverse of its original form.
*/

/* Problem Link
https://leetcode.com/problems/minimum-number-of-flips-to-reverse-binary-string/description/
*/

class Solution {
public:
    int minimumFlips(int n) {
        string s=bitset<32>(n).to_string();
        s=s.substr(s.find('1'));
        string rev=s;
        reverse(rev.begin(), rev.end());
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=rev[i]){
                count++;
            }
        }
        return count;
    }
};