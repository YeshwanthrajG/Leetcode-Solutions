/* 
Problem ID : 1323 

Problem : Maximum 69 Number

Statement : You are given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).
*/

/* Problem Link
https://leetcode.com/problems/maximum-69-number/description/?envType=daily-question&envId=2025-08-16
*/

class Solution {
    public int maximum69Number (int num) {
        char n[]=String.valueOf(num).toCharArray();
        for(int i=0;i<n.length;i++){
            if(n[i]=='6'){
                n[i]='9';
                break;
            }
        }
        return Integer.parseInt(new String(n));
    }
}