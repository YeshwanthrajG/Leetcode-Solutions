/* 
Problem ID : 2559 

Problem : Count Vowel Strings in Ranges

Statement : You are given a 0-indexed array of strings words and a 2D array of integers queries.
Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri 
(both inclusive) of words that start and end with a vowel.
Return an array ans of size queries.length, where ans[i] is the answer to the ith query.

Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.
*/

/* Problem Link
https://leetcode.com/problems/count-vowel-strings-in-ranges/description/?envType=daily-question&envId=2025-01-02
*/
import java.util.*;

class CountVowelStringsInRanges {
    public int[] vowelStrings(String[] words, int[][] queries) {
        int n=words.length;
        int m=queries.length;
        int prefix[]=new int[n+1];
        Set<Character> vowels=new HashSet<>(Arrays.asList('a','e','i','o','u'));

        for(int i=0;i<n;i++)
        {
            prefix[i+1]=prefix[i];
            if(vowels.contains(words[i].charAt(0))&&vowels.contains(words[i].charAt(words[i].length()-1)))
                prefix[i+1]++;
        }

        int result[]=new int[m];
        for(int i=0;i<m;i++)
        {
            result[i]=prefix[queries[i][1]+1]-prefix[queries[i][0]];
        }
        return result;
        
    }
}
