/* 
Problem ID : 3765 

Problem : Complete Prime Number

Statement : You are given an integer num.

A number num is called a Complete Prime Number if every prefix and every suffix of num is prime.

Return true if num is a Complete Prime Number, otherwise return false.

Note:

A prefix of a number is formed by the first k digits of the number.
A suffix of a number is formed by the last k digits of the number.
Single-digit numbers are considered Complete Prime Numbers only if they are prime.
*/

/* Problem Link
https://leetcode.com/problems/complete-prime-number/description/
*/

class Solution {
public:
    bool isPrime(long long n) {
        if (n <= 1) {
            return false;
        }
        if (n <= 3) {
            return true;
        }
        if (n % 2 == 0 || n % 3 == 0) {
            return false;
        }
        for (long long i = 5; i * i <= n; i = i + 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
    bool completePrime(int num) {
        string s=to_string(num);
        int n=s.size();
        for(int i=1;i<=n;i++){
            long long prefix=stoll(s.substr(0,i));
            if(!isPrime(prefix)) return false;
        }
        for(int i=0;i<n;i++){
            long long suffix=stoll(s.substr(i));
            if(!isPrime(suffix)) return false;
        }
        return true;
    }
};