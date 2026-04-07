/* 
Problem ID : 905 

Problem : Sort Array By Parity

Statement : Given an integer array nums, move all the even integers at the beginning of the array 
followed by all the odd integers.

Return any array that satisfies this condition.
*/

/* Problem Link
https://leetcode.com/problems/sort-array-by-parity/description/
*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int idx=0, n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[idx]%2==0){
                idx++;
                continue;
            }
            if(nums[i]%2==0){
                swap(nums[idx], nums[i]);
                idx++;
            }
        }
        return nums;
    }
};