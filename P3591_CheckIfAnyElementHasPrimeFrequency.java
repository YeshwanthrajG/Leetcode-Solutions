/* 
Problem ID : 3591 

Problem : Check if Any Element Has Prime Frequency

Statement : You are given an integer array nums.

Return true if the frequency of any element of the array is prime, otherwise, return false.

The frequency of an element x is the number of times it occurs in the array.

A prime number is a natural number greater than 1 with only two factors, 1 and itself.
*/

/* Problem Link
https://leetcode.com/problems/check-if-any-element-has-prime-frequency/description/
*/

class Solution {
    public boolean checkPrimeFrequency(int[] nums) {

        int freq[]=new int[101];
        for(int i:nums){
            freq[i]++;
        }
        for(int i:freq){
            if(isprime(i)){
                return true;
            }
        }
        return false;
    }

    public boolean isprime(int x){
        if(x==0||x==1){
            return false;
        }
        for(int i=2;i<=x/2;i++){
            if(x%i==0){
                return false;
            }
        }
        return true;
    }
}