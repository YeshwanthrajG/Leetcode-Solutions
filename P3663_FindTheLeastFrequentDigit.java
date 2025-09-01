/* 
Problem ID : 3663 

Problem : Find The Least Frequent Digit

Statement : Given an integer n, find the digit that occurs least frequently in its decimal representation. 
If multiple digits have the same frequency, choose the smallest digit.

Return the chosen digit as an integer.

The frequency of a digit x is the number of times it appears in the decimal representation of n.
*/

/* Problem Link
https://leetcode.com/problems/find-the-least-frequent-digit/description/
*/

class Solution {
    public int getLeastFrequentDigit(int n) {
        n=Math.abs(n);
        if(n==0) return 0;
        int[] freq=new int[10];
        while(n>0){
            freq[n%10]++;
            n/=10;
        }
        int result=0;
        int min=Integer.MAX_VALUE;
        for(int i=0;i<=9;i++){
            if(freq[i]>0 && freq[i]<min){
                min=freq[i];
                result=i;
            }
            else if(freq[i]==min && i<result){
                result=i;
            }
        }
        return result;
    }
}