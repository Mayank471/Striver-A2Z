
class Solution {
public:
    void combination( int open , int close , vector<string>& st , string s) {
        if(open==0&&close ==0) {
            st.push_back(s);
            return;
        }
        if(open>0){
            combination(open-1,close,st,s+'(');
        }
        if(close>0 && close > open) combination(open,close-1,st,s+')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        combination(n,n,res,"");
        return res;
    }
};