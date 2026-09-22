/* 
Problem ID : 2761 

Problem : Prime Pairs With Target Sum

Statement : You are given an integer n. We say that two integers x and y form a prime number pair if:

1 <= x <= y <= n
x + y == n
x and y are prime numbers
Return the 2D sorted list of prime number pairs [xi, yi]. The list should be sorted in 
increasing order of xi. If there are no prime number pairs at all, return an empty array.

Note: A prime number is a natural number greater than 1 with only two factors, itself and 1.
*/

/* Problem Link
https://leetcode.com/problems/prime-pairs-with-target-sum/description/
*/

class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        if(n<3) return {};
        vector<vector<int>> pairs;
        for(int i=2;i<=n/2;i++){
            if(isPrime(i) && isPrime(n-i)) pairs.push_back({i, (n-i)});
        }
        return pairs;
    }

    bool isPrime(int n){
        if(n<2) return false;
        if(n<4) return true;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;

    }
};