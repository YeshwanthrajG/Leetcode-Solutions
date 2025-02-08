/* 
Problem ID : 916 

Problem : Word Subsets

Statement : You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.
*/

/* Problem Link
https://leetcode.com/problems/word-subsets/description/
*/
import java.util.*;

class Subset {
    public List<String> wordSubsets(String[] words1, String[] words2) {
        int[] req = new int[26];
        for (String word : words2) {
            int[] cur = new int[26];
            for (char c : word.toCharArray()) {
                cur[c - 'a']++;
                req[c - 'a'] = Math.max(req[c - 'a'], cur[c - 'a']);
            }
        }
        
        List<String> ans = new ArrayList<>();
        for (String word : words1) {
            int[] cur = new int[26];
            for (char c : word.toCharArray()) cur[c - 'a']++;
            
            boolean isValid = true;
            for (int i = 0; i < 26; i++) {
                if (cur[i] < req[i]) {
                    isValid = false;
                    break;
                }
            }
            
            if (isValid) ans.add(word);
        }
        
        return ans;
    }
}