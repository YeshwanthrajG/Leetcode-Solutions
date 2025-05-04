/* 
Problem ID : 1128 

Problem : Number of Equivalent Domino Pairs

Statement : Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if 
and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be 
equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to 
dominoes[j].
*/

/* Problem Link
https://leetcode.com/problems/number-of-equivalent-domino-pairs/description/?envType=daily-question&envId=2025-05-04
*/


class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        Map<String, Integer> countMap = new HashMap<>();
        int count = 0;

        for (int[] d : dominoes) {
            int a = Math.min(d[0], d[1]);
            int b = Math.max(d[0], d[1]);
            String key = a + "," + b;
            count += countMap.getOrDefault(key, 0);
            countMap.put(key, countMap.getOrDefault(key, 0) + 1);
        }

        return count;
    }
}

