/* 
Problem ID : 1400 

Problem : Construct K Palindrome Strings

Statement : Given a string s and an integer k, return true if you can use all the characters in s to 
construct k palindrome strings or false otherwise
*/

/* Problem Link
https://leetcode.com/problems/construct-k-palindrome-strings/description/?envType=daily-question&envId=2025-01-11
*/

import java.util.*;

class ConstructKPalindromeStrings {
    public boolean canConstruct(String s, int k) {
        Map<Character,Integer> map=new HashMap<>();
        int count=0;
        int n=s.length();

        for(int i=0;i<n;i++)
        {
            map.put(s.charAt(i),map.getOrDefault(s.charAt(i),0)+1);
        }
        for(int i:map.values())
        {
            if(i%2==1)
                count++;
        }

        if(count<=k&&k<=n)
            return true;

        return false;
    }
}



