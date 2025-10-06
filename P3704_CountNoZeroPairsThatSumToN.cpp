/* 
Problem ID : 3704 

Problem : Count No-Zero Pairs That Sum to N

Statement : A no-zero integer is a positive integer that does not contain the digit 0 in its decimal 
representation.

Given an integer n, count the number of pairs (a, b) where:

a and b are no-zero integers.
a + b = n
Return an integer denoting the number of such pairs.
*/

/* Problem Link
https://leetcode.com/problems/count-no-zero-pairs-that-sum-to-n/description/
*/

unordered_map<long long,long long> memo;
class Solution {
public:
    bool isNoZero(long long num){
        while(num>0){
            if(num%10==0) return false;
            num/=10;
        }
        return true;
    }
    long long count(long long n){
        if(memo.contains(n)) return memo[n];
        long long d1=isNoZero(n/10)?2:0;
        long long d2=isNoZero(n/10-1)?2:0;
        return memo[n]=max(0LL, n%10-1LL)*(d1+count(n/10))+(9LL-n%10)*(d2+count(n/10-1));
    }
    long long countNoZeroPairs(long long n) {
        if(memo.empty()) for (long long i=0;i<=9;i++)   memo[i]=i-1;
        return count(n);
    }
};