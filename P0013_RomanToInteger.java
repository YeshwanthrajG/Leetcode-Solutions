/* 
Problem ID : 13 

Problem : Roman to Integer

Statement : Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is 
simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. 
Instead, the number four is written as IV. Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.
*/

/* Problem Link
https://leetcode.com/problems/roman-to-integer/description/
*/

class Solution {
    public int romanToInt(String s) {
        int res=0;
        int curr=0;
        int prev=Integer.MAX_VALUE;
        for(char ch:s.toCharArray()){
            curr=value(ch);
            res+=curr;
            if(prev<curr){
                res-=prev*2;
            }
            prev=curr;
        }
        return res;
    }
    private static int value(char c){
        if(c=='I')  return 1;
        if(c=='V')  return 5;
        if(c=='X')  return 10;
        if(c=='L')  return 50;
        if(c=='C')  return 100;
        if(c=='D')  return 500;
        if(c=='M')  return 1000;
        else return 0;
    }
}