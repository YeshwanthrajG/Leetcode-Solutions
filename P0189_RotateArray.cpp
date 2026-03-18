/* 
Problem ID : 189 

Problem : Rotate Array

Statement : Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
*/

/* Problem Link
https://leetcode.com/problems/rotate-array/description/?envType=problem-list-v2&envId=w9kfviyj
*/

class Solution {
public:
    void reverse(vector<int>& nums, int i, int j){
        int temp=0;
        while(i<j){
            temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
            i++;
            j--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
    }
};