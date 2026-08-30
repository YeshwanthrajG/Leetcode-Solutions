/* 
Problem ID : 2091 

Problem : Removing Minimum and Maximum From Array

Statement : You are given a 0-indexed array of distinct integers nums.

There is an element in nums that has the lowest value and an element that has the highest value. We call them 
the minimum and maximum respectively. Your goal is to remove both these elements from the array.

A deletion is defined as either removing an element from the front of the array or removing an element 
from the back of the array.

Return the minimum number of deletions it would take to remove both the minimum and maximum element 
rom the array.
*/

/* Problem Link
https://leetcode.com/problems/removing-minimum-and-maximum-from-array/description/?envType=daily-question&envId=2026-08-30
*/

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return n;
        int minVal=nums[0], minIdx=0;
        int maxVal=nums[0], maxIdx=0;
        for(int i=1;i<n;i++){
            if(minVal>nums[i]){
                minVal=nums[i];
                minIdx=i;
            }
            if(maxVal<nums[i]){
                maxVal=nums[i];
                maxIdx=i;
            }
        }
        int l=min(minIdx, maxIdx);
        int r=max(minIdx, maxIdx);
        int bl=r+1;
        int br=n-l;
        int opp=l+1+n-r;
        return min({bl, br, opp});
    }
};