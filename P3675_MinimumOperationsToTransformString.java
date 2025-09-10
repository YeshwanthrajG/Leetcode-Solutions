/* 
Problem ID : 3675 

Problem : Minimum Operations to Transform String

Statement : You are given a string s consisting only of lowercase English letters.

You can perform the following operation any number of times (including zero):

Choose any character c in the string and replace every occurrence of c with the next lowercase letter in the English 
alphabet.

Return the minimum number of operations required to transform s into a string consisting of only 'a' characters.

Note: Consider the alphabet as circular, thus 'a' comes after 'z'.
*/

/* Problem Link
https://leetcode.com/problems/minimum-operations-to-transform-string/description/
*/

class Solution {
    public int minOperations(String s) {
        int operations=0;
        for(char c: s.toCharArray()){
            int steps=(('a'-c+26)%26);
            operations=Math.max(operations,steps);
        }
        return operations;
    }
}