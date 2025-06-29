"""
Problem ID : 2570 

Problem : Merge Two 2D Arrays by Summing Values

Statement : You are given two 2D integer arrays nums1 and nums2.

nums1[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
nums2[i] = [idi, vali] indicate that the number with the id idi has a value equal to vali.
Each array contains unique ids and is sorted in ascending order by id.

Merge the two arrays into one array that is sorted in ascending order by id, respecting the 
following conditions:

Only ids that appear in at least one of the two arrays should be included in the resulting array.
Each id should be included only once and its value should be the sum of the values of this id in the two arrays. 
If the id does not exist in one of the two arrays, then assume its value in that array to be 0.
Return the resulting array. The returned array must be sorted in ascending order by id.
"""

""" Problem Link
https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/?envType=daily-question&envId=2025-03-02
"""

class Solution:
    def mergeArrays(self, nums1: List[List[int]], nums2: List[List[int]]) -> List[List[int]]:
        # Initialize pointers for both arrays
        i, j = 0, 0
        result = []
        
        # Traverse both arrays with two pointers
        while i < len(nums1) and j < len(nums2):
            id1, val1 = nums1[i]
            id2, val2 = nums2[j]
            
            if id1 < id2:
                # Id1 is smaller, add it to result
                result.append([id1, val1])
                i += 1
            elif id2 < id1:
                # Id2 is smaller, add it to result
                result.append([id2, val2])
                j += 1
            else:
                # Ids are equal, sum the values
                result.append([id1, val1 + val2])
                i += 1
                j += 1
        
        # Add remaining elements from nums1, if any
        while i < len(nums1):
            result.append(nums1[i])
            i += 1
        
        # Add remaining elements from nums2, if any
        while j < len(nums2):
            result.append(nums2[j])
            j += 1        
        return result