/* 
Problem ID : 2185

Problem : Counting Words With a Given Prefix

Statement : You are given an array of strings words and a string pref.

Return the number of strings in words that contain pref as a prefix.

A prefix of a string s is any leading contiguous substring of s
*/

/* Problem Link
https://leetcode.com/problems/counting-words-with-a-given-prefix/description/?envType=daily-question&envId=2025-01-09
*/

class CountingWordsWithAGivenPrefix {
    public int prefixCount(String[] words, String pref) {
        int n=words.length;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(words[i].startsWith(pref))
                count++;
        }
        return count;
    }
}

