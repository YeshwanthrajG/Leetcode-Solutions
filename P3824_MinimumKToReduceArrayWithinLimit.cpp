/* 
Problem ID : 3824 

Problem : Minimum K to Reduce Array Within Limit

Statement : You are given a positive integer array nums.

For a positive integer k, define nonPositive(nums, k) as the minimum number of operations needed to make 
every element of nums non-positive. In one operation, you can choose an index i and reduce nums[i] by k.

Return an integer denoting the minimum value of k such that nonPositive(nums, k) <= k2.
*/

/* Problem Link
https://leetcode.com/problems/minimum-k-to-reduce-array-within-limit/description/
*/

class Solution {
public:
    int minimumK(vector<int>& nums) {
        int left=1, right=1000000;
        int mini=right;
        while(left<=right){
            int k=left+(right-left)/2;
            long long opr=0;
            for(int x:nums){
                opr+=(x+k-1)/k;
                if(opr>1LL*k*k){
                    break;
                }
            }
            if(opr<=1LL*k*k){
                mini=k;
                right=k-1;
            }
            else{
                left=k+1;
            }
        }
        return mini;
    }
};