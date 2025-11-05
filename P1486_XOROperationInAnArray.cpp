/* 
Problem ID : 1486 

Problem : XOR Operation in an Array

Statement : You are given an integer n and an integer start.

Define an array nums where nums[i] = start + 2 * i (0-indexed) and n == nums.length.

Return the bitwise XOR of all elements of nums.
*/

/* Problem Link
https://leetcode.com/problems/xor-operation-in-an-array/description/?envType=problem-list-v2&envId=prshgx6i
*/

class Solution {
public:
    int xorOperation(int n, int start) {
        int x=start;
        for(int i=0;i<n-1;i++){
            start+=2;
            x^=start;
        }
        return x;
    }
};