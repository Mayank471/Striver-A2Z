// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        stack<string> s;
        int i=0;
        while(i<exp.length()) {
            if((exp[i]>='a'&& exp[i]<='z') || 
               (exp[i]>='A' && exp[i]<='Z'))s.push(string(1,exp[i]));
               else {
                   string t1 = s.top();
                   s.pop();
                   string t2 = s.top();
                   s.pop();
                   string comb = '('+t2+exp[i]+t1+')';
                   s.push(comb);
               }
            i++;
        }
        return s.top();
    }
};