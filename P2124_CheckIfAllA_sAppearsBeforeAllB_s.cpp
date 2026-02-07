/* 
Problem ID : 2124 

Problem : Check if All A's Appears Before All B's

Statement : Given a string s consisting of only the characters 'a' and 'b', 
return true if every 'a' appears before every 'b' in the string. Otherwise, return false.
*/

/* Problem Link
https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/description/
*/

class Solution {
public:
    bool checkString(string s) {
        int b=0;
        for(auto &c:s){
            if(c=='b') b++;
            else if(b) return false; 
        }
        return true;
    }
};