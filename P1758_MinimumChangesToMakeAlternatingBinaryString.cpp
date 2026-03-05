/* 
Problem ID : 1758 

Problem : Minimum Changes To Make Alternating Binary String

Statement : You are given a string s consisting only of the characters '0' and '1'. 
In one operation, you can change any '0' to '1' or vice versa.

The string is called alternating if no two adjacent characters are equal. For example, 
the string "010" is alternating, while the string "0100" is not.

Return the minimum number of operations needed to make s alternating.
*/

/* Problem Link
https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/?envType=daily-question&envId=2026-03-05
*/

class Solution {
public:
    int minOperations(string s) {
        int start1=0;
        int count1=0;
        for(char c:s){
            if(start1!=(c-'0')) count1++;
            start1^=1;
        }
        int start2=1;
        int count2=0;
        for(char c:s){
            if(start2!=(c-'0')) count2++;
            start2^=1;
        }
        return min(count1, count2);
    }
};