/* 
Problem ID : 2011 

Problem : Final Value of Variable After Performing Operations

Statement : There is a programming language with only four operations and one variable X:

++X and X++ increments the value of the variable X by 1.
--X and X-- decrements the value of the variable X by 1.
Initially, the value of X is 0.

Given an array of strings operations containing a list of operations, return the final value of X 
after performing all the operations.
*/

/* Problem Link
https://leetcode.com/problems/final-value-of-variable-after-performing-operations/description/?envType=daily-question&envId=2025-10-20
*/

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res=0;
        for(string&i: operations){
            if(i[1]=='+') res++;
            else res--;
        }
        return res;
    }
};