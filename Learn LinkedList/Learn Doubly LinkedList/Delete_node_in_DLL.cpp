/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to delete a node at given position.
       Node* deleteNode(Node* head, int x) {
        if (head == NULL) return NULL;
    
        // Case 1: Delete head
        if (x == 1) {
            Node* temp = head;
            head = head->next;
            if (head) head->prev = NULL;
            delete temp;
            return head;
        }
    
        // Case 2: Delete non-head node
        Node* curr = head;
        for (int i = 1; i < x && curr != NULL; i++) {
            curr = curr->next;
        }
    
        if (curr->prev) curr->prev->next = curr->next;
        if (curr->next) curr->next->prev = curr->prev;
    
        delete curr;
    
        return head;
    }
};