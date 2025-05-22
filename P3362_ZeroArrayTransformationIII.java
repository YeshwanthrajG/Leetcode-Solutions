/* 
Problem ID : 3362 

Problem : Zero Array Transformation III

Statement : You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri].

Each queries[i] represents the following action on nums:

Decrement the value at each index in the range [li, ri] in nums by at most 1.
The amount by which the value is decremented can be chosen independently for each index.
A Zero Array is an array with all its elements equal to 0.

Return the maximum number of elements that can be removed from queries, such that nums can still be converted 
to a zero array using the remaining queries. If it is not possible to convert nums to a zero array, return -1.
*/

/* Problem Link
https://leetcode.com/problems/zero-array-transformation-iii/description/?envType=daily-question&envId=2025-05-22
*/

class Solution {
    public int maxRemoval(int[] nums, int[][] queries) {
        Arrays.sort(queries, (a, b) -> Integer.compare(a[0], b[0]));
        PriorityQueue<Integer> available = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> assigned = new PriorityQueue<>();
        int count = 0;
        for (int time = 0, k = 0; time < nums.length; time++) {
            while (!assigned.isEmpty() && assigned.peek() < time)
                assigned.poll();
            while (k < queries.length && queries[k][0] <= time)
                available.add(queries[k++][1]);
            while (assigned.size() < nums[time]
                   && !available.isEmpty()
                   && available.peek() >= time) {
                assigned.add(available.poll());
                count++;
            }
            if (assigned.size() < nums[time])
                return -1;
        }
        return queries.length - count;
    }
}