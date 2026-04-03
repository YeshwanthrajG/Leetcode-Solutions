/* 
Problem ID : 3805 

Problem : Count Caesar Cipher Pairs

Statement : You are given an array words of n strings. Each string has length m and contains only 
lowercase English letters.

Two strings s and t are similar if we can apply the following operation any number of times (possibly 
zero times) so that s and t become equal.

Choose either s or t.
Replace every letter in the chosen string with the next letter in the alphabet cyclically. The next 
letter after 'z' is 'a'.
Count the number of pairs of indices (i, j) such that:

i < j
words[i] and words[j] are similar.
Return an integer denoting the number of such pairs.
*/

/* Problem Link
https://leetcode.com/problems/count-caesar-cipher-pairs/description/
*/

class Solution {
public:
    long long countPairs(vector<string>& words) {
        int n=words.size();
        unordered_map<string, long long> freq;
        for(const string &s:words){
            int temp=s[0]-'a';
            string norm=s;
            for(int i=0;i<s.size();i++){
                norm[i]=char((s[i]-'a'-temp+26)%26+'a');
            }
            freq[norm]++;
        }
        long long res=0;
        for(auto& [key, count]:freq){
            res+=count*(count-1)/2;
        }
        return res;
    }
};