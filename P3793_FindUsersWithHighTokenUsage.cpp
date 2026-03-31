/* 
Problem ID : 3793 

Problem : Find Users with High Token Usage

Statement : Table: prompts

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| user_id     | int     |
| prompt      | varchar |
| tokens      | int     |
+-------------+---------+
(user_id, prompt) is the primary key (unique value) for this table.
Each row represents a prompt submitted by a user to an AI system along with the number of tokens consumed.
Write a solution to analyze AI prompt usage patterns based on the following requirements:

For each user, calculate the total number of prompts they have submitted.
For each user, calculate the average tokens used per prompt (Rounded to 2 decimal places).
Only include users who have submitted at least 3 prompts.
Only include users who have submitted at least one prompt with tokens greater than their own average token usage.
Return the result table ordered by average tokens in descending order, and then by user_id in ascending order.

The result format is in the following example.
*/

/* Problem Link
https://leetcode.com/problems/find-users-with-high-token-usage/
*/

# Write your MySQL query statement below

select user_id, count(prompt) as prompt_count, round(avg(tokens), 2) as avg_tokens
from prompts
group by user_id
having prompt_count>2 and max(tokens)>avg_tokens
order by avg(tokens) desc, user_id;