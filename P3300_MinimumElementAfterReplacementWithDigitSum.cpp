/* 
Problem ID : 3300 

Problem : Minimum Element After Replacement With Digit Sum

Statement : You are given an integer array nums.

You replace each element in nums with the sum of its digits.

Return the minimum element in nums after all replacements.
*/

/* Problem Link
https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/description/?envType=daily-question&envId=2026-05-29
*/

class Solution {
public:
    int digitSum(int n){
        int sum=0;
        while(n>0){
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }

    int minElement(vector<int>& nums) {
        int minE=INT_MAX;
        for(int i:nums){
            i=digitSum(i);
            minE=min(minE, i);
        }    
        return minE;
    }
};