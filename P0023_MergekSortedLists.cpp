/* 
Problem ID : 23 

Problem : Merge k Sorted Lists

Statement : You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
*/

/* Problem Link
https://leetcode.com/problems/merge-k-sorted-lists/description/
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
    ListNode* merge(vector<ListNode*> &lists, int start, int end){
        if(start==end) return lists[start];
        if(start+1==end) return func(lists[start], lists[end]);
        int mid=start+(end-start)/2;
        ListNode* left=merge(lists, start, mid);
        ListNode* right=merge(lists, mid+1, end);
        return func(left, right);
    }

    ListNode* func(ListNode* l1, ListNode* l2){
        ListNode* temp=new ListNode(0);
        ListNode* curr=temp;
        while(l1 && l2){
            if(l1->val<l2->val){
                curr->next=l1;
                l1=l1->next;
            }
            else{
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        curr->next=l1?l1:l2;
        return temp->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        return merge(lists, 0, lists.size()-1);
    }
};