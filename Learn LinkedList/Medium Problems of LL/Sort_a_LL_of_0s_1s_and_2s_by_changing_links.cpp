/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        int count0 = 0 , count1 = 0 , count2 = 0;
        Node* temp = head;
        Node* dummy0 = new Node(-1);
        Node* tail0 = dummy0;
        Node* dummy1 = new Node(-1);
        Node* tail1 = dummy1;
        Node* dummy2 = new Node(-1);
        Node* tail2 = dummy2;
        while(temp!=NULL) {
            if(temp->data==0) {
                tail0->next = temp;
                tail0 = tail0->next;
            }
            else if(temp->data==1) {
                tail1->next = temp;
                tail1 = tail1->next;
            }
            else {
                tail2->next = temp;
                tail2 = tail2->next;
            }
            temp = temp->next;
        }
        tail0->next = dummy1->next ? dummy1->next : dummy2->next;
        tail1->next = dummy2->next;
        tail2->next = NULL;
        Node* newhead = dummy0->next;
        delete dummy0;
        delete dummy1;
        delete dummy2;
        return newhead;
    }
};