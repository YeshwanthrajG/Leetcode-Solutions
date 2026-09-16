/* 
Problem ID : 167 

Problem : Two Sum II - Input Array Is Sorted

Statement : Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, 
find two numbers such that they add up to a specific target number. Let these two numbers be 
numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers index1 and index2, each incremented by one, as an integer 
array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.
*/

/* Problem Link
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int l=0, r=n-1;
        while(l<r){
            int sum=numbers[l]+numbers[r];
            if(sum==target) return {l+1, r+1};
            else if(sum<target) l++;
            else r--;
        }
        return {-1,-1};
    }
};