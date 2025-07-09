/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        if(head == NULL ) {
            head = new Node(x);
            return head;
        }
        Node* curr = head;
        while(curr->next!=NULL)curr=curr->next;
        curr->next = new Node(x);
        return head;
    }
};