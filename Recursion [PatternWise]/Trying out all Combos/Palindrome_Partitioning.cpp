class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        backtrack(0,s,curr,res);
        return res;
    }
private: 
    bool isPalindrome(string st) {
        int l=0, r=st.length()-1;
        while(l<=r) {
            if(st[l]==st[r]){
                l++;r--;
            }
            else return false;
        }
        return true;
    }
    void backtrack( int start, string s, vector<string>& curr, vector<vector<string>>& res ){
        if(start == s.size()){
            res.push_back(curr);
            return;
        }
        for(int i = start; i<s.size(); i++) {
            if(isPalindrome(s.substr(start, i-start+1))) {
                curr.push_back(s.substr(start,i-start+1));
                backtrack(i+1,s,curr,res);
                curr.pop_back();
            }
        }
    }
};