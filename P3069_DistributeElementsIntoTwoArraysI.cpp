/* 
Problem ID : 3069 

Problem : Distribute Elements Into Two Arrays I

Statement : You are given a 1-indexed array of distinct integers nums of length n.

You need to distribute all the elements of nums between two arrays arr1 and arr2 using n operations. 
In the first operation, append nums[1] to arr1. In the second operation, append nums[2] to arr2. 
Afterwards, in the ith operation:

If the last element of arr1 is greater than the last element of arr2, append nums[i] to arr1. 
Otherwise, append nums[i] to arr2.
The array result is formed by concatenating the arrays arr1 and arr2. For example, if arr1 == [1,2,3] 
and arr2 == [4,5,6], then result = [1,2,3,4,5,6].

Return the array result.
*/

/* Problem Link
https://leetcode.com/problems/distribute-elements-into-two-arrays-i/description/?envType=daily-question&envId=2026-08-20
*/

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
       vector<int> arr1, arr2;
       int n=nums.size();
       arr1.push_back(nums[0]);
       arr2.push_back(nums[1]);
       int a1=nums[0], a2=nums[1];
       for(int i=2;i<n;i++){
           if(a1>a2){
               arr1.push_back(nums[i]);
               a1=nums[i];
           }
           else {
               arr2.push_back(nums[i]);
               a2=nums[i];
           }
       }
       for(int i:arr2){
           arr1.push_back(i);
       }
       return arr1;
    }
};