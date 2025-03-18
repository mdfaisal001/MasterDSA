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
private:
    void pushToStack(ListNode* head, stack<ListNode*> &st){
        ListNode* temp = head;
        while(temp){
            st.push(temp);
            temp = temp->next;
        }
    }
public:
    bool isPalindrome(ListNode* head) {
      stack<ListNode*> st;
      pushToStack(head,st);
      ListNode* current = head;
      while(!st.empty() && current ){
          ListNode* node = st.top();
          st.pop();
          if(current->val != node->val) return false;
          current = current->next;
      }
      return true;
}
};