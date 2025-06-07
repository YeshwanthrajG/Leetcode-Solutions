/* 
Problem ID : 3170 

Problem : Lexicographically Minimum String After Removing Stars

Statement : You are given a string s. It may contain any number of '*' characters. 
Your task is to remove all '*' characters.

While there is a '*', do the following operation:

Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest 
characters, you can delete any of them.
Return the lexicographically smallest resulting string after removing all '*' characters. 
*/

/* Problem Link
https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/description/?envType=daily-question&envId=2025-06-07
*/

import java.util.*;

class Solution {
    public String clearStars(String s) {
        int n = s.length();
        PriorityQueue<Character> pq = new PriorityQueue<>();
        Map<Character, Deque<Integer>> map = new HashMap<>();
        boolean[] keep = new boolean[n];
        Arrays.fill(keep, true);

        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (c == '*') {
                char smallest = pq.poll();
                int indexToRemove = map.get(smallest).removeLast();
                keep[i] = false;               // Remove '*'
                keep[indexToRemove] = false;   // Remove smallest char
            } else {
                pq.offer(c);
                map.putIfAbsent(c, new ArrayDeque<>());
                map.get(c).add(i);
            }
        }

        StringBuilder result = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (keep[i]) {
                result.append(s.charAt(i));
            }
        }

        return result.toString();
    }
}
