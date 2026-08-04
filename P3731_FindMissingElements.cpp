/* 
Problem ID : 3731 

Problem : Find Missing Elements

Statement : You are given an integer array nums consisting of unique integers.

Originally, nums contained every integer within a certain range. However, some integers might have 
gone missing from the array.

The smallest and largest integers of the original range are still present in nums.

Return a sorted list of all the missing integers in this range. If no integers are missing, return 
an empty list.
*/

/* Problem Link
https://leetcode.com/problems/find-missing-elements/description/?envType=daily-question&envId=2026-08-04
*/

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minV=nums[0], maxV=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            minV=min(minV, nums[i]);
            maxV=max(maxV, nums[i]);
        }
        unordered_set<int> set(nums.begin(), nums.end());
        vector<int> res;
        for(int i=minV+1;i<maxV;i++){
            if(set.find(i)==set.end()) res.push_back(i);
        }
        sort(res.begin(), res.end());
        return res;
    }
};