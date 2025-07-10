/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// Function to insert a new node at given position in doubly linked list.
class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        // code here
        Node* curr = head;
        for(int i = 0; i < pos ; i++ ) {
            if(curr==NULL) return head;
            curr=curr->next;
        }
        Node* temp = new Node(data);
        temp->prev = curr;
        temp->next = curr->next;
        if(curr->next) curr->next->prev = temp;
        curr->next = temp;
        return head;
    }
};