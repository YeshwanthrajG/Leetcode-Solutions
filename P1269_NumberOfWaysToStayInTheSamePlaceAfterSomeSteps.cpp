/* 
Problem ID : 1269 

Problem : Number of Ways to Stay in the Same Place After Some Steps

Statement : You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 
position to the left, 1 position to the right in the array, or stay in the same place (The pointer 
should not be placed outside the array at any time).

Given two integers steps and arrLen, return the number of ways such that your pointer is still at index 
0 after exactly steps steps. Since the answer may be too large, return it modulo 10^9 + 7.
*/

/* Problem Link
https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/description/
*/

class Solution {
public:
    int MOD=1e9+7;
    vector<vector<int>> memo;
    int x;

    int func(int i, int s){
        if(s==0 && i==0) return 1;
        if(i<0 || i>=x || s==0 || i>s) return 0;
        if(memo[i][s]!=-1) return memo[i][s];
        return memo[i][s]=((func(i+1, s-1)%MOD+func(i-1, s-1))%MOD+func(i, s-1))%MOD;
    }

    int numWays(int steps, int arrLen) {
        memo.resize(steps/2+1, vector<int>(steps+1, -1));
        this->x=arrLen;
        return func(0, steps);
    }
};