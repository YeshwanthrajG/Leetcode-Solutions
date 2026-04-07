/* 
Problem ID : 2164 

Problem : Sort Even and Odd Indices Independently

Statement : You are given a 0-indexed integer array nums. Rearrange the values of nums according to the 
following rules:

Sort the values at odd indices of nums in non-increasing order.
For example, if nums = [4,1,2,3] before this step, it becomes [4,3,2,1] after. The values at odd indices 
1 and 3 are sorted in non-increasing order.
Sort the values at even indices of nums in non-decreasing order.
For example, if nums = [4,1,2,3] before this step, it becomes [2,1,4,3] after. The values at even indices 
0 and 2 are sorted in non-decreasing order.
Return the array formed after rearranging the values of nums.
*/

/* Problem Link
https://leetcode.com/problems/sort-even-and-odd-indices-independently/description/
*/

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd, even;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i%2==0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        sort(even.rbegin(), even.rend());
        sort(odd.begin(), odd.end());
        for(int i=0;i<n;i++){
            if(i%2==0){
                nums[i]=even.back();
                even.pop_back();
            }
            else{
                nums[i]=odd.back();
                odd.pop_back();
            }
        }
        return nums;
    }
};