class Solution {
public:
    int maxDepth(string s) {
        int count = 0,maxcount=0;
        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i]=='(') {
                count++;
                maxcount = max(count,maxcount);
            }
            else if(s[i]==')')count--;
        }
        return maxcount;
    }
};