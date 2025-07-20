class Solution {
  public:
    Node* merge(Node* l1 , Node* l2) {
        Node* dummynode = new Node(-1);
        Node* temp = dummynode;

        while(l1 != NULL && l2 != NULL) {
            if(l1->data < l2->data) {
                temp->bottom = l1;
                l1 = l1->bottom;
            } else {
                temp->bottom = l2;
                l2 = l2->bottom;
            }
            temp = temp->bottom;
        }

        if (l1) temp->bottom = l1;
        else temp->bottom = l2;

        return dummynode->bottom;
    }
    
    Node* flatten(Node* root) {
        if(root == NULL || root->next == NULL)
            return root;

        root->next = flatten(root->next);
        root = merge(root, root->next);

        return root;
    }
};