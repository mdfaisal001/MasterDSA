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
    public boolean isPalindrome(ListNode head) {
        ListNode mid = head;
        ListNode fast = head;

        //to find the middle node
        while(fast!= null && fast.next != null){
            fast = fast.next.next;
            mid = mid.next;
        }

        ListNode prev = null;

        
        //reverse the right part fromthe middle
        while(mid != null){
            ListNode temp = mid.next;
            mid.next = prev;
            prev = mid;
            mid = temp;
        }

        //compare the right and left to be same;

        ListNode left = head;
        ListNode right = prev;

        while(right != null && right!=null){
            if(left.val != right.val) return false;
            left = left.next;
            right = right.next;
        }
     return true;
    }
}