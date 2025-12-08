/* 
Problem ID : 1925 

Problem : Count Square Sum Triples

Statement : A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.

Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.
*/

/* Problem Link
https://leetcode.com/problems/count-square-sum-triples/description/?envType=daily-question&envId=2025-12-08
*/

class Solution {
public:
    int countTriples(int n) {
        int res=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                double k=sqrt(i*i + j*j);
                if(k<=n && k==(int)k) res+=2;
            }
        }
        return res;
    }
};