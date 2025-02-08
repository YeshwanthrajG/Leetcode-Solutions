/* 
Problem ID : 3223 

Problem : Minimum Length of String After Operations

Statement : You are given a string s.

You can perform the following process on s any number of times:

Choose an index i in the string such that there is at least one character to the left of index i that is 
equal to s[i], and at least one character to the right that is also equal to s[i].
Delete the closest character to the left of index i that is equal to s[i].
Delete the closest character to the right of index i that is equal to s[i].
Return the minimum length of the final string s that you can achieve.
*/

/* Problem Link
https://leetcode.com/problems/construct-k-palindrome-strings/description/?envType=daily-question&envId=2025-01-11
*/

class MinimumLengthofStringAfterOperations {
    public int minimumLength(String s) {
        HashMap<Character,Integer> map=new HashMap<>();
        int n=s.length();
        int result=0;
        for(char i:s.toCharArray())
        {
            map.put(i,map.getOrDefault(i,0)+1);
        }

        for(int i:map.values())
        {
            while(i>=3)
            {
                result+=2;
                i-=2;
            }
        }

        return n-result;
    }
}