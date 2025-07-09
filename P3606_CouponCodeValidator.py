"""
Problem ID : 3606 

Problem : Coupon Code Validator

Statement : You are given three arrays of length n that describe the properties of n coupons: code, 
businessLine, and isActive. The ith coupon has:

code[i]: a string representing the coupon identifier.
businessLine[i]: a string denoting the business category of the coupon.
isActive[i]: a boolean indicating whether the coupon is currently active.
A coupon is considered valid if all of the following conditions hold:

code[i] is non-empty and consists only of alphanumeric characters (a-z, A-Z, 0-9) and underscores (_).
businessLine[i] is one of the following four categories: "electronics", "grocery", "pharmacy", "restaurant".
isActive[i] is true.
Return an array of the codes of all valid coupons, sorted first by their businessLine in the order: 
"electronics", "grocery", "pharmacy", "restaurant", and then by code in lexicographical (ascending) order 
within each category.

Problem Link
https://leetcode.com/problems/coupon-code-validator/description/
"""
from typing import List

class Solution:
    def validateCoupons(self, code: List[str], businessLine: List[str], isActive: List[bool]) -> List[str]:
        l=["electronics","grocery","pharmacy","restaurant"]
        priority={"electronics":0,"grocery":1,"pharmacy":2,"restaurant":3}
        res=[]
        for i in range(len(code)):
            if(code[i].isalnum() or '_' in code[i]):
                if businessLine[i] in l:
                    if isActive[i]:
                        res.append((priority[businessLine[i]], businessLine[i], code[i]))
        res.sort(key=lambda x:(x[0],x[2]))
        return [item[2] for item in res]
