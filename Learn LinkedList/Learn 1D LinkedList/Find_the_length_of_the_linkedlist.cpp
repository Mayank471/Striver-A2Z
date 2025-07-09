/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {

        // Code here
        int len=1;
        Node* curr = head;
        while(curr->next!=NULL) {
            len++;
            curr=curr->next;
        }
        return len;
    }
};