/* 
Problem ID : 2840 

Problem : Check if Strings Can be Made Equal With Operations II

Statement : You are given two strings s1 and s2, both of length n, consisting of lowercase English letters.

You can apply the following operation on any of the two strings any number of times:

Choose any two indices i and j such that i < j and the difference j - i is even, then swap the two 
characters at those indices in the string.
Return true if you can make the strings s1 and s2 equal, and false otherwise.
*/

/* Problem Link
https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/description/?envType=daily-question&envId=2026-03-30
*/

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<char> ve1, ve2, vo1, vo2;
        int n=s1.length();
        for(int i=0;i<n;i++){
            if(i%2==0){
                ve1.push_back(s1[i]);
                ve2.push_back(s2[i]);
            }
            else{
                vo1.push_back(s1[i]);
                vo2.push_back(s2[i]);
            }
        }
        sort(ve1.begin(), ve1.end());
        sort(ve2.begin(), ve2.end());
        if(ve1!=ve2) return false;
        sort(vo1.begin(), vo1.end());
        sort(vo2.begin(), vo2.end());
        if(vo1!=vo2) return false;
        return true;
    }
};