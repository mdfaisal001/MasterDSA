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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* mover1 = l1;
       ListNode* mover2 = l2;
       int carry = 0;
       ListNode* DummyNode = new ListNode(-1);
       ListNode* curr = DummyNode;
       while(mover1 || mover2){
            int sum = carry;
             if(mover1) sum+=mover1->val;
             if(mover2) sum+=mover2->val;
             ListNode* newNode = new ListNode(sum % 10); // extracting last dig or balance;
             carry = sum / 10 ; //taking first digit as carry ; 
             curr->next = newNode;
             curr = curr->next;
             if(mover1) mover1 = mover1->next;
             if(mover2) mover2 = mover2->next;
       }
       if(carry){
            ListNode* carryNode = new ListNode(carry);
            curr->next = carryNode;
       }
       return DummyNode->next;
     }
};

/*class Solution {
private:
    string makeInteger(ListNode* head){
        ListNode* temp = head;
        string sum = "";
        while(temp){
            sum += to_string(temp->val);
            temp = temp->next;
        }
        reverse(sum.begin(),sum.end());
        return sum;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string str1 = makeInteger(l1);
        string str2 = makeInteger(l2);
        long long value1 = stoll(str1);
        long long value2 = stoll(str2);
        long long total = value1 + value2;
        string result = to_string(total);
        reverse(result.begin(),result.end());
        long long first = result[0] -'0';
        ListNode* newHead = new ListNode(first);
        ListNode* temp = newHead;
        for(int i=1; i<result.size(); i++){
            long long newNodes = result[i]-'0';
            temp->next = new ListNode(newNodes);
            temp = temp->next;
        }
        temp->next = nullptr;
        return newHead;
     }
};*/