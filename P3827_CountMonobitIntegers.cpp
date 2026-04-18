/* 
Problem ID : 3827 

Problem : Count Monobit Integers

Statement : You are given an integer n.

An integer is called Monobit if all bits in its binary representation are the same.

Return the count of Monobit integers in the range [0, n] (inclusive).
*/

/* Problem Link
https://leetcode.com/problems/count-monobit-integers/description/
*/

// Approach 1

class Solution {
public:
    int countMonobit(int n) {
        vector<int> monobits;
        monobits.push_back(0);
        int i=1;
        int curr=pow(2,i)-1;
        while(curr<=1000) {
            monobits.push_back(curr);
            i++;
            curr=pow(2,i)-1;
        }
        int count=0;
        int size=monobits.size();
        for(int i=0;i<size;i++){
            if(monobits[i]>n) return count;
            count++;
        }
        return count;
    }
};

// Approach 2

class Solution {
public:
    int countMonobit(int n) {
        return 1+log2(n+1);
    }
};