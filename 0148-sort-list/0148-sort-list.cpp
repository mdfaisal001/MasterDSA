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
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        multimap<int,ListNode*> mp;
        ListNode* temp = head; // pointing a pointer to the head;
        while(temp){
            mp.insert({temp->val,temp});
            temp = temp->next;
        }
         auto it = mp.begin();
         ListNode *newHead = new ListNode(it->second->val);
         ListNode* mover = newHead;
        ++it;
       
        for(; it!=mp.end(); it++){
            mover->next = new ListNode(it->second->val);
            mover = mover->next;
        }
        mover->next = nullptr;
     return newHead;
    }
};