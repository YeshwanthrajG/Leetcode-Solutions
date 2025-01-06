/* 
Problem ID : 1769 

Problem : Minimum Number of Operations to Move All Balls to Each Box

Statement : You have n boxes. You are given a binary string boxes of length n, where boxes[i] is '0' if the ith box 
is empty, and '1' if it contains one ball.
In one operation, you can move one ball from a box to an adjacent box. Box i is adjacent to box j if abs(i - j) == 1. 

Note that after doing so, there may be more than one ball in some boxes.
Return an array answer of size n, where answer[i] is the minimum number of operations needed to move all the 
balls to the ith box.
Each answer[i] is calculated considering the initial state of the boxes.
*/


/* Problem Link
https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/?envType=daily-question&envId=2025-01-06
*/

class MinimumNumberOfOperationsToMoveAllBallsToEachBox {
    public int[] minOperations(String boxes) {
        int n=boxes.length();
        int result[]=new int[n];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(boxes.charAt(j)!='0')
                    result[i]+=Math.abs(i-j);
            }
        }

        return result;
    }
}