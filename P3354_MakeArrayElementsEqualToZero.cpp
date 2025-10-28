/* 
Problem ID : 3354 

Problem : Make Array Elements Equal to Zero

Statement : You are given an integer array nums.

Start by selecting a starting position curr such that nums[curr] == 0, and choose a movement 
direction of either left or right.

After that, you repeat the following process:

If curr is out of the range [0, n - 1], this process ends.

If nums[curr] == 0, move in the current direction by incrementing curr if you are moving right, 
or decrementing curr if you are moving left.

Else if nums[curr] > 0:
Decrement nums[curr] by 1.
Reverse your movement direction (left becomes right and vice versa).
Take a step in your new direction.

A selection of the initial position curr and movement direction is considered valid if every element 
in nums becomes 0 by the end of the process.

Return the number of possible valid selections.
*/

/* Problem Link
https://leetcode.com/problems/make-array-elements-equal-to-zero/description/?envType=daily-question&envId=2025-10-28
*/

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int total=accumulate(nums.begin(), nums.end(), 0LL);
        int ls=0, cases=0;
        for(int num:nums){
            int rs=total-ls-num;
            if(num==0){
                if(ls==rs){
                    cases+=2;
                }
                else if(ls==rs-1 || ls-1==rs){
                    cases++;
                }
            }
            ls+=num;
        }
        return cases;
    }
};