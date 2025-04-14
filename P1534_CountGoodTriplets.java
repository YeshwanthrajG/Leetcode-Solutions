/* 
Problem ID : 1534 

Problem : Count Good Triplets

Statement : Given an array of integers arr, and three integers a, b and c. You need to find the number of good 
triplets.

A triplet (arr[i], arr[j], arr[k]) is good if the following conditions are true:

0 <= i < j < k < arr.length
|arr[i] - arr[j]| <= a
|arr[j] - arr[k]| <= b
|arr[i] - arr[k]| <= c
Where |x| denotes the absolute value of x.

Return the number of good triplets.
*/

/* Problem Link
https://leetcode.com/problems/count-good-triplets/description/?envType=daily-question&envId=2025-04-14
*/

class Solution {
    public int countGoodTriplets(int[] arr, int a, int b, int c) {
        int good = 0;
        int n = arr.length;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (Math.abs(arr[i] - arr[j]) <= a &&
                        Math.abs(arr[j] - arr[k]) <= b &&
                        Math.abs(arr[i] - arr[k]) <= c) {
                        good++;
                    }
                }
            }
        }
        return good;
    }
}