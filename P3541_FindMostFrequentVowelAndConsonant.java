/* 
Problem ID : 3541 

Problem : Find Most Frequent Vowel and Consonant

Statement : You are given a string s consisting of lowercase English letters ('a' to 'z').

Your task is to:

Find the vowel (one of 'a', 'e', 'i', 'o', or 'u') with the maximum frequency.
Find the consonant (all other letters excluding vowels) with the maximum frequency.
Return the sum of the two frequencies.

Note: If multiple vowels or consonants have the same maximum frequency, you may choose any one of them. 
If there are no vowels or no consonants in the string, consider their frequency as 0.

The frequency of a letter x is the number of times it occurs in the string.
*/

/* Problem Link
https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/description/?envType=daily-question&envId=2025-09-13
*/

class Solution {
    public int maxFreqSum(String s) {
        HashMap<Character,Integer> vowel=new HashMap<>();
        HashMap<Character,Integer> consonant=new HashMap<>();
        int maxVow=0;
        int maxCon=0;

        for(char ch:s.toCharArray()){
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                vowel.put(ch,vowel.getOrDefault(ch,0)+1);
                maxVow=Math.max(maxVow,vowel.getOrDefault(ch,0));
            }
            else{
                consonant.put(ch,consonant.getOrDefault(ch,0)+1);
                maxCon=Math.max(maxCon,consonant.getOrDefault(ch,0));
            }
        }
        return maxVow+maxCon;
    }
}