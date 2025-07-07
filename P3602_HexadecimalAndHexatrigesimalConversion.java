/* 
Problem ID : 3602 

Problem : Hexadecimal and Hexatrigesimal Conversion

Statement : You are given an integer n.
Return the concatenation of the hexadecimal representation of n2 and the hexatrigesimal representation of n3.

A hexadecimal number is defined as a base-16 numeral system that uses the digits 0 – 9 and the uppercase 
letters A - F to represent values from 0 to 15.

A hexatrigesimal number is defined as a base-36 numeral system that uses the digits 0 – 9 and the uppercase 
letters A - Z to represent values from 0 to 35.
*/

/* Problem Link
https://leetcode.com/problems/hexadecimal-and-hexatrigesimal-conversion/description/
*/

class Solution {
    public String concatHex36(int n) {
        StringBuffer buff=new StringBuffer();
        String str=new String();
        return ""+findHex((int)Math.pow(n,2))+findTriges((int)Math.pow(n,3));
    }
    public String findHex(int n){
        String hex="0123456789ABCDEF";
        if(n==0) return "0";
        StringBuilder res=new StringBuilder();
        while(n>0){
            res.insert(0,hex.charAt(n%16));
            n/=16;
        }
        return res.toString();
        
    }
    public String findTriges(int n){
        String tri="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
           if(n==0) return "0";
        StringBuilder res=new StringBuilder();
        while(n>0){
            res.insert(0,tri.charAt(n%36));
            n/=36;
        }
        return res.toString();
    }
    
}