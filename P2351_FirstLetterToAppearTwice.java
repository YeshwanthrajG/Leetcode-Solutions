/* 
Problem ID : 2351 

Problem : First Letter to Appear Twice

Statement : Given a string s consisting of lowercase English letters, return the first letter to appear twice.

Note:

A letter a appears twice before another letter b if the second occurrence of a is before the second occurrence of b.
s will contain at least one letter that appears twice.
*/

/* Problem Link
https://leetcode.com/problems/first-letter-to-appear-twice/
*/

class Solution {
    public char repeatedCharacter(String s) {
        Set<Character> set=new HashSet<>();
        for(char ch:s.toCharArray()){
            if(set.contains(ch))    return ch;
            else set.add(ch);
        }
        return '0';
    }
}