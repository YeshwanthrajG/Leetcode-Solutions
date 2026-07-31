/* 
Problem ID : 3016 

Problem : Minimum Number of Pushes to Type Word II

Statement : You are given a string word containing lowercase English letters.

Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be 
used to form words by pushing them. For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c" .

It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be 
remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to 
find the minimum number of times the keys will be pushed to type the string word.

Return the minimum number of pushes needed to type word after remapping the keys.

An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 
do not map to any letters.
*/

/* Problem Link
https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/?envType=daily-question&envId=2026-07-31
*/

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26);
        for(char c:word){
            freq[c-'a']++;
        }
        sort(freq.begin(), freq.end());
        int res=0;
        for(int i=25;i>=0 && freq[i]>0; i--){
            res+=freq[i]*((25-i)/8+1);
        }
        return res;
    }
};