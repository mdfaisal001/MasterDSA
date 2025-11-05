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
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode temp = list1;
        for(int i=0; i<a-1; i++){
            temp = temp.next;
        }

        ListNode tail = list1;
        for(int j=0; j<=b;j++){
            tail = tail.next;
        }

        ListNode curr = list2;
        while(curr.next != null){
            curr = curr.next;
        }
        temp.next = list2;
        curr.next = tail;

        return list1;
    }
}