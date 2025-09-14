/* 
Problem ID : 344 

Problem : Reverse String

Statement : Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.
*/

/* Problem Link
https://leetcode.com/problems/reverse-string/description/
*/

class Solution {
    public void reverseString(char[] s) {
        int left=0,right=s.length-1;
        while(left<right){
            char temp=s[right];
            s[right]=s[left];
            s[left]=temp;
            left++;
            right--;
        }
    }
}