/* 
Problem ID : 2200 

Problem : Find All K-Distant Indices in an Array

Statement : You are given a 0-indexed integer array nums and two integers key and k. A k-distant index is an 
index i of nums for which there exists at least one index j such that |i - j| <= k and nums[j] == key.

Return a list of all k-distant indices sorted in increasing order. 
*/

/* Problem Link
https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/description/?envType=daily-question&envId=2025-06-24
*/

class Solution {
    public List<Integer> findKDistantIndices(int[] nums, int key, int k) {
        Set<Integer> res=new HashSet<>();
        int n=nums.length;
        for(int i=0;i<n;i++){
            if(nums[i]==key){
                for(int j=0;j<n;j++){
                    if(Math.abs(i-j)<=k){
                        res.add(j);
                    }
                }
            }
        }
        List<Integer> ans=new ArrayList<>(res);

        Collections.sort(ans);
        return ans;
    }
}