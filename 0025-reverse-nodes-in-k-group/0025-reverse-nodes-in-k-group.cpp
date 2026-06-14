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
    ListNode* rev(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* findkthGroup(ListNode* temp, int k) {
        while (temp && --k) {
            temp = temp->next;
        }
        return temp;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp) {
            ListNode* kth = findkthGroup(temp, k);
            if (kth == NULL) {
                if (prev) {
                    prev->next = temp;
                }
                break;
            }
            ListNode* next = kth->next; // storing the next head of the next group
            kth->next = NULL; // make the current groups tail to null

            ListNode* nhead = rev(temp); 
            if (temp == head) {  //if it was first group , the head and the temp will be equal
                head = nhead; 
            } else {
                prev->next = nhead; // else map the old group
            }

            prev = temp; //store the last node;
            temp = next; // move the temp to new group
        }
        return head;
    }
};