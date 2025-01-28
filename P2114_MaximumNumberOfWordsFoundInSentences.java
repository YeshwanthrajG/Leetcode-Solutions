/* 
Problem ID : 2114 

Problem : Maximum Number of Words Found in Sentences

Statement : A sentence is a list of words that are separated by a single space with no leading or trailing 
spaces.

You are given an array of strings sentences, where each sentences[i] represents a single sentence.

Return the maximum number of words that appear in a single sentence.

/* Problem Link
https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/description/
*/

class Solution {
    public int mostWordsFound(String[] sentences) {
        // int count=0,result=0;
        // for(String i:sentences)
        // {
        //     count=i.split(" ").length;
        //     result=Math.max(result,count);
        // }
        // return result;

        int count=0;
        int result=0;
        for(int i=0;i<sentences.length;i++)
        {
            for(int j=0;j<sentences[i].length();j++)
            {
                if(sentences[i].charAt(j)==' ')
                    count++;
            }

            result=Math.max(result,count);
            count=0;
        }
        return result+1;
    }
}