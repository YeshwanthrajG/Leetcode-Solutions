/* 
Problem ID : 3668 

Problem : Restore Finishing Order

Statement : You are given an integer array order of length n and an integer array friends.

order contains every integer from 1 to n exactly once, representing the IDs of the participants of a race in their 
finishing order.
friends contains the IDs of your friends in the race sorted in strictly increasing order. Each ID in friends is 
guaranteed to appear in the order array.
Return an array containing your friends' IDs in their finishing order.
*/

/* Problem Link
https://leetcode.com/problems/restore-finishing-order/description/
*/

class Solution {
    public int[] recoverOrder(int[] order, int[] friends) {
        Set<Integer> set=new HashSet<>();
        int[] res=new int[friends.length];
        int k=0;
        for(int i:friends){
            set.add(i);
        }
        for(int i:order){
            if(set.contains(i)){
                res[k++]=i;
            }
        }
        return res;
    }
}