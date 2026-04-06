/* 
Problem ID : 922 

Problem : Sort Array By Parity II

Statement : Given an array of integers nums, half of the integers in nums are odd, and the other half 
are even.

Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.

Return any answer array that satisfies this condition.
*/

/* Problem Link
https://leetcode.com/problems/sort-array-by-parity-ii/description/
*/

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        bool toggle=true;
        int n=nums.size();
        int curr=0, place=0;
        for(int i=0;i<n-1;i++){
            curr=i;
            place=i+1;
            while((nums[curr]%2)!=(curr%2) && curr<n){
                swap(nums[curr], nums[place]);
                place++;
            }
            curr++;
            toggle=!toggle;
        }
        return nums;
    }
};