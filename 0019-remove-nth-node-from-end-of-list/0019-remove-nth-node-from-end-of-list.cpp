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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        if(n == count){
            ListNode *delHead = head;
            head = head->next;
            delete delHead;
            return head;
        }

        int result = count - n;
        temp = head;
        while(--result > 0){
            temp = temp->next;
        }
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
        return head;
    }

};
/*ListNode* temp = head ,*mover = head, *prev = NULL;
        // reversing the pointers
        while(temp){
            temp = temp->next;
            mover->next = prev;
            prev = mover;
            mover = temp;
        }
        ListNode* current = prev;
        while(current){
            count++;
            if(count == n){
                current->val = current->next->val;
                ListNode* travel  = current->next;
                travel = travel->next;
                current = travel;
            }
            current = current->next;
        }
        ListNode  *reverseTemp = prev , *reverseMover = prev, *currHead = NULL;
        while(prev){
            reverseTemp = reverseTemp->next;
            reverseMover->next = currHead;
            currHead = reverseMover;
            reverseMover = reverseTemp;
        }
        return currHead; */