/* 
Problem ID : 1390 

Problem : Four Divisors

Statement : Given an integer array nums, return the sum of divisors of the integers in that array that 
have exactly four divisors. If there is no such integer in the array, return 0.
*/

/* Problem Link
https://leetcode.com/problems/four-divisors/description/?envType=daily-question&envId=2026-01-04
*/

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            int count=0;
            int a_sum=0;
            for(int j=1;j<=nums[i]/2;j++){
                if(nums[i]%j==0){
                    a_sum+=j;
                    count++;
                }
                if(count>3) break;
            }
            if(count==3) sum+=(a_sum+nums[i]);
        }
        return sum;
    }
};