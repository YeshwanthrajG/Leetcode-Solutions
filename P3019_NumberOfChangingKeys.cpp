/* 
Problem ID : 3019 

Problem : Number of Changing Keys

Statement : You are given a 0-indexed string s typed by a user. Changing a key is defined as using a 
key different from the last used key. For example, s = "ab" has a change of a key while s = "bBBb" does 
not have any.

Return the number of times the user had to change the key.

Note: Modifiers like shift or caps lock won't be counted in changing the key that is if a user typed the 
letter 'a' and then the letter 'A' then it will not be considered as a changing of key.
*/

/* Problem Link
https://leetcode.com/problems/number-of-changing-keys/description/?envType=problem-list-v2&envId=prshgx6i
*/

class Solution {
public:
    int countKeyChanges(string s) {
        int res=0;
        for(int i=1;i<s.size();i++){
            if(tolower(s[i-1])!=tolower(s[i])) res++;
        }
        return res;
    }
};