/* 
Problem ID : 1408

Problem : String Matching in an Array

Statement : Given an array of string words, return all strings in words that is a substring of another word. 
You can return the answer in any order.

A substring is a contiguous sequence of characters within a string.
*/

/* Problem Link
https://leetcode.com/problems/string-matching-in-an-array/description/?envType=daily-question&envId=2025-01-07
*/

import java.util.*;

class StringMatchingInAnArray {
    public List<String> stringMatching(String[] words) {

        List<String> result=new ArrayList<>();
        int n=words.length;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j&&words[j].contains(words[i]))
                {
                    result.add(words[i]);
                    break;
                }
            }
        }
        return result;
        
    }
}

