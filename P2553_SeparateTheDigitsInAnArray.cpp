/* 
Problem ID : 2553 

Problem : Separate the Digits in an Array

Statement : Given an array of positive integers nums, return an array answer that consists of the digits 
of each integer in nums after separating them in the same order they appear in nums.

To separate the digits of an integer is to get all the digits it has in the same order.

For example, for the integer 10921, the separation of its digits is [1,0,9,2,1].
*/

/* Problem Link
https://leetcode.com/problems/separate-the-digits-in-an-array/description/?envType=daily-question&envId=2026-05-11
*/

class Solution {
public:
    vector<int> digits(int num){
        vector<int> d;
        while(num>0){
            d.push_back(num%10);
            num/=10;
        }
        return d;
    }

    vector<int> separateDigits(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            vector<int> temp=digits(nums[i]);
            int m=temp.size();
            for(int j=m-1;j>=0;j--) res.push_back(temp[j]);
        }
        return res;
    }
};