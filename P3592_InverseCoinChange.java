/* 
Problem ID : 3592 

Problem : Inverse Coin Change

Statement : You are given a 1-indexed integer array numWays, where numWays[i] represents the number of ways to select a total amount i using an infinite supply of some fixed coin denominations. Each denomination is a positive integer with value at most numWays.length.

However, the exact coin denominations have been lost. Your task is to recover the set of denominations that could have resulted in the given numWays array.

Return a sorted array containing unique integers which represents this set of denominations.

If no such set exists, return an empty array.
*/

/* Problem Link
https://leetcode.com/problems/inverse-coin-change/description/
*/

class Solution {
    public List<Integer> findCoins(int[] numWays) {
        int n=numWays.length;
        int target[]=new int[n+1];
        target[0]=1;
        for(int i=0;i<n;i++){
            target[i+1]=numWays[i];
        }
        int ways[]=new int[n+1];
        ways[0]=1;
        List<Integer> res=new ArrayList<>();
        for(int i=1;i<=n;i++){
            int newWays[]=Arrays.copyOf(ways,n+1);
            for(int j=i;j<=n;j++){
                newWays[j]+=newWays[j-i];
            }
            // for(int x:newWays){
            //     System.out.print(x+" ");
            // }
            // System.out.println();
            boolean flag=true;
            for(int j=1;j<=n;j++){
                if(newWays[j]>target[j]){
                    flag=false;
                    break;
                }
                if(newWays[j]>ways[j]){
                    flag=true;
                }
            }
            if(flag){
                res.add(i);
                ways=newWays;
            }
        }
        for(int i=0;i<=n;i++){
            if(ways[i]!=target[i]){
                return new ArrayList<>();
            }
        }
        return res;
    }
}