/* 
Problem ID : 2095 

Problem : Delete the Middle Node of a Linked List

Statement : You are given the head of a linked list. Delete the middle node, and return the head of the 
modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, 
where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.
*/

/* Problem Link
https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/?envType=daily-question&envId=2026-06-15
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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return nullptr;
        ListNode *slow=head, *fast=head, *prev=nullptr;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        prev->next=slow->next;
        return head;
    }
};