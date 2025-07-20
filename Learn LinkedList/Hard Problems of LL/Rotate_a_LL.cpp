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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL|| k == 0)return head;
        ListNode* temp = head;
        int len = 1;
        while(temp->next!=NULL) {
            len++;
            temp = temp->next;
        }
        k%=len;
        if(k==0)return head;
        ListNode* start = head;
        for(int i = 0;i<len-k-1;i++) {
            start = start->next;
        }
        ListNode* newhead = start->next;
        temp->next = head;
        start->next=NULL;
        return newhead;
    }
};