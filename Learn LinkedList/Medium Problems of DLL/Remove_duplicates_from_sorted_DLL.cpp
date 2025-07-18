/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        Node* temp = head;
        while( temp != NULL && temp->next!=NULL) {
            if(temp->data == temp->next->data) {
                Node* todelete = temp->next;
                temp->next = temp->next->next;
                if(temp->next)temp->next->prev = temp;
                delete todelete;
            }
            else temp = temp->next;
        }
        return head;
    }
};