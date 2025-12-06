/* 
Problem ID : 3761 

Problem : Minimum Absolute Distance Between Mirror Pairs

Statement : You are given an integer array nums.

A mirror pair is a pair of indices (i, j) such that:

0 <= i < j < nums.length, and
reverse(nums[i]) == nums[j], where reverse(x) denotes the integer formed by reversing the digits of x. 
Leading zeros are omitted after reversing, for example reverse(120) = 21.
Return the minimum absolute distance between the indices of any mirror pair. The absolute distance 
between indices i and j is abs(i - j).

If no mirror pair exists, return -1.
*/

/* Problem Link
https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/description/
*/

class Solution {
public:
    int reverse(int x) {
        long long rev=0;
        while(x>0){
            rev=rev*10+(x%10);
            x/=10;
        }
        return (int)rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> lastPos;
        int n=nums.size();
        lastPos.reserve(n*2);
        for(int i=0;i<n;i++) lastPos[nums[i]].push_back(i);
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int revVal=reverse(nums[i]);
            auto it=lastPos.find(revVal);
            if(it==lastPos.end()) continue;
            const vector<int>& arr=it->second;
            auto ub=upper_bound(arr.begin(), arr.end(), i);
            if(ub!=arr.end()){
                int j=*ub;
                ans=min(ans, (j-i));
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};