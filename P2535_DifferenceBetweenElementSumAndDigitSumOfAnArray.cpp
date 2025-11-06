/* 
Problem ID : 2535 

Problem : Difference Between Element Sum and Digit Sum of an Array

Statement : You are given a positive integer array nums.

The element sum is the sum of all the elements in nums.
The digit sum is the sum of all the digits (not necessarily distinct) that appear in nums.
Return the absolute difference between the element sum and digit sum of nums.

Note that the absolute difference between two integers x and y is defined as |x - y|.
*/

/* Problem Link
https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/description/?envType=problem-list-v2&envId=prshgx6i
*/

class Solution {
public:
    int digitSum(int n){
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int differenceOfSum(vector<int>& nums) {
        int eleSum=0, digSum=0;
        for(int i=0;i<nums.size();i++){
            int temp=nums[i];
            eleSum+=temp;
            if(temp<10) digSum+=temp;
            else digSum+=digitSum(temp);
        }
        return abs(eleSum-digSum);
    }
};