'''
Problem ID : 2942 

Problem : Find Words Containing Character

Statement : You are given a 0-indexed array of strings words and a character x.

Return an array of indices representing the words that contain the character x.

Note that the returned array may be in any order.
'''
'''
Problem Link
https://leetcode.com/problems/find-words-containing-character/description/?envType=daily-question&envId=2025-05-24
'''

class Solution:
    def findWordsContaining(self, words: List[str], x: str) -> List[int]:
        res=[]

        for i in range(0,len(words)):
            if x in words[i]:
                res.append(i)
        return res
