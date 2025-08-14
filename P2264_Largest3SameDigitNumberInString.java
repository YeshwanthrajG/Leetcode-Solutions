/* 
Problem ID : 2264 

Problem : Largest 3-Same-Digit Number in String

Statement : You are given a string num representing a large integer. An integer is good if it meets the following 
conditions:

It is a substring of num with length 3.
It consists of only one unique digit.
Return the maximum good integer as a string or an empty string "" if no such integer exists.

Note:

A substring is a contiguous sequence of characters within a string.
There may be leading zeroes in num or a good integer.
*/

/* Problem Link
https://leetcode.com/problems/largest-3-same-digit-number-in-string/description/?envType=daily-question&envId=2025-08-14
*/

class Solution {
    public String largestGoodInteger(String num) {
        // String res="";
        for(int i=9;i>=1;i--){
            int n=i*100+i*10+i;
            String sub=String.valueOf(n);
            if(num.contains(sub)){
                return sub;
            }
        }
        if(num.contains("000")) return "000";
        return "";
    }
}