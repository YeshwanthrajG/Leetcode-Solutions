/* 
Problem ID : 3755 

Problem : Find Maximum Balanced XOR Subarray Length

Statement : Given an integer array nums, return the length of the longest subarray that has a 
bitwise XOR of zero and contains an equal number of even and odd numbers. 
If no such subarray exists, return 0.
*/

/* Problem Link
https://leetcode.com/problems/find-maximum-balanced-xor-subarray-length/description/
*/

class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        unordered_map<long long, int> first;
        long long xorP=0;
        long long balP=0;
        int n=nums.size();
        int ans=0;
        auto key=[&](long long x, long long b){
            return (x<<32) ^ (b&0xffffffff);
        };
        first[key(0,0)] =-1;
        for(int i=0;i<n;i++){
            xorP^=nums[i];
            balP+=(nums[i]%2==0?1:-1);
            long long k=key(xorP, balP);
            if(first.count(k)){
                ans=max(ans, i-first[k]);
            }
            else{
                first[k]=i;
            }
        }
        return ans;
    }
};