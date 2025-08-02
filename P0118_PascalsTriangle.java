/* 
Problem ID : 118 

Problem : Pascal's Triangle

Statement : Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it.
*/

/* Problem Link
https://leetcode.com/problems/pascals-triangle/description/?envType=daily-question&envId=2025-08-01
*/

import java.util.*;

class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> pascal = new ArrayList<>();

        for (int i = 0; i < numRows; i++) {
            List<Integer> row = new ArrayList<>(Collections.nCopies(i + 1, 1));
            for (int j = 1; j < i; j++) {
                int val = pascal.get(i - 1).get(j - 1) + pascal.get(i - 1).get(j);
                row.set(j, val);
            }
            pascal.add(row);
        }
        return pascal;
    }
}

