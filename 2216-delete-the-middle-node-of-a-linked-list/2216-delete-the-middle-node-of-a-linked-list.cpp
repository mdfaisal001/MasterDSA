/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return NULL;
        ListNode* fast = head , *slow = head , *prev = NULL;
        while(fast && fast->next){
            prev = slow;
            slow = slow ->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        return head;
    }
};

/*   if(!head || !head->next) return NULL;
        ListNode* temp = head;
        int count = 0;
        while(temp){
            count++;
            temp = temp->next;
        }
        int high = count;
        int low = 0;
        int mid = low + (high - low) / 2 ;
        int prev = mid - 1;
        
        temp = head;
        for(int i = 0 ; i<prev; i++){
            temp = temp->next;
        }
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
        return head;
    }*/;