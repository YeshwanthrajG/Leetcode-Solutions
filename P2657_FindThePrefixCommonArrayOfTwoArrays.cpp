/* 
Problem ID : 2657 

Problem : Find the Prefix Common Array of Two Arrays

Statement : You are given two 0-indexed integer permutations A and B of length n.

A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are 
present at or before the index i in both A and B.

Return the prefix common array of A and B.

A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.
*/

/* Problem Link
https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/?envType=daily-question&envId=2026-05-20
*/

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> map;
        int count=0;
        for(int i=0;i<A.size();i++){
            if(A[i]==B[i]){
                map[A[i]]+=2;
                count++;
            }
            else{
                map[A[i]]++;
                map[B[i]]++;
                if(map[A[i]]==2) count++;
                if(map[B[i]]==2) count++;
            }
            A[i]=count;
        }
        return A;
    }
};