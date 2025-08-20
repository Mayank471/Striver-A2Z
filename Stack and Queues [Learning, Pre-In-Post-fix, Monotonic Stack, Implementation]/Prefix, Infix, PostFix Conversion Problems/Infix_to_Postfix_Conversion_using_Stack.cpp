class Solution {
  public:
    int priority(char c) {
        if(c=='+'||c=='-')return 1;
        if(c=='*'||c=='/')return 2;
        if(c=='^')return 3;
        return -1;
    }
    string infixToPostfix(string& s) {
        // code here
        string ans="";
        stack<char> st;
        int i=0;
        while(i<s.length()) {
            if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || 
            (s[i]>='0' && s[i]<='9')){
                ans+=s[i];
            }
            else if(s[i]=='(')st.push(s[i]);
            else if(s[i]==')') {
                while(!st.empty() && st.top()!='(') {
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
            }
            else {
                while(!st.empty() && priority(s[i])<=priority(st.top())) {
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
