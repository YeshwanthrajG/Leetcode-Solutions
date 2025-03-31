/* 
Problem ID : 2560 

Problem : House Robber IV

Statement : There are several consecutive houses along a street, each of which has some money inside. 
There is also a robber, who wants to steal money from the homes, but he refuses to steal from adjacent homes.

The capability of the robber is the maximum amount of money he steals from one house of all the houses he 
robbed.

You are given an integer array nums representing how much money is stashed in each house. More formally, 
the ith house from the left has nums[i] dollars.

You are also given an integer k, representing the minimum number of houses the robber will steal from. 
It is always possible to steal at least k houses.

Return the minimum capability of the robber out of all the possible ways to steal at least k houses.
*/

/* Problem Link
https://leetcode.com/problems/house-robber-iv/description/?envType=daily-question&envId=2025-03-15
*/

class Solution {
    public boolean canRob(int[] nums, int mid, int k) {
        int count = 0, n = nums.length;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= mid) {
                count++;
                i++;
            }
        }
        return count >= k;
    }

    public int minCapability(int[] nums, int k) {
        int left = 1, right = Arrays.stream(nums).max().getAsInt(), ans = right;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (canRob(nums, mid, k)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
}
