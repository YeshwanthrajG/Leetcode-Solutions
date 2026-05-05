/* 
Problem ID : 61 

Problem : Rotate List

Statement : Given the head of a linked list, rotate the list to the right by k places.
*/

/* Problem Link
https://leetcode.com/problems/rotate-list/description/?envType=daily-question&envId=2026-05-05
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        ListNode* tail=head;
        int size=1;
        while(tail->next!=NULL){
            size++;
            tail=tail->next;
        }
        k%=size;
        if(k==0) return head;
        tail->next=head;
        int steps=size-k;
        ListNode* temp=head;
        while(--steps) temp=temp->next;
        ListNode* newHead=temp->next;
        temp->next=NULL;
        return newHead;

    }
};