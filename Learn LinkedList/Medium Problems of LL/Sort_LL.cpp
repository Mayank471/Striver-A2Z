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
        if(head==NULL || head->next==NULL) return head;
        ListNode* middle = middleElement(head);
        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode* left = head;
        left = sortList(left);
        right = sortList(right);
        return merge(left , right);
    }
    ListNode* merge(ListNode* left , ListNode* right){
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        while(left!=NULL && right!=NULL) {
            if(left->val<right->val) {
                tail->next = left;
                left = left->next;
                tail = tail->next;
            }
            else {
                tail->next = right;
                right = right->next;
                tail = tail->next;
            }
        }
        while(left!=NULL) {
            tail->next = left;
            left = left->next;
            tail = tail->next;
        }
        while(right!=NULL) {
            tail->next = right;
            right = right->next;
            tail = tail->next;
        }
        return dummy->next; 
    }

    ListNode* middleElement( ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
};