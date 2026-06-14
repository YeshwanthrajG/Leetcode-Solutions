/* 
Problem ID : 2130 

Problem : Maximum Twin Sum of a Linked List

Statement : In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is 
known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the 
only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.
*/

/* Problem Link
https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/?envType=daily-question&envId=2026-06-14
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLL(ListNode* head){
        ListNode *first, *prev=nullptr, *temp=head;
        while(temp!=nullptr){
            first=temp->next;
            temp->next=prev;
            prev=temp;
            temp=first;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        ListNode *list1=head;
        ListNode *slow=list1, *fast=list1->next;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* list2=reverseLL(slow);
        int maxSum=0;
        while(list1!=nullptr){
            maxSum=max(maxSum, (list1->val+list2->val));
            list1=list1->next;
            list2=list2->next;
        }
        return maxSum;
    }
};