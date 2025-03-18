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
    bool isPalindrome(ListNode* head) {
     // find the  middle 
     ListNode* slow = head , *fast = head , *prev=NULL;
     while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
     }
     // reversing the second half;
     while(slow){
        ListNode* temp = slow;
        temp = temp->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
     }
     // comparing first half and second half
     ListNode* left = head , *right = prev;
     while(right){
        if(left->val != right->val) return false;
        left = left->next;
        right = right->next;
     }
    return true;
}
};  

/* 
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
      return true;  // o(n) O(n); */