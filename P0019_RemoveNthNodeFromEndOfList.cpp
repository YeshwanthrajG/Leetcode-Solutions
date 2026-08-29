/* 
Problem ID : 19 

Problem : Remove Nth Node From End of List

Statement : Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/

/* Problem Link
https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=problem-list-v2&envId=linked-list
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy=new ListNode(0, head);
        ListNode* slow=dummy;
        ListNode* fast=dummy;
        for(int i=0;i<=n;i++) fast=fast->next;
       while(fast!=nullptr){
            slow=slow->next;
            fast=fast->next;
       }
       ListNode* temp=slow->next;
       slow->next=slow->next->next;
       delete temp;
       return dummy->next;
    }
};