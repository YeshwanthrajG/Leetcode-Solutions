/* 
Problem ID : 1832 

Problem : Check if the Sentence Is Pangram

Statement : A pangram is a sentence where every letter of the English alphabet appears at least once.

Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false 
otherwise.
*/

/* Problem Link
https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/?envType=problem-list-v2&envId=prshgx6i
*/

class Solution {
    public boolean checkIfPangram(String sentence) { 
        if(sentence.length()<26)  return false;
        Set<Character> set=new HashSet<>();
        for(char ch:sentence.toCharArray()){
            set.add(ch);
            if(set.size()==26)  return true;
        }
        return set.size()==26;
    }
}