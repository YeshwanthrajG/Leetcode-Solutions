"""
Problem ID : 1358 

Problem : Number of Substrings Containing All Three Characters

Statement : Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.
"""

""" Problem Link
https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/?envType=daily-question&envId=2025-03-11
"""

class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        last=[-1]*3
        count=0
        for i in range(len(s)):
            last[ord(s[i])-ord('a')]=i
            if last[0]!=-1 and last[1]!=-1 and last[2]!=-1:
                count+=(1+min(last[0],last[1],last[2]))
        return count
        