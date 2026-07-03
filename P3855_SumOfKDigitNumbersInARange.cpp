/* 
Problem ID : 3855 

Problem : Sum of K-Digit Numbers in a Range

Statement : You are given three integers l, r, and k.

Consider all possible integers consisting of exactly k digits, where each digit is chosen independently 
from the integer range [l, r] (inclusive). If 0 is included in the range, leading zeros are allowed.

Return an integer representing the sum of all such numbers.​​​​​​​ Since the answer may be very large, return 
it modulo 109 + 7.
*/

/* Problem Link
https://leetcode.com/problems/sum-of-k-digit-numbers-in-a-range/
*/

class Solution {
public:
    static const long long MOD=1e9+7;

    long long mod(long long a, long long b){
        long long res=1;
        while(b>0){
            if(b&1 ) res=(res*a)%MOD;
            a=(a*a)%MOD;
            b>>=1;
        }
        return res;
    }
    
    int sumOfNumbers(int l, int r, int k) {
        long long count=r-l+1;
        long long sum=0;
        for(int i=l;i<=r;i++){
            sum+=i;
        }
        sum%=MOD;
        long long p1=mod(count, k-1);
        long long p2=(mod(10, k)-1+MOD)%MOD;
        long long i9=mod(9, MOD-2);
        long long g=(p2*i9)%MOD;
        sum=(sum*p1)%MOD;
        sum=(sum*g)%MOD;
        return sum;
    }
};