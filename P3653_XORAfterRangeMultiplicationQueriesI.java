/* 
Problem ID : 3653 

Problem : XOR After Range Multiplication Queries I

Statement : You are given an integer array nums of length n and a 2D integer array queries of size q, 
where queries[i] = [li, ri, ki, vi].

For each query, you must apply the following operations in order:

Set idx = li.
While idx <= ri:
Update: nums[idx] = (nums[idx] * vi) % (109 + 7)
Set idx += ki.
Return the bitwise XOR of all elements in nums after processing all queries.
*/

/* Problem Link
https://leetcode.com/problems/xor-after-range-multiplication-queries-i/description/
*/

class Solution {
    public int xorAfterQueries(int[] nums, int[][] queries) {
        int modVal=(int)Math.pow(10,9)+7;
        for(int[] q:queries){
            int li=q[0],ri=q[1],ki=q[2],vi=q[3];
            for(int idx=li;idx<=ri;idx+=ki){
                nums[idx]=(int)(((long)nums[idx]*vi)%modVal);
            }
        }
        int XOR=0;
        for(int n:nums) XOR^=n;
        return XOR;
    }
}