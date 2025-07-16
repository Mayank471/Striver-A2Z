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
        int len = 0;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL) {
            len++;
            fast = fast->next;
        }
        fast = slow;
        if(n==len)return head->next;
        for(int i = 0 ; i < len - n - 1;i++) {
            slow = slow->next;
            fast = fast->next;
        }
        fast = fast->next;
        slow->next = fast->next;
        delete fast;
        return head;

    }
};