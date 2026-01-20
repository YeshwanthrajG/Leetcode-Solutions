/* 
Problem ID : 3781 

Problem : Maximum Score After Binary Swaps

Statement : You are given an integer array nums of length n and a binary string s of the same length.

Initially, your score is 0. Each index i where s[i] = '1' contributes nums[i] to the score.

You may perform any number of operations (including zero). In one operation, you may choose an 
index i such that 0 <= i < n - 1, where s[i] = '0', and s[i + 1] = '1', and swap these two characters.

Return an integer denoting the maximum possible score you can achieve.
*/

/* Problem Link
https://leetcode.com/problems/maximum-score-after-binary-swaps/description/
*/

class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        int n=nums.size();
        vector<int> onesPos;
        int ones=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                ones++;
                onesPos.push_back(i);
            }
        }
        if(ones==0) return 0;
        priority_queue<long long> pq;
        long long ans=0;
        int pos=0;
        for(int i=0;i<onesPos.size();i++){
            int lim=onesPos[i];
            while(pos<=lim){
                pq.push(nums[pos]);
                pos++;
            }
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};