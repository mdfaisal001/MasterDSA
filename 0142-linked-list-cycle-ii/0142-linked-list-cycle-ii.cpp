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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(head == NULL) return NULL;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
           if(fast == slow) {
              slow = head; // making one pointer to starting or reset simply
              while(fast != slow){
                slow = slow->next;
                fast = fast->next;
              }
              return fast;
           }
        }
       return NULL;
    }
};

/*   unordered_map<ListNode* , int>mp;
        ListNode* temp = head;
        if(head == NULL) return NULL;
        while(temp){
            if(mp.find(temp)!=mp.end()){
                return temp;
            }
            mp[temp] = temp->val;
            temp = temp->next;
        }
        return NULL;
    }
}; for map we need two parameters; O(1),O(n);

// with sets 
unordered_set<ListNode*>mp; // storing the nodes that means memory;
        ListNode* temp = head;
        if(head == NULL) return NULL; //edge case;

        while(temp){
            if(mp.find(temp)!=mp.end()){
                return temp;
            }
            mp.insert(temp); // inserting the memory locations to the set;
            temp = temp->next;
        }
        return NULL;
    }
// */