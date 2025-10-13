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
    public ListNode oddEvenList(ListNode head) {
        
        if(head == null || head.next == null) return head;
        ListNode odd = head;
        ListNode even = head.next;
        ListNode evenHead = even;

        while(even != null && even.next != null){
            odd.next = even.next; // changing the odd pointer;
            odd = odd.next; // now move the odd;
            
            //same thing for even;
            even.next = odd.next;
            even = even.next;
        }
        odd.next = evenHead;
        return head;
    }
}

/*
class Solution {
    public ListNode oddEvenList(ListNode head) {
        
        if(head.next.next == null) return head;

        ListNode ptr1 = head;
        ListNode ptr2 = head.next.next;

        while(ptr1.next.next !=null || ptr2.next.next != null){
            odd.add(ptr1);
            even.add(ptr2);
            ptr1 = ptr1.next.next;
            ptr2 = ptr2.next.next;
        }

        odd.addAll(even);
        return odd;
    }
}*/