/* 
Problem ID : 2999 

Problem : Count the Number of Powerful Integers

Statement : You are given three integers start, finish, and limit. You are also given a 0-indexed string s 
representing a positive integer.

A positive integer x is called powerful if it ends with s (in other words, s is a suffix of x) and each 
digit in x is at most limit.

Return the total number of powerful integers in the range [start..finish].

A string x is a suffix of a string y if and only if x is a substring of y that starts from some 
index (including 0) in y and extends to the index y.length - 1. For example, 25 is a suffix of 5125 
whereas 512 is not.
*/

/* Problem Link
https://leetcode.com/problems/count-the-number-of-powerful-integers/description/
*/

class Solution {
    private Long[][] dp;
    private String suffix;
    private int limit;

    public long numberOfPowerfulInt(long start, long finish, int limit, String suffix) {
        this.limit = limit;
        this.suffix = suffix;

        long countToFinish = countValid(finish);
        long countToStart = countValid(start - 1);
        return countToFinish - countToStart;
    }

    private long countValid(long num) {
        if (num < Long.parseLong(suffix)) return 0;
        String numStr = Long.toString(num);
        dp = new Long[numStr.length()][2];
        return dfs(0, true, numStr);
    }

    private long dfs(int idx, boolean tight, String num) {
        if (idx == num.length()) return 1L;
        if (dp[idx][tight ? 1 : 0] != null) return dp[idx][tight ? 1 : 0];

        long res = 0;
        int maxDigit = tight ? num.charAt(idx) - '0' : 9;

        int suffixStart = num.length() - suffix.length();
        if (idx >= suffixStart) {
            int suffixIdx = idx - suffixStart;
            int digit = suffix.charAt(suffixIdx) - '0';
            if (digit <= maxDigit && digit <= limit)
                res += dfs(idx + 1, tight && digit == maxDigit, num);
        } else {
            for (int d = 0; d <= Math.min(maxDigit, limit); d++) {
                res += dfs(idx + 1, tight && d == maxDigit, num);
            }
        }
        return dp[idx][tight ? 1 : 0] = res;
    }
}