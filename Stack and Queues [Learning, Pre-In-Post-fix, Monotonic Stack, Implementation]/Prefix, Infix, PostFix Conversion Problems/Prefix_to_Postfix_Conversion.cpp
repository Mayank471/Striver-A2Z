// User function Template for C++

class Solution {
  public:
    string preToPost(string pre_exp) {
        stack<string> s;
        int i=pre_exp.length()-1;
        while( i>=0) {
            if((pre_exp[i]>='a'&& pre_exp[i]<='z') || 
               (pre_exp[i]>='A' && pre_exp[i]<='Z'))s.push(string(1,pre_exp[i]));
               else {
                   string t1 = s.top();
                   s.pop();
                   string t2 = s.top();
                   s.pop();
                   string comb = t1+t2+pre_exp[i];
                   s.push(comb);
               }
            i--;
        }
        return s.top();
    }
};