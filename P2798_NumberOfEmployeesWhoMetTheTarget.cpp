/* 
Problem ID : 2798 

Problem : Number of Employees Who Met the Target

Statement : There are n employees in a company, numbered from 0 to n - 1. Each employee i has worked 
for hours[i] hours in the company.

The company requires each employee to work for at least target hours.

You are given a 0-indexed array of non-negative integers hours of length n and a non-negative integer 
target.

Return the integer denoting the number of employees who worked at least target hours.
*/

/* Problem Link
https://leetcode.com/problems/number-of-employees-who-met-the-target/description/?envType=problem-list-v2&envId=prshgx6i
*/

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int res=0;
        for(auto& a:hours) {
            if(a>=target) res++;
        }
        return res;
    }
};