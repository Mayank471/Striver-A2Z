/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void insertStack(stack<int>& s , int temp) {
    if(s.empty()|| s.top()<temp) {
        s.push(temp);
        return;
    }
    int top = s.top();
    s.pop();
    insertStack(s , temp);
    s.push(top);
}
void SortedStack::sort() {
    // Your code here
    if(s.empty())return;
    
    int temp = s.top();
    s.pop();
    sort();
    
    insertStack(s , temp);
}