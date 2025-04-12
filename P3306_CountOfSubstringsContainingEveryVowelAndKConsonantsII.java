/* 
Problem ID : 3306 

Problem : Count of Substrings Containing Every Vowel and K Consonants II

Statement :You are given a string word and a non-negative integer k.

Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at 
least once and exactly k consonants.
*/

/* Problem Link
https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/description/?envType=daily-question&envId=2025-03-10
*/

class Solution {
    private boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    private long atLeastK(String word, int k) {
        int n = word.length();
        long ans = 0;
        int consonants = 0;
        int left = 0;
        HashMap<Character, Integer> vowelMap = new HashMap<>();

        for (int right = 0; right < n; right++) {
            char c = word.charAt(right);
            if (isVowel(c)) {
                vowelMap.put(c, vowelMap.getOrDefault(c, 0) + 1);
            } else {
                consonants++;
            }

            while (vowelMap.size() == 5 && consonants >= k) {
                ans += n - right;
                char leftChar = word.charAt(left);
                if (isVowel(leftChar)) {
                    vowelMap.put(leftChar, vowelMap.get(leftChar) - 1);
                    if (vowelMap.get(leftChar) == 0) {
                        vowelMap.remove(leftChar);
                    }
                } else {
                    consonants--;
                }
                left++;
            }
        }
        return ans;
    }

    public long countOfSubstrings(String word, int k) {
        return atLeastK(word, k) - atLeastK(word, k + 1);
    }
}