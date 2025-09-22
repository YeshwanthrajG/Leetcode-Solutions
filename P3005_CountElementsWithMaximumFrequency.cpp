/* 
Problem ID : 3005 

Problem : Count Elements With Maximum Frequency

Statement : You are given an array nums consisting of positive integers.

Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

The frequency of an element is the number of occurrences of that element in the array.
*/

/* Problem Link
https://leetcode.com/problems/count-elements-with-maximum-frequency/description/?envType=daily-question&envId=2025-09-22
*/

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int count=0;
        vector<int> bucket(101,0);
        int maxVal=0;
        for(int i=0;i<nums.size();i++){
            bucket[nums[i]]++;
            maxVal=max(maxVal,bucket[nums[i]]);
        }
        for(int i=0;i<bucket.size();i++){
            if(maxVal==bucket[i]){
                count+=bucket[i];
            }
        }
        return count;
    }
};