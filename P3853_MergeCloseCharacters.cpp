/* 
Problem ID : 3853 

Problem : Merge Close Characters

Statement : You are given a string s consisting of lowercase English letters and an integer k.

Two equal characters in the current string s are considered close if the distance between their indices 
is at most k.

When two characters are close, the right one merges into the left. Merges happen one at a time, and after 
each merge, the string updates until no more merges are possible.

Return the resulting string after performing all possible merges.

Note: If multiple merges are possible, always merge the pair with the smallest left index. If multiple 
pairs share the smallest left index, choose the pair with the smallest right index.
*/

/* Problem Link
https://leetcode.com/problems/merge-close-characters/
*/

class Solution {
public:
    string mergeCharacters(string s, int k) {
        while(true){
            bool mer=false;
            int n=s.size();
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n && j-i<=k;j++){
                    if(s[i]==s[j]){
                        s.erase(j,1);
                        mer=true;
                        break;
                    }
                }
                if(mer) break;
            }
            if(!mer) break;
        }
        return s;
    }
};