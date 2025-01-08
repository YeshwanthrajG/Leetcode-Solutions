/* 
Problem ID : 3042

Problem : Count Prefix and Suffix Pairs I

Statement : You are given a 0-indexed string array words.

Let's define a boolean function isPrefixAndSuffix that takes two strings, str1 and str2:

isPrefixAndSuffix(str1, str2) returns true if str1 is both a prefix and a suffix of str2, and false otherwise.

For example, isPrefixAndSuffix("aba", "ababa") is true because "aba" is a prefix of "ababa" and also a 
suffix, but isPrefixAndSuffix("abc", "abcd") is false.

Return an integer denoting the number of index pairs (i, j) such that i < j, and 
isPrefixAndSuffix(words[i], words[j]) is true.
*/

/* Problem Link
https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/?envType=daily-question&envId=2025-01-08
*/

class CountPrefixAndSuffixPairsI {
    public int countPrefixSuffixPairs(String[] words) {
        int n=words.length;
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(isPrefixAndSuffix(words[i],words[j]))
                    count++;
            }
        }
        return count;
    }

    public boolean isPrefixAndSuffix(String str1, String str2)
    {
        int n1=str1.length();
        int n2=str2.length();
        if(n1>n2)
            return false;

        return (str2.substring(0,n1).equals(str1)&&str2.substring(n2-n1).equals(str1));
    }
}



