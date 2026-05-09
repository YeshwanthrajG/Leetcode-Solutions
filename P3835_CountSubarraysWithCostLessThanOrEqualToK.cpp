/* 
Problem ID : 3835 

Problem : Count Subarrays With Cost Less Than or Equal to K

Statement : You are given an integer array nums, and an integer k.

For any subarray nums[l..r], define its cost as:

cost = (max(nums[l..r]) - min(nums[l..r])) * (r - l + 1).

Return an integer denoting the number of subarrays of nums whose cost is less than or equal to k.
*/

/* Problem Link
https://leetcode.com/problems/count-subarrays-with-cost-less-than-or-equal-to-k/description/
*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long res=0;
        int n=nums.size();
        deque<int> mx, mn;
        int l=0;
        for(int r=0;r<n;r++){
            while(!mx.empty() && mx.back() <nums[r]){
                mx.pop_back();
            }
            mx.push_back(nums[r]);
            while(!mn.empty() && mn.back()>nums[r]){
                mn.pop_back();
            }
            mn.push_back(nums[r]);
            while(!mx.empty() && !mn.empty() &&
                  (long long)(mx.front()-mn.front())*(r-l+1)>k){
                if(mx.front()==nums[l]) mx.pop_front();
                if(mn.front()==nums[l]) mn.pop_front();
                l++;
                  }
            res+=(r-l+1);
        }
        return res;
    }
};