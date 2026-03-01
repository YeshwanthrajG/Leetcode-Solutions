/* 
Problem ID : 1689 

Problem : Partitioning Into Minimum Number Of Deci-Binary Numbers

Statement : A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. 
For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.

Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary 
numbers needed so that they sum up to n.
*/

/* Problem Link
https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/description/?envType=daily-question&envId=2026-03-01
*/

class Solution {
public:
    int minPartitions(string n) {
        char maxChar='0';
        for(char c:n){
            if(c>maxChar) maxChar=c;
        }
        return maxChar-'0';
    }
};