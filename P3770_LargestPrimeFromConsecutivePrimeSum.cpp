/* 
Problem ID : 3770 

Problem : Largest Prime from Consecutive Prime Sum

Statement : You are given an integer n.

Return the largest prime number less than or equal to n that can be expressed as the sum of 
one or more consecutive prime numbers starting from 2. If no such number exists, return 0.
*/

/* Problem Link
https://leetcode.com/problems/largest-prime-from-consecutive-prime-sum/description/
*/

class Solution {
public:
    bool isPrime(long long x) {
    if (x < 2) return false;
        if (x % 2 == 0) return x == 2;
        for (long long i = 3; i * i <= x; i += 2)
            if (x % i == 0) return false;
        return true;
    }
    
    int largestPrime(int n) {
        vector<bool> prime(n+1,true);
        prime[0]=prime[1]=false;
        for(int i=2;i*i<=n;i++){
            if(prime[i]){
                for(int j=i*i;j<=n;j+=i){
                    prime[j]=false;
                }
            }
        }
        vector<int> primes;
        for(int i=2;i<=n;i++){
            if(prime[i]) primes.push_back(i);
        }
        int sum=0, res=0;
        for(int p:primes){
            sum+=p;
            if(sum>n) break;
            if(isPrime(sum)) res=sum;
        }
        return res;
    }
};