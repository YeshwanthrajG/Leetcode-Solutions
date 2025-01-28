/* 
Problem ID : 2 

Problem : Add Two Numbers

Statement : You are given two non-empty linked lists representing two non-negative integers. The digits are 
stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the 
sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself
*/

/* Problem Link
https://leetcode.com/problems/add-two-numbers/description/
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

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int sum=0,carry=0;
        ListNode l3=new ListNode(0);
        ListNode temp=l3;
        while(l1!=null||l2!=null||carry!=0)
        {
            sum=carry;
            if(l1!=null)
            {
                sum+=l1.val;
                l1=l1.next;
            }
            if(l2!=null)
            {
                sum+=l2.val;
                l2=l2.next;
            }
            carry=sum/10;
            temp.next=new ListNode(sum%10);
            temp=temp.next;
        }
        return l3.next;
    }
}