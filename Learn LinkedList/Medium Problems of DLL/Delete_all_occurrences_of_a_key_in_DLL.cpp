// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        Node* temp = *head_ref;
        while(temp!= NULL) {
            if(temp->data == x) {
                Node* deletedata = temp;
                temp = temp->next;
                if(deletedata == *head_ref){
                    *head_ref = temp;
                    if((*head_ref)->prev) (*head_ref)->prev = NULL;
                    delete deletedata;
                }
                else {
                    if(deletedata->prev)deletedata->prev->next = deletedata->next;
                    if(deletedata->next)deletedata->next->prev = deletedata->prev;
                    delete deletedata;
                }
            } else {
            temp = temp->next;
            }
        }
    }
};