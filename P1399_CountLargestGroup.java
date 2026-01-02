/* 
Problem ID : 1399 

Problem : Count Largest Group

Statement : You are given an integer n.

Each number from 1 to n is grouped according to the sum of its digits.

Return the number of groups that have the largest size.
*/

/* Problem Link
https://leetcode.com/problems/count-largest-group/description/?envType=daily-question&envId=2025-04-23
*/

class Solution {
    public int countLargestGroup(int n) {
        Map<Integer, Integer> map = new HashMap<>();
        int maxSize = 0;
        for (int i = 1; i <= n; i++) {
            int sum = 0, num = i;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            map.put(sum, map.getOrDefault(sum, 0) + 1);
            maxSize = Math.max(maxSize, map.get(sum));
        }

        int count = 0;
        for (int val : map.values()) {
            if (val == maxSize) count++;
        }
        return count;
    }
}