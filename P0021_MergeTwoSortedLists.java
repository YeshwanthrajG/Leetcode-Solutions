/* 
Problem ID : 1400 

Problem : Merge Two Sorted Lists

Statement : You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first 
two lists.

Return the head of the merged linked list.
*/

/* Problem Link
https://leetcode.com/problems/merge-two-sorted-lists/description/
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class MergeTwoSortedLists {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {

        ListNode head=new ListNode(0);
        ListNode temp=head;

        while(list1!=null&&list2!=null)
        {
            if(list1.val<=list2.val)
            {
                temp.next=list1;
                list1=list1.next;
            }
            else
            {
                temp.next=list2;
                list2=list2.next;
            }
            temp=temp.next;
        }

        if(list1!=null)
            temp.next=list1;

        else
            temp.next=list2;

        return head.next;
    }
}