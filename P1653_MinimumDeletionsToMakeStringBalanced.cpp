/* 
Problem ID : 1653 

Problem : Minimum Deletions to Make String Balanced

Statement : You are given a string s consisting only of characters 'a' and 'b'​​​​.

You can delete any number of characters in s to make s balanced. s is balanced if there is no 
pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.

Return the minimum number of deletions needed to make s balanced.
*/

/* Problem Link
https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/?envType=daily-question&envId=2026-02-07
*/

class Solution {
public:
    int minimumDeletions(string s) {
        int res=0, b=0;
        for(auto &c:s){
            if(c=='b') b++;
            else if(b){
                res++;
                b--;
            }
        }
        return res;
    }
};
