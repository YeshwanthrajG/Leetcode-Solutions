/* 
Problem ID : 1317 

Problem : Convert Integer to the Sum of Two No-Zero Integers

Statement : No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.

Given an integer n, return a list of two integers [a, b] where:
a and b are No-Zero integers.
a + b = n
The test cases are generated so that there is at least one valid solution. If there are many valid solutions, 
you can return any of them.
*/

/* Problem Link
https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/description/?envType=daily-question&envId=2025-09-08
*/

class Solution {
    public int[] getNoZeroIntegers(int n) {
        // int res[]=new int[2];
        // int need=n;
        // for(int i=1,j=n-1;i<=n-1&&j>=1;i++,j--){
        //     if(!hasZero(i)&&!hasZero(j)){
        //         res[0]=i;
        //         res[1]=j;
        //         if(i+j==n)  return res;
        //     }
        // }
        for(int i=1;i<n;i++){
            int j=n-i;
            if(!hasZero(i)&&!hasZero(j)){
                return new int[]{i,j};
            }
        }
        return new int[0];
    }
    private boolean hasZero(int n){
        if(n==0)    return true;
        while(n>0){
            if(n%10==0)    return true;
            n/=10;
        }
        return false;
    }
}