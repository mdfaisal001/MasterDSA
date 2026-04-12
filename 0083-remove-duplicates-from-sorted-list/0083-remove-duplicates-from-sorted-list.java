class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null) return null;

        HashMap<Integer, Boolean> mp = new HashMap<>();

        ListNode curr = head;
        ListNode prev = null;

        while (curr != null) {
            if (mp.containsKey(curr.val)) {
                // delete curr
                prev.next = curr.next;
                curr = curr.next;
            } else {
                mp.put(curr.val, true);
                prev = curr;       // move prev only if NOT deleted
                curr = curr.next;
            }
        }

        return head;
    }
}