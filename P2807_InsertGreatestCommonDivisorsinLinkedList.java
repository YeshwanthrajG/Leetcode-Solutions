/* 
Problem ID : 2807 

Problem : Insert Greatest Common Divisors in Linked List

Statement : Given the head of a linked list head, in which each node contains an integer value.

Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of 
them.

Return the linked list after insertion.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.
*/

/* Problem Link
https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/
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
class InsertGreatestCommonDivisorsinLinkedList {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp=head;
        while(temp->next!=NULL)
        {
            ListNode* traverse=new ListNode(__gcd(temp->val,temp->next->val),temp->next);
            temp->next=traverse;
            temp=traverse->next;
        }
        return head;
    }
};