/* 
Problem ID : 25 

Problem : Reverse Nodes in k-Group

Statement : Given the head of a linked list, reverse the nodes of the list k at a time, and return 
the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of 
nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.
*/

/* Problem Link
https://leetcode.com/problems/reverse-nodes-in-k-group/description/
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
    ListNode* reverseList(ListNode* head, ListNode* tail){
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode *prev=nullptr, *curr=head, *front;
        while(curr!=tail){
            front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr) return head;
        ListNode* tail=head;
        for(int i=0;i<k;i++){
            if(tail==nullptr) return head;
            tail=tail->next;
        }
        ListNode* newHead=reverseList(head, tail);
        head->next=reverseKGroup(tail, k);
        return newHead;
    }
};