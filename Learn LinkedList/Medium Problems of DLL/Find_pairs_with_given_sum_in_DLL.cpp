// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<pair<int, int>> res;
        Node* l = head;
        Node* r = head;
        while(r->next!=NULL) r = r->next;
        while(l!=r && l->prev!=r) {
            if(l->data+r->data==target) {
                res.push_back({l->data,r->data});
                l = l->next;
                r = r->prev;
            } else if(l->data+r->data<target) {
                l = l->next;
            } else r = r->prev;
        }
        return res;
    }
};