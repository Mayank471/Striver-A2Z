/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        if(head==NULL || head->next==NULL)return 0;
        Node* fast = head;
        Node* slow = head;
        while(fast!=NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                int len=1;
                fast = fast->next;
                while(fast!=slow) {
                    fast=fast->next;
                    len++;
                }
                return len;
            }
        }
        return 0;
    }
};