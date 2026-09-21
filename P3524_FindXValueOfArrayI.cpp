/* 
Problem ID : 3524 

Problem : Find X Value of Array I

Statement : You are given an array of positive integers nums, and a positive integer k.

You are allowed to perform an operation once on nums, where in each operation you can remove any 
non-overlapping prefix and suffix from nums such that nums remains non-empty.

You need to find the x-value of nums, which is the number of ways to perform this operation so that 
the product of the remaining elements leaves a remainder of x when divided by k.

Return an array result of size k where result[x] is the x-value of nums for 0 <= x <= k - 1.

A prefix of an array is a subarray that starts from the beginning of the array and extends to any 
point within it.

A suffix of an array is a subarray that starts at any point within the array and extends to the 
end of the array.

Note that the prefix and suffix to be chosen for the operation can be empty.
*/

/* Problem Link
https://leetcode.com/problems/find-x-value-of-array-i/description/?envType=daily-question&envId=2026-09-21
*/

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> res(k);
        vector<int> freq(5, 0);
        for(auto &x:nums){
            x%=k;
            vector<int> temp(5,0);
            temp[x]=1;
            for(int i=0;i<k;i++){
                temp[i*x%k]+=freq[i];
            }
            for(int i=0;i<k;i++){
                freq[i]=temp[i];
                res[i]+=freq[i];
            }
        }
        return res;
    }
};