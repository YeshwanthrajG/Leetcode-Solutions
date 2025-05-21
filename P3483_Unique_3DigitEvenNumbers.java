/* 
Problem ID : 3483 

Problem : Unique 3-Digit Even Numbers

Statement : You are given an array of digits called digits. Your task is to determine the number of 
distinct three-digit even numbers that can be formed using these digits.

Note: Each copy of a digit can only be used once per number, and there may not be leading zeros.
*/

/* Problem Link
https://leetcode.com/problems/unique-3-digit-even-numbers/description/
*/

class Solution {
    public int totalNumbers(int[] digits) {
        HashSet<Integer> map = new HashSet<>();
        int n = digits.length;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i != j && i != k && j != k) {
                        if (digits[i] != 0) {
                            if (digits[k] % 2 == 0) {
                                int number = digits[i] * 100 + digits[j] * 10 + digits[k];
                                map.add(number);
                            }
                        }
                    }
                }
            }
        }
        return map.size();
    }
}