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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        ListNode* newhead = head->next;
        while( temp1 !=NULL && temp2!=NULL && temp1->next!=NULL && temp2->next!=NULL) {
            temp1->next = temp2->next;
            temp1 = temp1->next;
            temp2->next = temp1->next;
            temp2 = temp2->next;
        }
        temp1->next = newhead;
        return head;
    }
};