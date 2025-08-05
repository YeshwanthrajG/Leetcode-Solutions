/* 
Problem ID : 3477 

Problem : Fruits Into Baskets II

Statement : You are given two arrays of integers, fruits and baskets, each of length n, where fruits[i] represents the 
quantity of the ith type of fruit, and baskets[j] represents the capacity of the jth basket.

From left to right, place the fruits according to these rules:

Each fruit type must be placed in the leftmost available basket with a capacity greater than or equal to the quantity of 
that fruit type.
Each basket can hold only one type of fruit.
If a fruit type cannot be placed in any basket, it remains unplaced.
Return the number of fruit types that remain unplaced after all possible allocations are made.
*/

/* Problem Link
https://leetcode.com/problems/fruits-into-baskets-ii/description/?envType=daily-question&envId=2025-08-05
*/

class Solution {
    public int numOfUnplacedFruits(int[] fruits, int[] baskets) {
        int n=fruits.length;
        int res=n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(fruits[i]<=baskets[j]){
                    res--;
                    baskets[j]=0;
                    break;
                }
            }
        }
        return res;

    }
}