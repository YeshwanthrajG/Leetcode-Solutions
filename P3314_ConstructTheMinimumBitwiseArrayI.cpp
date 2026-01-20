/* 
Problem ID : 3314 

Problem : Construct the Minimum Bitwise Array I

Statement : You are given an array nums consisting of n prime integers.

You need to construct an array ans of length n, such that, for each index i, the bitwise OR of 
ans[i] and ans[i] + 1 is equal to nums[i], i.e. ans[i] OR (ans[i] + 1) == nums[i].

Additionally, you must minimize each value of ans[i] in the resulting array.

If it is not possible to find such a value for ans[i] that satisfies the condition, then set ans[i] = -1.
*/

/* Problem Link
https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/description/?envType=daily-question&envId=2026-01-20
*/

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int s=nums.size();
        vector<int> res(s,-1);
        for(int i=0;i<s;i++){
            int n=nums[i];
            for(int j=1;j<n;j++){
                if((j | (j+1)) == n){
                    res[i]=j;
                    break;
                }
            }
        }
        return res;
    }
};