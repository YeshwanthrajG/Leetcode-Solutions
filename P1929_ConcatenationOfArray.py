"""
Problem ID : 1929 

Problem : Concatenation of Array

Statement : Given an integer array nums of length n, you want to create an array ans of length 2n where 
ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).

Specifically, ans is the concatenation of two nums arrays.

Return the array ans.
"""

""" Problem Link
https://leetcode.com/problems/concatenation-of-array/description/
"""

class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        ls=[]
        for x in nums:
            ls.append(x)
        for x in nums:
            ls.append(x)
        return ls