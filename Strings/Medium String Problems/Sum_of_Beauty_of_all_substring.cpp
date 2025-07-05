class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        for(int i = 0 ; i < s.size();i++) {
            vector<int> map(26,0);
            for(int j = i;j<s.size();j++) {
                map[s[j]-'a']++;
                int maxFreq=0,minFreq=INT_MAX;
                for(int f : map) {
                    if(f>0) {
                        maxFreq=max(maxFreq,f);
                        minFreq=min(minFreq,f);
                    }
                }
                sum+=maxFreq-minFreq;
            }
        }
        return sum;
    }
};