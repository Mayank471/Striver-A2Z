class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(int i=0; i<num.length(); i++) {
            while(!s.empty() && k>0 && s.top()>num[i]) {
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        while(k>0) {
            s.pop();
            k--;
        }
        if(s.empty())return"0";
        string res="";
        while(!s.empty()) {
            res+=s.top();
            s.pop();
        }
        while(!res.empty() && res.back()=='0')res.pop_back();
        if(res.empty())return "0";
        reverse(res.begin(), res.end());
        return res;
    }
};