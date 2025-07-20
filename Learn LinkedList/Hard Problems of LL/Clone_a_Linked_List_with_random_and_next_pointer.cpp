/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        while( temp != NULL) {
            Node* newnode = new Node(temp->val);
            newnode->next = temp->next;
            temp->next = newnode;
            temp = temp->next->next;
        }
        temp = head;
        while(temp!=NULL) {
            if(temp->random)temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        temp = head;
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        while(temp!=NULL){
            res->next = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            res = res->next;
        }
        return dummyNode->next;
    }
};