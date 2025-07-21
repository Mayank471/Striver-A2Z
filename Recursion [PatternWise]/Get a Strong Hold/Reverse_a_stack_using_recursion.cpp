// User function Template for C++

class Solution {
  public:
    void Reverse(stack<int> &st) {
        if(st.empty())return;
        int temp = st.top();
        st.pop();
        Reverse(st);
        insertStack(st , temp);
    }
    
    void insertStack(stack<int>& s , int temp) {
        if(s.empty()) {
            s.push(temp);
            return;
        }
        int top = s.top();
        s.pop();
        insertStack(s , temp);
        s.push(top);
    }
};