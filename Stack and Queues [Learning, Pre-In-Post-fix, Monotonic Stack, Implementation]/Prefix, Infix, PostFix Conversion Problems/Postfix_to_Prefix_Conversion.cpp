// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        // Write your code here
        stack<string> s;
        int i=0;
        while(i<post_exp.length()) {
            if((post_exp[i]>='a'&& post_exp[i]<='z') || 
               (post_exp[i]>='A' && post_exp[i]<='Z'))s.push(string(1,post_exp[i]));
               else {
                   string t1 = s.top();
                   s.pop();
                   string t2 = s.top();
                   s.pop();
                   string comb = post_exp[i]+t2+t1;
                   s.push(comb);
               }
            i++;
        }
        return s.top();
    }
};