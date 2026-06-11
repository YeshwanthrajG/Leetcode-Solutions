/* 
Problem ID : 2670 

Problem : Find the Distinct Difference Array

Statement : You are given a 0-indexed array nums of length n.

The distinct difference array of nums is an array diff of length n such that diff[i] is equal to the 
number of distinct elements in the suffix nums[i + 1, ..., n - 1] subtracted from the number of distinct 
elements in the prefix nums[0, ..., i].

Return the distinct difference array of nums.

Note that nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j 
inclusive. Particularly, if i > j then nums[i, ..., j] denotes an empty subarray.
*/

/* Problem Link
https://leetcode.com/problems/find-the-distinct-difference-array/description/
*/

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> map, temp;
        for(auto i:nums) temp[i]++;
        for(auto i:nums){
            map[i]++;
            temp[i]--;
            if(temp[i]==0) temp.erase(i);
            res.push_back(map.size()-temp.size());
        }
        return res;
    }
};