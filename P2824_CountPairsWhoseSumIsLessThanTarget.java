/* 
Problem ID : 2824 

Problem : Count Pairs Whose Sum is Less than Target

Statement : Given a 0-indexed integer array nums of length n and an integer target, return the number of 
pairs (i, j) where 0 <= i < j < n and nums[i] + nums[j] < target.
*/

/* Problem Link
https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/description/?envType=problem-list-v2&envId=sorting
*/

class CountPairsWhoseSumIsLessThanTarget {
    public int countPairs(List<Integer> nums, int target) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {                
                if(nums.get(i)+nums.get(j)<target)
                    count++;
            }
        }
        return count;
    }
}