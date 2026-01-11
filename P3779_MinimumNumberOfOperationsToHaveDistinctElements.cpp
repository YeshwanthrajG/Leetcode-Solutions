/* 
Problem ID : 3779 

Problem : Minimum Number of Operations to Have Distinct Elements

Statement : You are given an integer array nums.

In one operation, you remove the first three elements of the current array. 
If there are fewer than three elements remaining, all remaining elements are removed.

Repeat this operation until the array is empty or contains no duplicate values.

Return an integer denoting the number of operations required.
*/

/* Problem Link
https://leetcode.com/problems/minimum-number-of-operations-to-have-distinct-elements/description/
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_set<int> seen;
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            if(seen.count(nums[i])){
                return (i+3)/3;
            }
            seen.insert(nums[i]);
        }
        return 0;
    }
};