/* 
Problem ID : 75 

Problem : Sort Colors

Statement : Given an array nums with n objects colored red, white, or blue, sort them in-place 
so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
*/

/* Problem Link
https://leetcode.com/problems/sort-colors/description/
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3, 0);
        for(int i:nums){
            count[i]++;
        }
        nums.clear();
        for(int i=0;i<3;i++){
            nums.insert(nums.end(), count[i], i);
        }
    }
};