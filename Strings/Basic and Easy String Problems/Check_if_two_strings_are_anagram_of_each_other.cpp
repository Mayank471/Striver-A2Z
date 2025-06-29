class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        vector<int> a(26,0) , b(26,0);
        for(int i = 0;i<s.size();i++) {
            a[s[i]-97]++;
            b[t[i]-97]++;
        }
        if(a==b)return true;
        return false;
    }
};