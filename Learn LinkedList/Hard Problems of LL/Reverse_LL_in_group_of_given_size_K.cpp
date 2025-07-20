class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* newhead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }

    ListNode* findkthnode(ListNode* temp, int k) {
        k = k - 1;
        while(k > 0 && temp != NULL) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL) {
            ListNode* knode = findkthnode(temp, k);

            if(knode == NULL) {
                if(prev) prev->next = temp;
                break;
            }

            ListNode* nextnode = knode->next;
            knode->next = NULL;

            ListNode* newhead = reverseList(temp);

            if(temp == head) {
                head = newhead;
            } else {
                prev->next = newhead;
            }
            prev = temp;
            temp = nextnode;
        }
        return head;
    }
};
