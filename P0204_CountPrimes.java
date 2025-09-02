/* 
Problem ID : 204

Problem : Count Primes

Statement : Given an integer n, return the number of prime numbers that are strictly less than n.
*/

/* Problem Link
https://leetcode.com/problems/count-primes/description/
*/

class Solution {
    // Using Sieve of Eratosthenes
    public int countPrimes(int n){
        if(n<2) return 0;
        boolean primeArr[]=new boolean[n+1];
        int count=0;
        Arrays.fill(primeArr,true);
        primeArr[0]=false;
        primeArr[1]=false;
        for(int p=2;p*p<n;p++){
            if(primeArr[p]){
                for(int i=p*p;i<n;i+=p)    primeArr[i]=false;
            }
        }
        for(int i=2;i<n;i++){
            if(primeArr[i]) count++;
        }
        return count;
    }
}