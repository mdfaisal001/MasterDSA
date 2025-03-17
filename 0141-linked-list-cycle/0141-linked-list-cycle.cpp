/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
           if(fast == slow) return true;
        }
       return false;
    }
};

/*class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == NULL) {
            return false;
        }
        map<ListNode*, bool> visited;
        ListNode* temp = head;

        while (temp != NULL) {
            if (visited[temp] == true) {
                return true;
            }
            visited[temp] = true;
            temp = temp->next;
        }
        return false;
    }
};
 // checking the nodes with hashmap by visited or not technique; 
 we can also use map with find method if the address already visited thus exists a cycle*/