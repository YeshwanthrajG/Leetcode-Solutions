/* 
Problem ID : 38

Problem : Count and Say

Statement : The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the run-length encoding of countAndSay(n - 1).
Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical 
characters (repeated 2 or more times) with the concatenation of the character and the number marking the 
count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" 
with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed 
string becomes "23321511".

Given a positive integer n, return the nth element of the count-and-say sequence.
*/

/* Problem Link
https://leetcode.com/problems/count-and-say/description/?envType=daily-question&envId=2025-04-18
*/

class Solution {
    public String countAndSay(int n) {
        if (n == 1) return "1";
        
        String prev = countAndSay(n - 1);
        StringBuilder res = new StringBuilder();
        
        int i = 0;
        while (i < prev.length()) {
            int count = 1;
            while (i + 1 < prev.length() && prev.charAt(i) == prev.charAt(i + 1)) {
                i++;
                count++;
            }
            res.append(count).append(prev.charAt(i));
            i++;
        }
        
        return res.toString();
    }
}