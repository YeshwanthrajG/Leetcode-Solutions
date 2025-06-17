/* 
Problem ID : 2929 

Problem : Distribute Candies Among Children II

Statement : You are given two positive integers n and limit.

Return the total number of ways to distribute n candies among 3 children such that no child gets more than 
limit candies.
*/

/* Problem Link
https://leetcode.com/problems/distribute-candies-among-children-ii/description/?envType=daily-question&envId=2025-06-01
*/

class Solution {
    public long distributeCandies(int n, int limit) {
        long res = 0;
        for (int i = 0; i <= Math.min(limit, n); i++) {
            if (n - i <= 2 * limit)
                res += Math.min(n - i, limit) - Math.max(0, n - i - limit) + 1;
        }
        return res;
    }
}