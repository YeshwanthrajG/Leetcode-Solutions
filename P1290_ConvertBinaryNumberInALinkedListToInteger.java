/* 
Problem ID : 1290 

Problem : Convert Binary Number in a Linked List to Integer

Statement : Given head which is a reference node to a singly-linked list. The value of each node in the 
linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.
*/

/* Problem Link
https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/description/?envType=daily-question&envId=2025-07-14
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
    public int getDecimalValue(ListNode head) {
        int sum=0;
        while(head!=null){
            sum=sum*2+head.val;
            head=head.next;
        }
        return sum;
    }
}