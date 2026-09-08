/* 
Problem ID : 3870 

Problem : Count Commas in Range

Statement : You are given an integer n.

Return the total number of commas used when writing all integers from [1, n] (inclusive) in standard 
number formatting.

In standard formatting:

A comma is inserted after every three digits from the right.
Numbers with fewer than 4 digits contain no commas.
*/

/* Problem Link
https://leetcode.com/problems/count-commas-in-range/description/?envType=daily-question&envId=2026-09-08
*/

class Solution {
public:
    int countCommas(int n) {
        int total=0;
        for(int i=1;i<=n;i++){
            int digits=to_string(i).size();
            total+=(digits-1)/3;
        }
        return total;
    }
};