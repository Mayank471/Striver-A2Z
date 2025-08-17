class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        // code here
        StackNode* temp = new StackNode(x);
        temp->next=top;
        top=temp;
        return;
    }

    int pop() {
        if(top==NULL) return -1;
        int x=top->data;
        StackNode* temp=top;
        top=top->next;
        delete temp;
        return x;
        // code here
    }

    MyStack() { top = NULL; }
};