/* 
Problem ID : 3618 

Problem : Split Array by Prime Indices

Statement : You are given an integer array nums.

Split nums into two arrays A and B using the following rule:

Elements at prime indices in nums must go into array A.
All other elements must go into array B.
Return the absolute difference between the sums of the two arrays: |sum(A) - sum(B)|.

Note: An empty array has a sum of 0.
*/

/* Problem Link
https://leetcode.com/problems/split-array-by-prime-indices/description/
*/

class Solution {
    public long splitArray(int[] nums) {
        ArrayList<Integer> prime=new ArrayList<>();
        ArrayList<Integer> composite=new ArrayList<>();
        for(int i=0;i<nums.length;i++){
            if(isPrime(i)) prime.add(nums[i]);
            else composite.add(nums[i]);
        }

        long primeSum=0,compositeSum=0;
        for(int i:prime){
            primeSum+=i;
        }
        for(int i:composite){
            compositeSum+=i;
        }

        return (long)Math.abs(primeSum-compositeSum);
    }


    private boolean isPrime(int num){
        if(num<=1) return false;
        if(num==2||num==3) return true;
        if(num%2==0||num%3==0) return false;

        for(int i=5;i<=Math.sqrt(num);i+=6){
            if(num%i==0||num%(i+2)==0) return false;
        }
        return true;
    }
}