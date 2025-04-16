/* 
Problem ID : 2179 

Problem : Count Good Triplets in an Array

Statement : You are given two 0-indexed arrays nums1 and nums2 of length n, both of which are permutations of 
[0, 1, ..., n - 1].

A good triplet is a set of 3 distinct values which are present in increasing order by position both in nums1 
and nums2. In other words, if we consider pos1v as the index of the value v in nums1 and pos2v as the index 
of the value v in nums2, then a good triplet will be a set (x, y, z) where 0 <= x, y, z <= n - 1, such that 
pos1x < pos1y < pos1z and pos2x < pos2y < pos2z.

Return the total number of good triplets.

/* Problem Link
https://leetcode.com/problems/count-good-triplets-in-an-array/?envType=daily-question&envId=2025-04-15
*/

class Solution {
    public long goodTriplets(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> mpp = new HashMap<>();
        for (int i = 0; i < nums1.length; i++) mpp.put(nums1[i], i);
        int n = nums2.length;
        long total = 0;
        ArrayList<Integer> st = new ArrayList<>();
        for (int x : nums2) {
            int idx = mpp.get(x);
            int left = orderOfKey(st, idx);
            int right = (n - 1 - idx) - (st.size() - left);
            total += (long) left * right;
            int pos = Collections.binarySearch(st, idx);
            if (pos < 0) pos = -pos - 1;
            st.add(pos, idx);
        }
        return total;
    }
    
    private int orderOfKey(ArrayList<Integer> st, int key) {
        int pos = Collections.binarySearch(st, key);
        return pos < 0 ? -pos - 1 : pos;
    }
}
