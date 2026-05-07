/* 
Problem ID : 3660 

Problem : Jump Game IX

Statement : You are given an integer array nums.

From any index i, you can jump to another index j under the following rules:

Jump to index j where j > i is allowed only if nums[j] < nums[i].
Jump to index j where j < i is allowed only if nums[j] > nums[i].
For each index i, find the maximum value in nums that can be reached by following any sequence of valid 
jumps starting at i.

Return an array ans where ans[i] is the maximum value reachable starting from index i.
*/

/* Problem Link
https://leetcode.com/problems/jump-game-ix/description/?envType=daily-question&envId=2026-05-07
*/

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int> pref(n), suff(n), res(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=max(pref[i-1], nums[i]);
        }
        suff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]=min(suff[i+1], nums[i]);
        }
        res[n-1]=pref[n-1];
        for(int i=n-2;i>=0;i--){
            if(pref[i]>suff[i+1]) res[i]=res[i+1];
            else res[i]=pref[i];
        }
        return res;
    }
};