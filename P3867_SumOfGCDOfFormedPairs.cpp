/* 
Problem ID : 3867 

Problem : Sum of GCD of Formed Pairs

Statement : You are given an integer array nums of length n.

Construct an array prefixGcd where for each index i:

Let mxi = max(nums[0], nums[1], ..., nums[i]).
prefixGcd[i] = gcd(nums[i], mxi).
After constructing prefixGcd:

Sort prefixGcd in non-decreasing order.
Form pairs by taking the smallest unpaired element and the largest unpaired element.
Repeat this process until no more pairs can be formed.
For each formed pair, compute the gcd of the two elements.
If n is odd, the middle element in the prefixGcd array remains unpaired and should be ignored.
Return an integer denoting the sum of the GCD values of all formed pairs.

The term gcd(a, b) denotes the greatest common divisor of a and b.
*/

/* Problem Link
https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/description/?envType=daily-question&envId=2026-07-16
*/

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long> prefix(n);
        long long mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx, (long long)nums[i]);
            prefix[i]=gcd((long long)nums[i], mx);
        }
        sort(prefix.begin(), prefix.end());
        long long res=0;
        int l=0, r=n-1;
        while(l<r){
            res+=gcd(prefix[l], prefix[r]);
            l++;
            r--;
        }
        return res;
    }
};