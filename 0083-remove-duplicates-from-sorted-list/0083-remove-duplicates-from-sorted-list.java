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
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) return null;

        ListNode prev = head;
        ListNode temp = head.next;

        while(temp != null ){
            while(temp != null && temp.val == prev.val){
                temp = temp.next; // move the next pointer if anydup
            }

            prev.next = temp;
            prev = temp;
            if(temp!=null)temp = temp.next;
        }
        return head;
    }
}