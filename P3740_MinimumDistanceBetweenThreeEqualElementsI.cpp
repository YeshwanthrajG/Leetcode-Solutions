/* 
Problem ID : 3740 

Problem : Minimum Distance Between Three Equal Elements I

Statement : You are given an integer array nums.

A tuple (i, j, k) of 3 distinct indices is good if nums[i] == nums[j] == nums[k].

The distance of a good tuple is abs(i - j) + abs(j - k) + abs(k - i), where abs(x) denotes the absolute 
value of x.

Return an integer denoting the minimum possible distance of a good tuple. If no good tuples exist, 
return -1.
*/

/* Problem Link
https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/description/
*/

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int minIdx=INT_MAX;
        int n=nums.size();
        if(n<3) return -1;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                if(i==j) continue;
                if(nums[i]!=nums[j]) continue;
                for(int k=j+1;k<n;k++){
                    if(i==k || j==k) continue;
                    if(nums[j]==nums[k]){
                        int dist=abs(i-j)+abs(j-k)+abs(i-k);
                        minIdx=min(minIdx,dist);
                    }
                }
            }
        }
        return (minIdx==INT_MAX)?-1:minIdx;
    }
};