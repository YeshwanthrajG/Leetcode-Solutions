/* 
Problem ID : 611 

Problem : Valid Triangle Number

Statement : Given an integer array nums, return the number of triplets chosen from the array that can make 
triangles if we take them as side lengths of a triangle.
*/

/* Problem Link
https://leetcode.com/problems/valid-triangle-number/description/?envType=daily-question&envId=2025-09-26
*/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int count=0;
        for(int i=n-1;i>=2;i--){
            int l=0,r=i-1;
            while(l<r){
                if(nums[l]+nums[r]>nums[i]){
                    count+=r-l;
                    r--;
                }
                else l++;
            }
        }
    return count;
    }
};