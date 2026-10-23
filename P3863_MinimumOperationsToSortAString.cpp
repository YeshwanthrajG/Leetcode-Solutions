/* 
Problem ID : 3863 

Problem : Minimum Operations to Sort a String

Statement : You are given a string s consisting of lowercase English letters.

In one operation, you can select any substring of s that is not the entire string and sort it in 
non-descending alphabetical order.

Return the minimum number of operations required to make s sorted in non-descending order. 
If it is not possible, return -1.
*/

/* Problem Link
https://leetcode.com/problems/minimum-operations-to-sort-a-string/description/?envType=daily-question&envId=2026-10-23
*/

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        bool sorted = true;
        for (int i = 1; i < n; ++i) {
            if (s[i] < s[i - 1]) {
                sorted = false;
                break;
            }
        }
        if (sorted) return 0;
        if (n == 2) return -1;
        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());
        if (s[0] == mn || s[n - 1] == mx) return 1;
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == mn || s[i] == mx) return 2;
        }
        return 3;
    }
};