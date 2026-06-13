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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		unordered_map<ListNode*,int> mp;

        ListNode* temp = headA;

        while(temp){
            mp[temp]++;
            temp = temp->next;
        }

        ListNode* curr = headB;

        while(curr){
            if(mp[curr] > 0) return curr;
            curr = curr->next;
        }

        return NULL;
	}
};