/* 
Problem ID : 3217 

Problem : Delete Nodes From Linked List Present in Array

Statement : You are given an array of integers nums and the head of a linked list. Return the head of the 
modified linked list after removing all nodes from the linked list that have a value that exists in nums.
*/

/* Problem Link
https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/?envType=daily-question&envId=2025-11-01
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
    public ListNode modifiedList(int[] nums, ListNode head) {
        Set<Integer> ll=new HashSet<>();
        for(int i:nums){
            ll.add(i);
        }
        while(head!=null && ll.contains(head.val)) head=head.next;
        ListNode curr=head;
        while(curr!=null && curr.next!=null){
            while(curr.next!=null && ll.contains(curr.next.val)){
                curr.next=curr.next.next;
            }
            curr=curr.next;
        }
        return head;
    }
}