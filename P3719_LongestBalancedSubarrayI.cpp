/* 
Problem ID : 3719 

Problem : Longest Balanced Subarray I

Statement : You are given an integer array nums.

A subarray is called balanced if the number of distinct even numbers in the subarray is 
equal to the number of distinct odd numbers.

Return the length of the longest balanced subarray.
*/

/* Problem Link
https://leetcode.com/problems/longest-balanced-subarray-i/description/?envType=daily-question&envId=2026-02-10
*/

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        vector<int> bal(n,0);
        unordered_map<int, int> m;
        int res=0;
        for(int i=n-1;i>=0;i--){
            int x=nums[i];
            auto it=m.find(x);
            if(it!=m.end()) bal[it->second]=0;
            m[x]=i;
            bal[i]=((x&1)==0)?1:-1;
            int s=0;
            for(int j=i;j<n;j++){
                s+=bal[j];
                if(s==0){
                    res=max(res, j-i+1);
                }
            }
        }
        return res;
    }
};