/* 
Problem ID : 338 

Problem : Counting Bits

Statement : Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), 
ans[i] is the number of 1's in the binary representation of i.
*/

/* Problem Link
https://leetcode.com/problems/counting-bits/description/
*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for(int i=0;i<=n;i++){
            res[i]=__builtin_popcount(i);
        }
        return res;
    }
};